void calculateRepellingForce(unsigned int win_width, unsigned int win_height, sf::Vector2f position, sf::Vector2f& repelling_force, float dist_threshold, float epsilon) {
    if (position.x < dist_threshold) {
        repelling_force.x += dist_threshold / position.x;
    } else if (position.x > win_width - dist_threshold) {
        int delta = position.x - win_width;
        repelling_force.x += dist_threshold / (delta + epsilon);
    } else if (position.y < dist_threshold) {
        repelling_force.y += dist_threshold / position.y;
    } else if (position.y > win_height - dist_threshold) {
        int delta = position.y - win_height;
        repelling_force.y += dist_threshold / (delta + epsilon);
    }
}
