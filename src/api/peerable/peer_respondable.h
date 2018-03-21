

#ifndef PEER_RESPONDABLE_H
#define PEER_RESPONDABLE_H

#include "utilities/platform.h"

#include <cstring>

namespace ARK {
namespace API {
namespace Peer {
namespace Respondable {

/*************************************************
*		ARK::API::Peer::Respondable::Version
*
*   @param:	char version{32], char build[32]
*
*   @methods:	printTo(Print& p)
*
*   @brief:	Model for Loader Status API Response
**************************************************/
class Version : public Printable {
private:
	char version_[64];  //TODO: review sizes
	char build_[64];

public:
	Version(const char* const v, const char* const b) : version_(), build_() {
		strncpy(version_, v, sizeof(version_) / sizeof(version_[0]));
		strncpy(build_, b, sizeof(build_) / sizeof(build_[0]));
	}

	const char* version() const noexcept { return version_; }
	const char* build() const noexcept { return build_; }

	size_t printTo(Print& p) const override;
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
/*************************************************/
/*************************************************/


/*************************************************/
/*************************************************/
/*  ARK::API::Peer::Respondable::Peers  */
/*  Description  */
// String ARK::API::Peer::Respondable::Peers::description() {
//   String resp;
//   if (this->count > 0) {
//     for (int i = 0; i < this->count; i++) {
//       resp += "\npeer ";
//       resp += i + 1;
//       resp += ":\n";
//       resp += this->list[i].description();
//       resp += "\n";
//     };
//   };
//   return resp;
// }
/*  ==================================  */
/*  ==========================================================================  */


}
}
}
}

#endif
