#include "api/blockable/block_respondable.h"

#include <cstring>
#include <cstdio>

namespace ARK {
namespace API {
namespace Block {
namespace Respondable {

size_t Status::printTo(Print& p) const
    {
      size_t size = 0;
        size += p.print("\nepoch: ");
        size += p.print(this->epoch_);

        size += p.print("\nheight: ");
        size += p.print(this->height_);

				size += p.print("\nfee: ");
        size += p.print(this->fee_.ark());

				size += p.print("\nmilestone: ");
        size += p.print(this->milestone_);

				size += p.print("\nnethash: ");
        size += p.print(this->nethash_.getValue());

				size += p.print("\nreward: ");
        size += p.print(this->reward_.ark());

				size += p.print("\nsupply: ");
        size += p.print(this->supply_.ark());
      return size;
    };



/*  ==========================================================================  */
/*  ====================================  */
/*  ARK::API::Block::Respondable::Height  */
/*  Description  */
void ARK::API::Block::Respondable::Height::description(char* const buf, size_t size)
{
    strcpy(buf, "height: ");
    strcat(buf, this->height_);
    strcat(buf, "\nid: ");
    strcat(buf, this->id_);
}
/*  ====================================  */
/*  ==========================================================================  */

}
}
}
}

