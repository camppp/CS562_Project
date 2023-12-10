#include <shogun/latent/LatentSOSVM.h>
#include <shogun/structure/DualLibQPBMSOSVM.h>

using namespace shogun;

CLatentSOSVM::CLatentSOSVM()
	: CLinearLatentMachine()
{
	// Register parameters
	SG_ADD(&m_so_solver, "so_solver", "Solver for solving the SOSVM optimization problem.");

	// Initialize member variables
	m_so_solver = NULL;
}
