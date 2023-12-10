class SolverSelection {
public:
    SolverSelection(const Settings& settings) : settings_(settings) {}

    void SetAdvectionSolver(AdvectionSolver& solver, AdvectionType type) {
        switch (type) {
            case AdvectionType::ForwardEuler:
                solver = ForwardEulerAdvectionSolver(settings_);
                break;
            case AdvectionType::BackwardEuler:
                solver = BackwardEulerAdvectionSolver(settings_);
                break;
            case AdvectionType::CrankNicolson:
                solver = CrankNicolsonAdvectionSolver(settings_);
                break;
            default:
                throw std::invalid_argument("Invalid advection type");
        }
    }

    void SetDiffusionSolver(DiffusionSolver& solver, DiffusionType type) {
        switch (type) {
            case DiffusionType::Fourier:
                solver = FourierDiffusionSolver(settings_);
                break;
            case DiffusionType::FiniteDifference:
                solver = FiniteDifferenceDiffusionSolver(settings_);
                break;
            default:
                throw std::invalid_argument("Invalid diffusion type");
        }
    }

private:
    const Settings& settings_;
};
