

#ifndef HASH_H
#define HASH_H

#include <cstring>

/********************************************************************************
*
* hash: 
*   "578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23"
*   
*   64 Characters | HEX-encoded
*
********************************************************************************/

struct Hash
{
private:
  static const auto HASH_SIZE = 65;

  char value_[HASH_SIZE];

public:
  Hash() : value_() { }

  /*  =====  */

  Hash(const char* const hashStr) : value_()
  {
    strncpy(value_, hashStr, sizeof(value_) / sizeof(value_[0]));
  }

  /*  =====  */

  const char* getValue() const { return value_; }
};

#endif