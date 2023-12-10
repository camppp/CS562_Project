#include <memory>
#include <mysql_driver.h>
#include <mysql_connection.h>

class MysqlConnection {
private:
    std::shared_ptr<sql::Connection> m_connection;

public:
    // Returns the connection.
    std::shared_ptr<sql::Connection> getConnection() {
        if (!m_connection) {
            sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
            m_connection = std::shared_ptr<sql::Connection>(driver->connect("hostname", "username", "password"));
            m_connection->setSchema("test_database");
        }
        return m_connection;
    }
};
