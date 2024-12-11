#include <stdint.h>

#ifndef _BABYBEAR_POSEIDON2
  #define _BABYBEAR_POSEIDON2

  #ifdef __cplusplus
extern "C" {
  #endif

typedef struct scalar_t scalar_t;
typedef struct Hash Hash;

Hash* babybear_create_poseidon2_hasher(unsigned t, const scalar_t* domain_tag);

  #ifdef __cplusplus
}
  #endif

#endif