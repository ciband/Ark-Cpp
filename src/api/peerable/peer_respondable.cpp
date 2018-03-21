#include "api/peerable/peer_respondable.h"

namespace ARK {
namespace API {
namespace Peer {
namespace Respondable {

size_t Version::printTo(Print& p) const
  {
    size_t size = 0;
      size += p.print("version: ");
      size += p.print(this->version_);
      size += p.print("\nbuild: ");
      size += p.print(this->build_);
    return size;
  }



/*  ==========================================================================  */
/*  ==================================  */
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
