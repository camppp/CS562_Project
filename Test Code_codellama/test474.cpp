#include <iostream>
#include <mutex>
#include <thread>
#include <unordered_map>

namespace sp
{
    namespace video
    {
        class SharedRenderContext
        {
        public:
            SharedRenderContext() {}

            void createResource(const std::string& resourceName)
            {
                std::lock_guard<std::mutex> lock(resourceMutex);
                std::cout << "Resource '" << resourceName << "' created by thread " << std::this_thread::get_id() << std::endl;
                resources[resourceName] = std::this_thread::get_id();
            }

            void destroyResource(const std::string& resourceName)
            {
                std::lock_guard<std::mutex> lock(resourceMutex);
                auto it = resources.find(resourceName);
                if (it != resources.end())
                {
                    std::cout << "Resource '" << resourceName << "' destroyed by thread " << it->second << std::endl;
                    resources.erase(it);
                }
            }

            void createResource(const std::string& resourceName, const std::thread::id& threadId)
            {
                std::lock_guard<std::mutex> lock(resourceMutex);
                std::cout << "Resource '" << resourceName << "' created by thread " << threadId << std::endl;
                resources[resourceName] = threadId;
            }

            void destroyResource(const std::string& resourceName, const std::thread::id& threadId)
            {
                std::lock_guard<std::mutex> lock(resourceMutex);
                auto it = resources.find(resourceName);
                if (it != resources.end() && it->second == threadId)
                {
                    std::cout << "Resource '" << resourceName << "' destroyed by thread " << threadId << std::endl;
                    resources.erase(it);
                }
            }

        private:
            std::unordered_map<std::string, std::thread::id> resources;
            std::mutex resourceMutex;
        };
    } // namespace video
} // namespace sp
