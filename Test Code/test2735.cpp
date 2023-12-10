// Calculate the average atomic mass of the element
double ElementView::average_atomic_mass() const {
    double total_mass = 0.0;
    double total_abundance = 0.0;

    // Iterate over isotopes and calculate the weighted average
    for (int isotope = 1; ; isotope++) {
        double mass = params_.atomic_mass(isotope);
        double abundance = params_.natural_abundance(isotope);

        if (mass == 0.0 || abundance == 0.0) {
            // End of isotopic data
            break;
        }

        total_mass += mass * abundance;
        total_abundance += abundance;
    }

    if (total_abundance > 0.0) {
        return total_mass / total_abundance;
    } else {
        // Handle the case where no isotopic data is available
        return 0.0; // or throw an exception
    }
}
