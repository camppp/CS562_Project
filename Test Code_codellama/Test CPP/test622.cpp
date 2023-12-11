#include <iostream>
#include <unordered_map>
#include <mutex>
#include <thread>

// Definition of the CmdTable class
class CmdTable {
public:
    CmdTable(int num_reserved_slots) {
        // Initialize the command table with the given number of reserved slots
        for (int i = 0; i < num_reserved_slots; i++) {
            slots_.push_back(nullptr);
        }
    }

    // Reserve a slot in the command table
    void reserve(int slot_num) {
        // Check if the slot is already reserved
        if (slots_[slot_num] != nullptr) {
            throw std::runtime_error("Slot already reserved");
        }

        // Reserve the slot
        slots_[slot_num] = new CmdSlot();
    }

    // Initialize the command table
    void InitCmdTable() {
        // Initialize the command table with the given number of reserved slots
        for (int i = 0; i < num_reserved_slots_; i++) {
            slots_[i] = new CmdSlot();
        }
    }

private:
    // The number of reserved slots in the command table
    int num_reserved_slots_;

    // The slots in the command table
    std::vector<CmdSlot*> slots_;
};

// Definition of the PikaCmdTableManager class
class PikaCmdTableManager {
public:
    // Insert the current thread's command table into the map
    void InsertCurrentThreadCmdTable() {
        // Get the current thread ID
        std::thread::id thread_id = std::this_thread::get_id();

        // Create a new command table for the current thread
        CmdTable* cmd_table = new CmdTable(300);

        // Initialize the command table
        cmd_table->InitCmdTable();

        // Insert the thread ID and the command table into the map
        std::lock_guard<std::mutex> lock(mutex_);
        thread_table_map_[thread_id] = cmd_table;
    }

private:
    // The map of thread IDs to command tables
    std::unordered_map<std::thread::id, CmdTable*> thread_table_map_;

    // The mutex to protect the map
    std::mutex mutex_;
};
