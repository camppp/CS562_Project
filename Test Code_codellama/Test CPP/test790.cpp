class Object {
public:
    // Define the Object class here
    Object() = default;
    Object(const Object&) = default;
    Object& operator=(const Object&) = default;

    virtual ~Object() = default;

    virtual bool operator==(const Object& other) const = 0;
    virtual bool operator!=(const Object& other) const = 0;

    virtual std::string toString() const = 0;
};
