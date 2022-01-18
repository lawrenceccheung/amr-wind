#ifndef EPS_OPS_H
#define EPS_OPS_H

#include "amr-wind/equation_systems/epsilon/EPS.H"
#include "amr-wind/core/field_ops.H"

namespace amr_wind {
namespace pde {

/** Implementation of Turbulence operator for EPS equation
 *  \ingroup eps_eqn
 */
template <>
struct TurbulenceOp<EPS>
{

    TurbulenceOp(turbulence::TurbulenceModel& tmodel, PDEFields& fields)
        : m_tmodel(tmodel), m_fields(fields)
    {}

    void operator()()
    {

        auto& mueff = m_fields.mueff;
        m_tmodel.update_scalar_diff(mueff, EPS::var_name());
    }

    turbulence::TurbulenceModel& m_tmodel;
    PDEFields& m_fields;
};

/** Implementation of post-processing actions for EPS equation
 *  \ingroup eps_eqn
 */

template <>
struct PostSolveOp<EPS>
{

    PostSolveOp(CFDSim&, PDEFields& fields) : m_fields(fields) {}

    void operator()(const amrex::Real time)
    {
        field_ops::lower_bound(m_fields.field, clip_value);
        m_fields.field.fillpatch(time);
    }
    PDEFields& m_fields;
    amrex::Real clip_value{1.0e-8};
};

template <typename Scheme>
struct FieldRegOp<EPS, Scheme>
{
    explicit FieldRegOp(CFDSim& sim_in) : sim(sim_in) {}

    PDEFields operator()(const SimTime& time, const int probtype)
    {
        auto& repo = sim.repo();
        auto fields = create_fields_instance<EPS, Scheme>(time, repo, probtype);
        repo.declare_cc_field(
            EPS::var_name() + "_lhs_src_term", EPS::ndim, 1, 1);
        sim.io_manager().register_io_var(fields.field.name());

        return fields;
    }

    CFDSim& sim;
};

} // namespace pde
} // namespace amr_wind

#endif
