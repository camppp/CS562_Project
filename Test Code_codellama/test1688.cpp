#include <iostream>
#include <unordered_map>

class Screen {
public:
    Screen(int id) : id(id) {}
    virtual void display() = 0;
    int getId() const { return id; }
private:
    int id;
};

class App {
public:
    void addScreen(Screen* screen) {
        screens[screen->getId()] = screen;
    }

    void removeScreen(int id) {
        screens.erase(id);
    }

    void showScreen(int id) {
        auto it = screens.find(id);
        if (it != screens.end()) {
            it->second->display();
        } else {
            std::cout << "Screen not found" << std::endl;
        }
    }

private:
    std::unordered_map<int, Screen*> screens;
};

int main() {
    App app;

    // Add a screen
    Screen* screen1 = new Screen(1);
    app.addScreen(screen1);

    // Add another screen
    Screen* screen2 = new Screen(2);
    app.addScreen(screen2);

    // Remove a screen
    app.removeScreen(1);

    // Show a screen
    app.showScreen(2);

    return 0;
}
