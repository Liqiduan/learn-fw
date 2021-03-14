#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>

typedef uint32_t IPv4Address;

static inline IPv4Address IP(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
{
    union {
        IPv4Address ip;
        uint8_t data[4];
    } addr = {
        .data = {a, b, c, d}
    };
    return addr.ip;
}


typedef struct {
    uint8_t mac[6];
} MacAddress;

static inline MacAddress MAC(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f)
{
    return MacAddress {a, b, c, d, e, f};
}

#endif
