#include <msmq.h>
#include <msmqobj.h>

void EnsureQueueExists(String^ path)
{
    try
    {
        if (!MessageQueue::Exists(path))
        {
            MessageQueue^ queue = MessageQueue::Create(path);
            // Optionally, set queue properties or permissions here
        }
    }
    catch (MessageQueueException^ e)
    {
        // Handle any specific message queue exceptions here
        // For example: log the error, retry, or throw a custom exception
    }
    catch (Exception^ e)
    {
        // Handle any other general exceptions here
        // For example: log the error, retry, or throw a custom exception
    }
}
