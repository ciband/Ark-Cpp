

#ifndef LOADER_RESPONDABLE_H
#define LOADER_RESPONDABLE_H

#include "utilities/platform.h"

#include <cstring>

namespace ARK {
namespace API {
namespace Loader {
namespace Respondable {

/*************************************************
*	ARK::API::Loader::Respondable::Status
*
*   @param: bool loaded, int now, char blocksCount[64]
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @brief:	Model for Loader Status API Response
**************************************************/
class Status : public Printable {
private:
    bool loaded_;
    int now_;
    char blocksCount_[32];  //TODO review sizes

public:
    Status(
        const char* const l,
        int n,
        const char* const bc
    ) : loaded_(strcmp(l, "true") == 0), now_(n), blocksCount_() {
        strncpy(blocksCount_, bc, sizeof(blocksCount_) / sizeof(blocksCount_[0]));
    }

	bool loaded() const noexcept { return loaded_; }
	int now() const noexcept { return now_; }
	const char* blocks_count() const noexcept { return blocksCount_; }

    size_t printTo(Print& p) const override;
};
/*  ============  */
/*  ================================================  */


/*************************************************
*		ARK::API::Loader::Respondable::Sync 
*
*   @param:	bool syncing, int blocks, char height[32], char id[32]
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @brief:	Model for Loader Sync API Response
**************************************************/
class Sync : public Printable {
private:
    bool syncing_;
    int blocks_;
    char height_[32]; //TODO: review sizes
    char id_[32];

public:
    Sync(
        const char* s,
        int b,
        const char* const h,
        const char* const i
    ) : syncing_(strcmp(s, "true") == 0), blocks_(b), height_(), id_() {
        strncpy(height_, h, sizeof(height_) / sizeof(height_[0]));
        strncpy(id_, i, sizeof(id_) / sizeof(id_[0]));
    }

	bool syncing() const noexcept { return syncing_; }
	int blocks() const noexcept { return blocks_; }
	const char* height() const noexcept { return height_; }
	const char* id() const noexcept { return id_; }

    size_t printTo(Print& p) const override;
};

}
}
}
}

#endif
