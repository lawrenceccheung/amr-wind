#include "amr-wind/equation_systems/epsilon/EPS.H"
#include "amr-wind/equation_systems/AdvOp_Godunov.H"
#include "amr-wind/equation_systems/AdvOp_MOL.H"
#include "amr-wind/equation_systems/BCOps.H"
#include "amr-wind/equation_systems/epsilon/eps_ops.H"

namespace amr_wind {
namespace pde {

template class PDESystem<EPS, fvm::Godunov>;
template class PDESystem<EPS, fvm::MOL>;

} // namespace pde
} // namespace amr_wind
