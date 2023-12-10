#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

class IOServiceManager {
public:
    IOServiceManager(size_t numThreads) : m_ioServices(numThreads), m_works(numThreads) {
        for (size_t i = 0; i < numThreads; ++i) {
            m_works.push_back(new boost::asio::io_service::work(m_ioServices[i]));
            m_threads.create_thread(boost::bind(&boost::asio::io_service::run, &m_ioServices[i]));
        }
    }

    void submitTask(const std::function<void()>& task) {
        size_t index = m_nextIoServiceIndex.fetch_add(1) % m_ioServices.size();
        m_ioServices[index].post(task);
    }

    void stopAllServices() {
        for (size_t i = 0; i < m_ioServices.size(); ++i) {
            m_works[i].reset();  // Allow the work associated with the I/O service to complete
            m_ioServices[i].stop();  // Stop the I/O service
        }
        m_threads.join_all();  // Wait for all threads to complete
    }

private:
    boost::ptr_vector<boost::asio::io_service> m_ioServices;
    boost::ptr_vector<boost::asio::io_service::work> m_works;
    boost::thread_group m_threads;
    boost::atomic<size_t> m_nextIoServiceIndex{0};
};

// Example usage
int main() {
    IOServiceManager manager(4);  // Create a manager with 4 I/O service instances

    // Submit tasks to the I/O services
    for (int i = 0; i < 10; ++i) {
        manager.submitTask([i](){
            std::cout << "Task " << i << " executed by thread " << boost::this_thread::get_id() << std::endl;
        });
    }

    // Stop all I/O services gracefully
    manager.stopAllServices();

    return 0;
}
