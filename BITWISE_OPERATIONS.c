#include "BITWISE_OPERATIONS.h"

uint32_t SETBIT(uint32_t reg, uint8_t bit)
{
    uint32_t temp = (uint32_t)bit;
    uint32_t temp1 = 1U;
    temp = temp1 << temp;
    reg = reg | temp;
    return reg;
}

uint32_t CLEARBIT(uint32_t reg, uint8_t bit)
{
    uint32_t temp = (uint32_t)bit;
    uint32_t temp1 = 1U;
    temp = temp1 << temp;
    reg = reg & (~temp);
    return reg;
}

uint32_t TOGGLEBIT(uint32_t reg, uint8_t bit)
{
    uint32_t temp = (uint32_t)bit;
    uint32_t temp1 = 1U;
    temp = temp1 << temp;
    reg = reg ^ temp;
    return reg;
}

uint8_t CHECKBIT(uint32_t reg, uint8_t bit)
{
    uint32_t temp = (uint32_t)bit;
    uint32_t temp1 = 1U;
    uint32_t temp2 = (uint32_t)bit;
    temp = temp1 << temp;
    reg = (reg & temp)>>temp2;
    return (uint8_t)reg;
}
