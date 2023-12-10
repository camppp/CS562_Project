// Resource.h
class Resource {
public:
    virtual ~Resource() = default;
    virtual void build() = 0;
    virtual void use() = 0;
};

// Initializer.h
class Initializer {
public:
    virtual ~Initializer() = default;
    virtual void initialize() = 0;
    virtual void build() = 0;
    virtual void use() = 0;
};

// ResourceManager.h
class ResourceManager {
public:
    ResourceManager();
    ~ResourceManager();
    void addResource(Resource* resource);
    void removeResource(Resource* resource);
    void buildResource(Resource* resource);
    void useResource(Resource* resource);
    void initialize();
private:
    std::vector<Resource*> resources;
};

// ProcgenInitializer.h
class ProcgenInitializer : public Initializer {
public:
    ProcgenInitializer();
    ~ProcgenInitializer();
    void initialize();
    void build();
    void use();
private:
    Resource* em;
    Resource* procgen;
    Resource* engtypes;
};

// ProcgenInitializer.cpp
ProcgenInitializer::ProcgenInitializer() {
    em = new Resource("em");
    procgen = new Resource("procgen");
    engtypes = new Resource("engtypes");
}

ProcgenInitializer::~ProcgenInitializer() {
    delete em;
    delete procgen;
    delete engtypes;
}

void ProcgenInitializer::initialize() {
    // Initialize the resources
    em->build();
    procgen->build();
    engtypes->build();
}

void ProcgenInitializer::build() {
    // Build the resources
    em->build();
    procgen->build();
    engtypes->build();
}

void ProcgenInitializer::use() {
    // Use the resources
    em->use();
    procgen->use();
    engtypes->use();
}

// ResourceManager.cpp
ResourceManager::ResourceManager() {
    // Initialize the resources
    em = new Resource("em");
    procgen = new Resource("procgen");
    engtypes = new Resource("engtypes");
}

ResourceManager::~ResourceManager() {
    delete em;
    delete procgen;
    delete engtypes;
}

void ResourceManager::addResource(Resource* resource) {
    resources.push_back(resource);
}

void ResourceManager::removeResource(Resource* resource) {
    resources.erase(std::remove(resources.begin(), resources.end(), resource), resources.end());
}

void ResourceManager::buildResource(Resource* resource) {
    resource->build();
}

void ResourceManager::useResource(Resource* resource) {
    resource->use();
}

void ResourceManager::initialize() {
    // Initialize the resources
    for (auto resource : resources) {
        resource->build();
    }
}
