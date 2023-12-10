#include <map>
#include <pthread.h>
#include <unistd.h>
#include <vector>

// Definition of the CmdTable class
class CmdTable {
public:
  void reserve(size_t n) {
    commands_.reserve(n);
  }

  void InitCmdTable() {
    // Initialize the command table
    // ...
  }

private:
  std::vector<Command> commands_;  // Assuming Command is a defined type
};

// Definition of the PikaCmdTableManager class
class PikaCmdTableManager {
public:
  void InsertCurrentThreadCmdTable() {
    pid_t tid = gettid();
    CmdTable* cmds = new CmdTable();
    cmds->reserve(300);
    cmds->InitCmdTable();
    pthread_mutex_lock(&map_mutex_);
    thread_table_map_[tid] = cmds;
    pthread_mutex_unlock(&map_mutex_);
  }

  // Other member functions for accessing/manipulating command tables

private:
  std::map<pid_t, CmdTable*> thread_table_map_;
  pthread_mutex_t map_mutex_ = PTHREAD_MUTEX_INITIALIZER;
};
