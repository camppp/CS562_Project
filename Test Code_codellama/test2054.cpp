CLatentSOSVM::CLatentSOSVM() : CLinearLatentMachine()
{
    // Register the necessary parameters
    register_param<int>("m_so_solver", "The solver used for structured output", 0);
    register_param<int>("m_so_max_iter", "The maximum number of iterations for the solver", 100);
    register_param<double>("m_so_tol", "The tolerance for the solver", 1e-3);

    // Initialize the m_so_solver member variable to NULL
    m_so_solver = NULL;
}
