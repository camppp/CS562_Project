#ifndef EAGINE_UNITS_DIM_MASS_DENSITY_HPP
#define EAGINE_UNITS_DIM_MASS_DENSITY_HPP

#include <eagine/units/dimension.hpp>
#include <eagine/units/mass.hpp>
#include <eagine/units/volume.hpp>

namespace eagine::units {

// Define the mass density dimension
using mass_density = decltype(mass() / volume());

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_MASS_DENSITY_HPP
