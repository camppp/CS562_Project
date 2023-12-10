inline void _follow_path(f64 dt)
{
  system.update_position = true;
  system.update_rotation = true;

  if (system.mover.state >= system.mover.steps[system.mover.num_points - 1].time){
    system.position = system.mover.steps[system.mover.num_points - 1].position;
    system.rotation = system.mover.steps[system.mover.num_points - 1].rotation;
    system.mover.active = false;
  } else {
    // Find the current segment of the path based on the elapsed time
    int segment = 0;
    while (system.mover.steps[segment + 1].time < system.mover.state) {
      segment++;
    }

    // Interpolate position and rotation based on the current segment
    f64 segment_time = system.mover.steps[segment + 1].time - system.mover.steps[segment].time;
    f64 t = (system.mover.state - system.mover.steps[segment].time) / segment_time;

    system.position = interpolate_position(system.mover.steps[segment].position, system.mover.steps[segment + 1].position, t);
    system.rotation = interpolate_rotation(system.mover.steps[segment].rotation, system.mover.steps[segment + 1].rotation, t);
  }
}
