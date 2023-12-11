bool isColliding(const Entity& entity1, const Entity& entity2) {
    // Check if the x-coordinates of the two entities overlap
    if (entity1.x + entity1.width <= entity2.x || entity2.x + entity2.width <= entity1.x) {
        return false;
    }

    // Check if the y-coordinates of the two entities overlap
    if (entity1.y + entity1.height <= entity2.y || entity2.y + entity2.height <= entity1.y) {
        return false;
    }

    // If the x- and y-coordinates of the two entities overlap, then they are colliding
    return true;
}
