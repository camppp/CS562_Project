void calculateRepellingForce(unsigned int win_width, unsigned int win_height, sf::Vector2f position, sf::Vector2f& repelling_force, float dist_threshold, float epsilon)
{
    // Calculate the distance of the object from the window edges
    float dist_left = position.x - win_width / 2.0f;
    float dist_right = win_width / 2.0f - position.x;
    float dist_top = position.y - win_height / 2.0f;
    float dist_bottom = win_height / 2.0f - position.y;

    // Calculate the repelling force based on the distance from the window edges
    if (dist_left < dist_threshold)
    {
        repelling_force.x += (dist_left - dist_threshold) / epsilon;
    }
    if (dist_right < dist_threshold)
    {
        repelling_force.x -= (dist_right - dist_threshold) / epsilon;
    }
    if (dist_top < dist_threshold)
    {
        repelling_force.y += (dist_top - dist_threshold) / epsilon;
    }
    if (dist_bottom < dist_threshold)
    {
        repelling_force.y -= (dist_bottom - dist_threshold) / epsilon;
    }
}
