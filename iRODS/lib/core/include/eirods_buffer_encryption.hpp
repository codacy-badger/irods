


#ifndef __EIRODS_BUFFER_ENCRYPTION_H__
#define __EIRODS_BUFFER_ENCRYPTION_H__

// =-=-=-=-=-=-=-
// irods includes
#include "rodsDef.hpp"

// =-=-=-=-=-=-=-
// eirods includes
#include "eirods_error.hpp"

// =-=-=-=-=-=-=-
// boost includes
#include <boost/numeric/ublas/storage.hpp>

// =-=-=-=-=-=-=-
// ssl includes
#include <openssl/evp.h>

namespace eirods {

    /// =-=-=-=-=-=-=-
    /// @brief functor which manages buffer encryption
    ///        used for parallel transfers.  based on 
    ///        SSL EVP library
    class buffer_crypt {
    public:
        // =-=-=-=-=-=-=-
        // typedef for bounded array
        typedef std::vector< unsigned char > array_t;

        // =-=-=-=-=-=-=-
        // con/de structors
        buffer_crypt();
        buffer_crypt( 
            int,           // key size in bytes
            int,           // salt size in bytes
            int,           // num hash rounds
            const char* ); // algorithm
        ~buffer_crypt();
        
        /// =-=-=-=-=-=-=-
        /// @brief given a string, encrypt it
        eirods::error encrypt( 
            const array_t&, // key
            const array_t&, // initialization vector
            const array_t&, // plaintext buffer
            array_t& );     // encrypted buffer

        /// =-=-=-=-=-=-=-
        /// @brief given a string, decrypt it
        eirods::error decrypt( 
            const array_t&, // key
            const array_t&, // initialization vector
            const array_t&, // encrypted buffer
            array_t& );     // plaintext buffer

        /// =-=-=-=-=-=-=-
        /// @brief given a key, create a hashed key and IV
        eirods::error initialization_vector(
            array_t& );     // intialization vector

        /// =-=-=-=-=-=-=-
        /// @brief generate a random byte key
        eirods::error generate_key(
            array_t& ); // random byte key
        
        /// =-=-=-=-=-=-=-
        /// @brief accessors for attributes
        int         key_size()        { return key_size_;        };
        int         salt_size()       { return salt_size_;       };
        int         num_hash_rounds() { return num_hash_rounds_; };
        std::string algorithm()       { return algorithm_;       };

        static std::string gen_hash( unsigned char*, int );

    private:
        // =-=-=-=-=-=-=-
        // attributes
        int         key_size_;
        int         salt_size_;
        int         num_hash_rounds_;
        std::string algorithm_;

    }; // class buffer_crypt

}; // namespace eirods

#endif // __EIRODS_BUFFER_ENCRYPTION_H__



