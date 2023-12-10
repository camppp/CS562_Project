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
        auto it = screens.find(id);
        if (it != screens.end()) {
            delete it->second;
            screens.erase(it);
        }
    }

    void showScreen(int id) {
        auto it = screens.find(id);
        if (it != screens.end()) {
            it->second->display();
        } else {
            std::cout << "Screen not found" << std::endl;
        }
    }

    ~App() {
        for (auto& pair : screens) {
            delete pair.second;
        }
    }

private:
    std::unordered_map<int, Screen*> screens;
};

class ExampleScreen : public Screen {
public:
    ExampleScreen(int id, const std::string& content) : Screen(id), content(content) {}
    void display() override {
        std::cout << "Screen " << getId() << ": " << content << std::endl;
    }
private:
    std::string content;
};

int main(){
    App app;
    app.addScreen(new ExampleScreen(1, "Welcome to the app"));
    app.addScreen(new ExampleScreen(2, "Settings screen"));
    app.showScreen(1);
    app.showScreen(2);
    app.removeScreen(1);
    app.showScreen(1);
    return 0;
}
