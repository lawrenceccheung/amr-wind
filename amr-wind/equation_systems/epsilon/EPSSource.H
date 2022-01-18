#ifndef EPSSOURCE_H
#define EPSSOURCE_H

#include "amr-wind/core/Factory.H"
#include "amr-wind/core/FieldDescTypes.H"
#include "amr-wind/core/FieldUtils.H"
#include "amr-wind/core/FieldRepo.H"
#include "AMReX_MultiFab.H"
#include <AMReX_Array4.H>
#include <AMReX_MFIter.H>

namespace amr_wind {

class CFDSim;

namespace pde {

/** Base class for EPS source terms.
 *  \ingroup eps_src
 *
 *  All concrete implementations of EPS source terms must subclass this class.
 */

class EPSSource : public Factory<EPSSource, const CFDSim&>
{
public:
    static const std::string base_identifier() { return "EPSSource"; }
    virtual ~EPSSource() = default;

    virtual void operator()(
        const int lev,
        const amrex::MFIter& mfi,
        const amrex::Box& bx,
        const FieldState fstate,
        const amrex::Array4<amrex::Real>& src_term) const = 0;
};

} // namespace pde
} // namespace amr_wind

#endif
