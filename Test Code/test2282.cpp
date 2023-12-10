#include <iostream>
#include <ctime>

class Role {
    // Class definition for Role
};

class PlayerProgress {
private:
    Role *m_role;
    short m_zhanshendian_pass_level;
    short m_yesterday_pass_level;
    unsigned int m_fetch_day_reward_timestamp;

public:
    // Constructor
    PlayerProgress(Role *role, short zhanshendian_pass_level, short yesterday_pass_level, unsigned int fetch_day_reward_timestamp)
        : m_role(role), m_zhanshendian_pass_level(zhanshendian_pass_level), m_yesterday_pass_level(yesterday_pass_level), m_fetch_day_reward_timestamp(fetch_day_reward_timestamp) {}

    // Destructor
    ~PlayerProgress() {
        delete m_role; // Release memory for Role object
    }

    // Getter and setter methods for m_role
    Role* getRole() const {
        return m_role;
    }

    void setRole(Role *role) {
        m_role = role;
    }

    // Getter and setter methods for m_zhanshendian_pass_level
    short getZhanshendianPassLevel() const {
        return m_zhanshendian_pass_level;
    }

    void setZhanshendianPassLevel(short level) {
        if (level >= 0 && level <= 100) {
            m_zhanshendian_pass_level = level;
        } else {
            std::cerr << "Error: Invalid level. Level should be within the range 0-100." << std::endl;
        }
    }

    // Getter and setter methods for m_yesterday_pass_level
    short getYesterdayPassLevel() const {
        return m_yesterday_pass_level;
    }

    void setYesterdayPassLevel(short level) {
        if (level >= 0 && level <= 100) {
            m_yesterday_pass_level = level;
        } else {
            std::cerr << "Error: Invalid level. Level should be within the range 0-100." << std::endl;
        }
    }

    // Getter and setter methods for m_fetch_day_reward_timestamp
    unsigned int getFetchDayRewardTimestamp() const {
        return m_fetch_day_reward_timestamp;
    }

    void setFetchDayRewardTimestamp(unsigned int timestamp) {
        m_fetch_day_reward_timestamp = timestamp;
    }

    // Method to fetch daily reward
    void fetchDailyReward() {
        m_fetch_day_reward_timestamp = static_cast<unsigned int>(std::time(0));
    }
};

int main() {
    // Example usage
    Role *role = new Role(); // Create a Role object
    PlayerProgress player(role, 50, 40, 1626841200); // Create a PlayerProgress object

    player.fetchDailyReward(); // Fetch daily reward and update timestamp

    return 0;
}
