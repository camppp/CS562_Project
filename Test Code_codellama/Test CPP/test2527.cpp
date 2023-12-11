#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define the game world
struct Room {
    string name;
    vector<string> exits;
    vector<string> creatures;
};

// Define the player's actions
enum Action {
    MOVE_NORTH,
    MOVE_SOUTH,
    MOVE_EAST,
    MOVE_WEST,
    SHOOT_ARROW
};

// Define the game's state
struct GameState {
    vector<Room> rooms;
    vector<string> creatures;
    vector<string> arrows;
    int currentRoom;
    int currentCreature;
    int currentArrow;
};

// Define the game's events
enum Event {
    PLAYER_MOVED,
    PLAYER_SHOT_ARROW,
    CREATURE_SPAWNED,
    CREATURE_KILLED
};

// Define the game's observers
struct Observer {
    virtual void notify(Event event) = 0;
};

// Define the game's logic
void handleAction(GameState& state, Action action) {
    switch (action) {
        case MOVE_NORTH:
            state.currentRoom = state.rooms[state.currentRoom].exits[0];
            break;
        case MOVE_SOUTH:
            state.currentRoom = state.rooms[state.currentRoom].exits[1];
            break;
        case MOVE_EAST:
            state.currentRoom = state.rooms[state.currentRoom].exits[2];
            break;
        case MOVE_WEST:
            state.currentRoom = state.rooms[state.currentRoom].exits[3];
            break;
        case SHOOT_ARROW:
            state.arrows.push_back(state.currentCreature);
            state.currentCreature = -1;
            break;
    }
}

void handleEvent(GameState& state, Event event) {
    switch (event) {
        case PLAYER_MOVED:
            // Notify observers of the player's movement
            break;
        case PLAYER_SHOT_ARROW:
            // Notify observers of the player's arrow shot
            break;
        case CREATURE_SPAWNED:
            // Notify observers of a creature spawning
            break;
        case CREATURE_KILLED:
            // Notify observers of a creature being killed
            break;
    }
}

// Define the game's main loop
void gameLoop(GameState& state) {
    while (true) {
        // Handle player actions
        handleAction(state, getPlayerAction());

        // Handle game events
        handleEvent(state, getGameEvent());

        // Update the game state
        updateGameState(state);
    }
}

int main() {
    // Initialize the game state
    GameState state;

    // Set up the game world
    state.rooms.push_back(Room("Start", {"North", "South", "East", "West"}));
    state.rooms.push_back(Room("North", {"South", "East", "West"}));
    state.rooms.push_back(Room("South", {"North", "East", "West"}));
    state.rooms.push_back(Room("East", {"North", "South", "West"}));
    state.rooms.push_back(Room("West", {"North", "South", "East"}));

    // Set up the player's starting position
    state.currentRoom = 0;

    // Set up the game's observers
    Observer observer1;
    Observer observer2;

    // Start the game loop
    gameLoop(state);

    return 0;
}
