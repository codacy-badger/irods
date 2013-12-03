/* -*- mode: c++; fill-column: 132; c-basic-offset: 4; indent-tabs-mode: nil -*- */


#include "eirods_replicator.hpp"
#include "eirods_object_oper.hpp"

namespace eirods {

    replicator::replicator(
        oper_replicator* _oper_replicator) :
        oper_replicator_(_oper_replicator)
    {
    }

    replicator::~replicator(void) {
    }

    error replicator::replicate(
        resource_plugin_context& _ctx,
        const child_list_t& _siblings,
        object_list_t& _opers)
    {
        error result = SUCCESS();
        while(result.ok() && _opers.size()) {
            object_oper oper =  _opers.front();
            _opers.pop_front();
            error ret = oper_replicator_->replicate(_ctx, _siblings, oper);
            if(!ret.ok()) {
                std::stringstream msg;
                msg << __FUNCTION__;
                msg << " - Failed to replicate object \"" << oper.object().logical_path() << "\"";
                msg << " with operation \"" << oper.operation() << "\"";
                result = PASSMSG(msg.str(), ret);
            }
        }
        return result;
    }
    
}; // namespace eirods
