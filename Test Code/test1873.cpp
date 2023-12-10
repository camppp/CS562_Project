#ifndef EAGINE_UNITS_DIM_MASS_DENSITY_HPP
#define EAGINE_UNITS_DIM_MASS_DENSITY_HPP

namespace eagine::units {

// Mass density dimension
struct mass_density_dim {
    using unit = mass_density_dim;
    using scalar = double;
    using scalar_type = scalar;
    using unit_type = unit;
    using dimension = dimension_t<1, 1, 1, 1, 1, 0>;
    using base_units = base_units_t<mass_dim, length_dim, time_dim>;
    using units = units_t<mass_density_dim, mass_dim, length_dim, time_dim>;
};

// Mass density constants
constexpr auto g_per_cm3 = mass_density_dim{1.0};
constexpr auto kg_per_m3 = mass_density_dim{1000.0};

// Mass density conversions
template <typename U>
constexpr auto to_mass_density(U&& u) {
    return u * g_per_cm3;
}

template <typename U>
constexpr auto to_mass_density(U&& u) {
    return u * kg_per_m3;
}

// Mass density arithmetic
template <typename U>
constexpr auto operator+(mass_density_dim u, U&& v) {
    return u + to_mass_density(v);
}

template <typename U>
constexpr auto operator-(mass_density_dim u, U&& v) {
    return u - to_mass_density(v);
}

template <typename U>
constexpr auto operator*(mass_density_dim u, U&& v) {
    return u * to_mass_density(v);
}

template <typename U>
constexpr auto operator/(mass_density_dim u, U&& v) {
    return u / to_mass_density(v);
}

} // namespace eagine::units

#endif // EAGINE_UNITS_DIM_MASS_DENSITY_HPP
