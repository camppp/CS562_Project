// Base classes
class Component {
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void handleEvent(Event& event) = 0;
};

class Timer {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void setInterval(int interval) = 0;
};

// Core class
class Core {
public:
    Core();
    ~Core();

    UndoManager& getUndoManager();

private:
    UndoManager undoManager;
};

// UndoManager class
class UndoManager {
public:
    UndoManager();
    ~UndoManager();

    void addUndoAction(const std::string& action);
    void undo();
    void redo();

private:
    std::vector<std::string> undoActions;
    int currentUndoAction;
};

// GUIComponent class
class GUIComponent : public Component, public Timer {
public:
    GUIComponent(const std::string& name, int x, int y, int width, int height);
    ~GUIComponent();

    void draw();
    void update();
    void handleEvent(Event& event);

    void startTimer();
    void stopTimer();
    void setInterval(int interval);

private:
    std::string name;
    int x, y, width, height;
    bool isTimerRunning;
    int timerInterval;
};
