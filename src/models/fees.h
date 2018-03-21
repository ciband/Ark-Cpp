

#ifndef fees_h
#define fees_h

#include "types/balance.h"
#include "utilities/platform.h"

namespace ARK {

/*  ================================================  */
/*  =========  */
/*  ARK::Fees  */
/*  /api/blocks/getFees */
class Fees : public Printable {
private:
    Balance send_;
    Balance vote_;
    Balance delegate_;
    Balance secondsignature_;
    Balance multisignature_;

public:
    Fees(
        const char* const s,
        const char* const v,
        const char* const d,
        const char* const ss,
        const char* const ms
    ) : send_(s), vote_(v), delegate_(d), secondsignature_(ss), multisignature_(ms) { }

	const Balance& send() const noexcept { return send_; }
	const Balance& vote() const noexcept { return vote_; }
	const Balance& delegate() const noexcept { return delegate_; }
	const Balance& second_signature() const noexcept { return secondsignature_; }
	const Balance& multi_signature() const noexcept { return multisignature_; }

    size_t printTo(Print& p) const override;
};
/*  =========  */
/*  ================================================  */

};

#endif
