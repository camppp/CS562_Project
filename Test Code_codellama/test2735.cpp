class ElementView {
private:
    MaterialParamsRef params_;
    int atomic_number_;

public:
    // Construct from shared material data and global element ID
    ElementView(const MaterialParamsRef& params, int atomic_number)
        : params_(params), atomic_number_(atomic_number) {}

    // Atomic number Z
    int atomic_number() const { return atomic_number_; }

    // Calculate the average atomic mass of the element
    double average_atomic_mass() const {
        double atomic_mass_sum = 0;
        double natural_abundance_sum = 0;
        for (int isotope = 0; isotope < params_.num_isotopes(); isotope++) {
            atomic_mass_sum += params_.atomic_mass(isotope) * params_.natural_abundance(isotope);
            natural_abundance_sum += params_.natural_abundance(isotope);
        }
        return atomic_mass_sum / natural_abundance_sum;
    }
};
