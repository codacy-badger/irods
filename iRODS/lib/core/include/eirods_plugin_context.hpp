


#ifndef __EIRODS_PLUGIN_CONTEXT_H__
#define __EIRODS_PLUGIN_CONTEXT_H__

// =-=-=-=-=-=-=-
// stl includes
#include <string>

// =-=-=-=-=-=-=-
// eirods includes
#include "eirods_plugin_base.hpp"
#include "eirods_first_class_object.hpp"

namespace eirods {
    // =-=-=-=-=-=-=-
    // base context class for communicating to plugins
    class plugin_context {
        public:
        // =-=-=-=-=-=-=-
        // ctor
        plugin_context( 
            plugin_property_map&   _prop_map,  
            first_class_object_ptr _fco,       
            const std::string&     _results )  :
            prop_map_( _prop_map ),
            fco_( _fco ),
            results_( _results )  {
        
        } // ctor

        // =-=-=-=-=-=-=-
        // test to determine if contents are valid
        virtual error valid() { 
            return SUCCESS();

        } // valid

        // =-=-=-=-=-=-=-
        // test to determine if contents are valid
        template < typename OBJ_TYPE >
        error valid() { 
            // =-=-=-=-=-=-=
            // trap case of non type related checks
            error ret = valid();

            // =-=-=-=-=-=-=
            // trap case of incorrect type for first class object
            try {
                OBJ_TYPE* ref = dynamic_cast< OBJ_TYPE* >( fco_.get() );
            } catch( std::bad_cast exp ) {
                ret = PASSMSG( "invalid type for fco cast", ret );
            }

            return ret;

        } // valid

        // =-=-=-=-=-=-=-
        // accessors
        virtual plugin_property_map&   prop_map()     { return prop_map_;  }
        virtual first_class_object_ptr fco()          { return fco_;       }
        virtual const std::string      rule_results() { return results_;   }  
        
        // =-=-=-=-=-=-=-
        // mutators
        virtual void rule_results( const std::string& _s ) { results_ = _s; }  

        protected:
        // =-=-=-=-=-=-=-
        // attributes
        plugin_property_map&   prop_map_;  // resource property map
        first_class_object_ptr fco_;       // first class object in question
        std::string            results_;   // results from the pre op rule call

    }; // class plugin_context

    /// =-=-=-=-=-=-=-
    /// @brief type for the generic plugin operation
    typedef error (*plugin_operation)( plugin_context&, ... );

}; // namespace eirods

#endif // __EIRODS_PLUGIN_CONTEXT_H__



