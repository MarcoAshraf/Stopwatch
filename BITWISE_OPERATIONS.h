#ifndef _BITWISE_OPERATIONS_H_
#define _BITWISE_OPERATIONS_H_
#include <stdint.h>

inline uint32_t SETBIT(uint32_t reg, uint8_t bit);
inline uint32_t CLEARBIT(uint32_t reg, uint8_t bit);
inline uint32_t TOGGLEBIT(uint32_t reg, uint8_t bit);
inline uint8_t CHECKBIT(uint32_t reg, uint8_t bit);




#endif /* _BITWISE_OPERATIONS_H_ */
