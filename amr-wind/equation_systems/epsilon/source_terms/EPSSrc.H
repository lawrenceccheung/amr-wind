#ifndef EPSSRC_H
#define EPSSRC_H

#include "amr-wind/CFDSim.H"
#include "amr-wind/core/FieldDescTypes.H"
#include "amr-wind/equation_systems/epsilon/EPSSource.H"
#include <AMReX_MFIter.H>

namespace amr_wind {
namespace pde {
namespace tke {

class EPSSrc : public EPSSource::Register<EPSSrc>
{

public:
    static const std::string identifier() { return "EPSSrc"; }
    explicit EPSSrc(const CFDSim&);
    virtual ~EPSSrc();
    virtual void operator()(
        const int lev,
        const amrex::MFIter& mfi,
        const amrex::Box& bx,
        const FieldState fstate,
        const amrex::Array4<amrex::Real>& src_term) const override;

private:
    Field& m_eps_src;
    Field& m_eps_diss;
};

} // namespace tke

} // namespace pde

} // namespace amr_wind

#endif
