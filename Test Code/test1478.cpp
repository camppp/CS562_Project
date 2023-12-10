#include "oblog.hpp"
#include "ode_engine.hpp"

using namespace OB;

void EngineLogger::engine_pre_step(Engine &engine)
{
    Vector linMomentum = engine.get_linear_momentum();
    Vector angMomentum = engine.get_angular_momentum();
    Real kinEnergy = engine.get_kinetic_energy();
    Vector position{0,0,0};
    log_stream << static_cast<int>(LogType::engine) << ";"
               << engine.get_physics_time().count() << ";"
               << linMomentum.x << "," << linMomentum.y << "," << linMomentum.z << ";"
               << angMomentum.x << "," << angMomentum.y << "," << angMomentum.z << ";"
               << kinEnergy << ";"
               << position.x << "," << position.y << "," << position.z << "\n";
}
