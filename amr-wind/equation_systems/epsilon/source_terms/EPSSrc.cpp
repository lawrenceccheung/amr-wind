#include <AMReX_Orientation.H>

#include "amr-wind/equation_systems/epsilon/source_terms/EPSSrc.H"
#include "amr-wind/CFDSim.H"
#include "amr-wind/turbulence/TurbulenceModel.H"

namespace amr_wind {
namespace pde {
namespace tke {

EPSSrc::EPSSrc(const CFDSim& sim)
    : m_eps_src(sim.repo().get_field("epsilon_src"))
    , m_eps_diss(sim.repo().get_field("eps_dissipation"))
{}

EPSSrc::~EPSSrc() = default;

void EPSSrc::operator()(
    const int lev,
    const amrex::MFIter& mfi,
    const amrex::Box& bx,
    const FieldState fstate,
    const amrex::Array4<amrex::Real>& src_term) const
{

    const auto& eps_src_arr = (this->m_eps_src)(lev).array(mfi);
    const auto& eps_diss_arr = (this->m_eps_diss)(lev).array(mfi);
}

} // namespace tke
} // namespace pde
} // namespace amr_wind
