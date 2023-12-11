void _follow_path(float dt) {
    // Check if the path following system is active
    if (!system.mover.active) {
        return;
    }

    // Update the position and rotation of the entity based on the elapsed time
    if (system.update_position) {
        // Calculate the position of the entity at the current time
        float current_time = system.mover.state;
        float next_time = current_time + dt;
        int next_waypoint = 0;
        while (next_waypoint < system.mover.num_points && system.mover.steps[next_waypoint].time < next_time) {
            next_waypoint++;
        }
        if (next_waypoint < system.mover.num_points) {
            // Interpolate the position of the entity between the current waypoint and the next waypoint
            float t = (next_time - system.mover.steps[next_waypoint - 1].time) / (system.mover.steps[next_waypoint].time - system.mover.steps[next_waypoint - 1].time);
            system.position = system.mover.steps[next_waypoint - 1].position + t * (system.mover.steps[next_waypoint].position - system.mover.steps[next_waypoint - 1].position);
        } else {
            // The entity has reached the end of the path, so update the position and deactivate the path following system
            system.position = system.mover.steps[system.mover.num_points - 1].position;
            system.mover.active = false;
        }
    }

    if (system.update_rotation) {
        // Calculate the rotation of the entity at the current time
        float current_time = system.mover.state;
        float next_time = current_time + dt;
        int next_waypoint = 0;
        while (next_waypoint < system.mover.num_points && system.mover.steps[next_waypoint].time < next_time) {
            next_waypoint++;
        }
        if (next_waypoint < system.mover.num_points) {
            // Interpolate the rotation of the entity between the current waypoint and the next waypoint
            float t = (next_time - system.mover.steps[next_waypoint - 1].time) / (system.mover.steps[next_waypoint].time - system.mover.steps[next_waypoint - 1].time);
            system.rotation = system.mover.steps[next_waypoint - 1].rotation + t * (system.mover.steps[next_waypoint].rotation - system.mover.steps[next_waypoint - 1].rotation);
        } else {
            // The entity has reached the end of the path, so update the rotation and deactivate the path following system
            system.rotation = system.mover.steps[system.mover.num_points - 1].rotation;
            system.mover.active = false;
        }
    }
}
