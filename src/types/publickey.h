

#ifndef PUBLICKEY_H
#define PUBLICKEY_H

#include <cstring>

/********************************************************************************
*
* publicKey: 
*   "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456"
*   
*   66 Characters | Base64-encoded
*
********************************************************************************/

    struct publickey_t {
    private:
        static const auto PUBLICKEY_SIZE = 67;

        char value_[PUBLICKEY_SIZE];

    public:
        publickey_t() : value_() { };

        publickey_t(const char* const _base64String) : value_() {      
          strncpy(value_, _base64String, sizeof(value_) / sizeof(value_[0]));
        };

        publickey_t(const publickey_t& other) : value_() {
            strcpy(value_, other.value_);
        }
        publickey_t& operator=(const publickey_t& other) {
            if (this != &other) {
                strcpy(value_, other.value_);
            }
            return *this;
        }

        const char* getValue() const { return value_; }     
    };

    typedef publickey_t Publickey;


//   };
// };


#endif
