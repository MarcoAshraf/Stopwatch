#include "BITWISE_OPERATIONS.h"

uint8_t SETBIT(uint32_t reg, uint8_t bit)
{
    return (uint8_t)(reg |= (1U<<bit));
}

uint8_t CLEARBIT(uint32_t reg, uint8_t bit)
{
    return (uint8_t)(reg &= ~(1U<<bit));
}

uint8_t TOGGLEBIT(uint32_t reg, uint8_t bit)
{
    return (uint8_t)(reg ^= (1U<<bit));
}

uint8_t CHECKBIT(uint32_t reg, uint8_t bit)
{
    return (uint8_t)(reg & (1U<<bit))>>bit;
}
