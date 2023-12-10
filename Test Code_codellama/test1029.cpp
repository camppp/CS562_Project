#include <unordered_map>

// Define a hash table to store the command-executor function mappings
std::unordered_map<int, void (*)()> command_executor_map;

// Define a macro to define the association between a command type and its executor function
#define DEFINE_EXECUTE_CMD(cmd_type, executor_func) \
  command_executor_map[cmd_type] = executor_func;

// Function to populate the data structure with the command-executor function mappings
void populate_command_executor_map() {
  // Iterate over the list of command types and executor functions
  for (int cmd_type : command_types) {
    // Add the mapping to the hash table
    command_executor_map[cmd_type] = executor_func;
  }
}

// Function to retrieve the executor function based on a given command type
void (*get_executor_func(int cmd_type))() {
  // Use the hash table to retrieve the corresponding executor function
  auto it = command_executor_map.find(cmd_type);
  if (it != command_executor_map.end()) {
    return it->second;
  } else {
    // Return a default executor function if the command type is not found in the hash table
    return default_executor_func;
  }
}
