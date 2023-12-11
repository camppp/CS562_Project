class Object {
public:
    Object() {
        std::cout << "Object constructor called" << std::endl;
    }
};

class Component : public Object {
public:
    Component() : Object() {
        std::cout << "Component constructor called" << std::endl;
    }
};

class Behaviour : public Component {
public:
    Behaviour() : Component() {
        std::cout << "Behaviour constructor called" << std::endl;
    }
};

class MonoBehaviour : public Behaviour {
public:
    MonoBehaviour() : Behaviour() {
        std::cout << "MonoBehaviour constructor called" << std::endl;
    }
};
