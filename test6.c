#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_HISTORY_LENGTH 100

// Structure to store command history
struct command_history {
    char *command;
    struct command_history *next;
};

// Function to add a command to the history
void add_command(char *command) {
    // Create a new history entry
    struct command_history *new_entry = malloc(sizeof(struct command_history));
    new_entry->command = malloc(strlen(command) + 1);
    strcpy(new_entry->command, command);
    new_entry->next = NULL;

    // Add the new entry to the end of the history list
    struct command_history *current = history;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_entry;
}

// Function to print the command history
void print_history() {
    struct command_history *current = history;
    while (current != NULL) {
        printf("%s\n", current->command);
        current = current->next;
    }
}

// Main function
int main() {
    // Initialize the command history
    history = NULL;

    // Read commands from the user and execute them
    char command[MAX_COMMAND_LENGTH];
    while (1) {
        printf("$ ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        if (strcmp(command, "exit\n") == 0) {
            break;
        }
        add_command(command);
        system(command);
    }

    // Print the command history
    print_history();

    
    return 0;
}
