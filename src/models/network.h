

#ifndef network_h
#define network_h

#include "utilities/platform.h"

#include <cstring>

namespace ARK {

/*  ================================================  */
/*  ARK::NetworkType  */
  enum NetworkType { INVALID = -1, DEV = 0, MAIN = 1, CUSTOM = 2 };
/*  ================================================  */

/********************************************************************************
*
* Network: 
*  	578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23
*		DARK
*		DѦ
*		https://dexplorer.ark.io/
*		30
*
********************************************************************************/

/*  ================================================  */
  /*  ============  */
  /*  ARK::Network  */
class Network : public Printable {
private:
    char nethash_[65];		//TODO: review sizes
    char token_[8];
    char symbol_[4];
    char explorer_[65];
    int version_;

public:
    Network() : nethash_(), token_(), symbol_(), explorer_(), version_(-1) { }
    Network(
        const char* const n, 
        const char* const t, 
        const char* const s, 
        const char* const e, 
        int v
    ) : nethash_(), token_(), symbol_(), explorer_(), version_(v) { 
        strncpy(nethash_, n, sizeof(nethash_) / sizeof(nethash_[0]));
        strncpy(token_, t, sizeof(token_) / sizeof(token_[0]));
        strncpy(symbol_, s, sizeof(symbol_) / sizeof(symbol_[0]));
        strncpy(explorer_, e, sizeof(explorer_) / sizeof(explorer_[0]));
    }

	const char* nethash() const noexcept { return nethash_; }
	const char* token() const noexcept { return token_; }
	const char* symbol() const noexcept { return symbol_; }
	const char* explorer() const noexcept { return explorer_; }
	int version() const noexcept { return version_; }

    size_t printTo(Print& p) const override;

    bool operator==(const Network& rhs) const;
    bool operator!=(const Network& rhs) const;
};
  /*  ============  */
  /*  ================================================  */
  /*  ================  */
  /*  ARK::Network_ADV  */
  namespace Network_ADV {
    struct bip32_t {
      long pub;         // base58 will have a prefix 'apub'
      long priv;        // base58Priv will have a prefix 'apriv'
    };

    struct network_t {
      const char* messagePrefix;
      bip32_t bip32;
      long pubKeyHash;  // Addresses will begin with 'A'
      long wif;         // Network prefix for wif generation
    };
  };
/*  ================  */

};


#endif
