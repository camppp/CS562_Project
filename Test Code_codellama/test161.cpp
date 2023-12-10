#include <iostream>
#include <pqxx/notification_receiver.h>

class NetworkNotificationReceiver : public pqxx::notification_receiver
{
public:
    NetworkNotificationReceiver(PostgreSQL* postgresql, pqxx::connection& connection, const std::string& channel)
        : pqxx::notification_receiver(connection, channel)
        , m_postgresql(postgresql)
    {
    }

    void operator()(const std::string& payload, int backend_pid) override
    {
        std::cout << "Received notification: " << payload << " from backend process ID: " << backend_pid << std::endl;
    }

private:
    PostgreSQL* m_postgresql;
};
