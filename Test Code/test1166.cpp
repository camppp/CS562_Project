bool Command::isSingleRotorThrusts() const 
{
    // Check if the command represents single rotor thrusts
    return thrusts.allFinite() && !std::isfinite(collective_thrust) && !omega.allFinite();
}
