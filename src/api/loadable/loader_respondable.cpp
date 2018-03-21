#include "api/loadable/loader_respondable.h"

#include <cstring>
#include <cstdio>


namespace ARK {
namespace API {
namespace Loader {
namespace Respondable {

size_t Status::printTo(Print& p) const
    {
      size_t size = 0;
        size += p.print("loaded: ");
        size += p.print(this->loaded_ ? "true" : "false");
        size += p.print("\nnow: ");
        size += p.print(this->now_);
        size += p.print("\nblocksCount: ");
        size += p.print(this->blocksCount_);
      return size;
    }



size_t Sync::printTo(Print& p) const
    {
      size_t size = 0;
        size += p.print("syncing: ");
        size += p.print(this->syncing_ ? "true" : "false");
        size += p.print("\nblocks: ");
        size += p.print(this->blocks_);
        size += p.print("\nheight: ");
        size += p.print(this->height_);
        size += p.print("\nid: ");
        size += p.print(this->id_);
      return size;
    }

}
}
}
}
