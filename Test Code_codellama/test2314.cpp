#include <msmq.h>

void EnsureQueueExists(const std::string& queuePath)
{
    // Check if the queue already exists
    if (MessageQueue::Exists(queuePath))
    {
        // Queue already exists, nothing to do
        return;
    }

    // Queue does not exist, create it
    try
    {
        // Create the queue
        MessageQueue::Create(queuePath);
    }
    catch (const std::exception& e)
    {
        // Handle any exceptions that may occur during queue creation
        std::cerr << "Error creating queue: " << e.what() << std::endl;
    }
}
