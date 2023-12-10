class Tree {
private:
    static int objectCount;

public:
    Tree() {
        objectCount++;
    }

    static int getObjectCount() {
        return objectCount;
    }
};
