bool hasCircularDependency(SharedPtr<CircularDependencyObject> obj) {
    // Create a set to keep track of the objects that have been visited
    std::set<SharedPtr<CircularDependencyObject>> visited;

    // Create a queue to store the objects to be visited
    std::queue<SharedPtr<CircularDependencyObject>> queue;

    // Add the starting object to the queue
    queue.push(obj);

    // Loop until the queue is empty
    while (!queue.empty()) {
        // Get the next object from the queue
        SharedPtr<CircularDependencyObject> current = queue.front();
        queue.pop();

        // If the current object has already been visited, return true
        if (visited.find(current) != visited.end()) {
            return true;
        }

        // Add the current object to the visited set
        visited.insert(current);

        // If the current object has a reference to another object, add it to the queue
        if (current->getOther()) {
            queue.push(current->getOther());
        }
    }

    // If the queue is empty, there are no circular dependencies
    return false;
}
