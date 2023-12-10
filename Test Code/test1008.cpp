class SceneNode {
public:
    SceneNode(const std::string& name) : name(name) {}

    void addChild(SceneNode* child) {
        children.push_back(child);
        child->parent = this;
    }

    void removeChild(SceneNode* child) {
        children.erase(std::remove(children.begin(), children.end(), child), children.end());
        child->parent = nullptr;
    }

    void traverse(std::function<void(SceneNode*)> callback) {
        callback(this);
        for (auto& child : children) {
            child->traverse(callback);
        }
    }

private:
    std::string name;
    std::vector<SceneNode*> children;
    SceneNode* parent = nullptr;
};
