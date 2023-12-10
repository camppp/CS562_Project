bool isColliding(const Entity& entity1, const Entity& entity2) {
    int left1 = entity1.x;
    int right1 = entity1.x + entity1.width;
    int top1 = entity1.y;
    int bottom1 = entity1.y + entity1.height;

    int left2 = entity2.x;
    int right2 = entity2.x + entity2.width;
    int top2 = entity2.y;
    int bottom2 = entity2.y + entity2.height;

    // Check for non-overlapping conditions
    if (left1 >= right2 || right1 <= left2 || top1 >= bottom2 || bottom1 <= top2) {
        return false;
    }

    // If none of the non-overlapping conditions are met, the bounding boxes overlap
    return true;
}
