#include <iostream>
#include <cstdint>
#include <ctime>

class Role {
    // Class definition for Role
};

class PlayerProgress {
private:
    Role* m_role;
    short m_zhanshendian_pass_level;
    short m_yesterday_pass_level;
    unsigned int m_fetch_day_reward_timestamp;

public:
    PlayerProgress(Role* role) {
        m_role = role;
        m_zhanshendian_pass_level = 0;
        m_yesterday_pass_level = 0;
        m_fetch_day_reward_timestamp = 0;
    }

    ~PlayerProgress() {
        delete m_role;
    }

    Role* getRole() {
        return m_role;
    }

    short getZhanshendianPassLevel() {
        return m_zhanshendian_pass_level;
    }

    short getYesterdayPassLevel() {
        return m_yesterday_pass_level;
    }

    unsigned int getFetchDayRewardTimestamp() {
        return m_fetch_day_reward_timestamp;
    }

    void setZhanshendianPassLevel(short level) {
        if (level < 0 || level > 100) {
            std::cerr << "Invalid level: " << level << std::endl;
            return;
        }
        m_zhanshendian_pass_level = level;
    }

    void setYesterdayPassLevel(short level) {
        if (level < 0 || level > 100) {
            std::cerr << "Invalid level: " << level << std::endl;
            return;
        }
        m_yesterday_pass_level = level;
    }

    void fetchDailyReward() {
        m_fetch_day_reward_timestamp = std::time(0);
    }
};
