// Entity.h
class Entity {
public:
    virtual string HumanName() = 0;
    virtual string InternalName() = 0;
};

// Entity.cpp
class ConcreteEntity : public Entity {
public:
    string HumanName() {
        return "Concrete Entity";
    }

    string InternalName() {
        return "ConcreteEntity";
    }
};

// main.cpp
int main() {
    Entity* entity = new ConcreteEntity();
    cout << "Human name: " << entity->HumanName() << endl;
    cout << "Internal name: " << entity->InternalName() << endl;
    return 0;
}
