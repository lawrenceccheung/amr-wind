#ifndef EPS_H
#define EPS_H

#include "amr-wind/equation_systems/PDETraits.H"
#include "amr-wind/equation_systems/SchemeTraits.H"
#include "amr-wind/equation_systems/PDEHelpers.H"
#include "amr-wind/equation_systems/PDE.H"
#include "amr-wind/core/field_ops.H"
#include "amr-wind/equation_systems/epsilon/EPSSource.H"

namespace amr_wind {
namespace pde {

/**
 *  \defgroup eps_eqn Dissipation Rate (epsilon) transport equation
 *  %EPS transport equation
 *
 *  \ingroup eqsys
 */

/**
 *  \defgroup eps_src EPS source terms
 *
 *  Source terms used with EPS transport equation
 *
 *  \ingroup eps_eqn
 */

/** Characteristics of EPS transport equation
 *  \ingroup eps_eqn
 */
struct EPS : ScalarTransport
{
    using MLDiffOp = amrex::MLABecLaplacian;
    using SrcTerm = EPSSource;

    static std::string pde_name() { return "EPS"; }
    static std::string var_name() { return "eps"; }

    static constexpr amrex::Real default_bc_value = 0.0;

    static constexpr int ndim = 1;
    static constexpr bool multiply_rho = true;
    static constexpr bool has_diffusion = true;
    static constexpr bool need_nph_state = true;
};

} // namespace pde
} // namespace amr_wind

#endif /* EPS_H */
