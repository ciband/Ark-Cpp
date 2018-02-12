

#ifndef PEER_RESPONDABLE_H
#define PEER_RESPONDABLE_H

#include <cstring>

namespace ARK
{
namespace API
{
namespace Peer
{
namespace Respondable
{

/*  ==========================================================================  */
/*  ========================  */
/*  ARK::API::Peer::Respondable::Version  */
  struct Version {
    public:
        char version[64];  //TODO: review sizes
        char build[64];

        Version(const char* const v, const char* const b) : version(), build() {
            strncpy(version, v, sizeof(version) / sizeof(version[0]));
            strncpy(build, b, sizeof(build) / sizeof(build[0]));
        }

        void description(char* const buf, size_t size);
  };
/*  ========================  */
/*  ==========================================================================  */


/*  ==========================================================================  */
/*  ==================================  */
/*  ARK::API::Peer::Respondable::Peers  */
//   struct Peers {
//     public:
//       // int count;
//       ARK::Peer list[10];// = {{}};
//       // PeersResponse(int);
//       String description();
//   };
/*  ==================================  */
/*  ==========================================================================  */


};
};
};
};


#endif
