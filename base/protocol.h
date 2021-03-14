#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <bits/stdint-uintn.h>
#include <stdint.h>

#pragma pack(1)
typedef enum {
    ETH_IPV4 = 0x0800
} EthType;

typedef struct {
    uint8_t mac[6];
} MacAddress;

typedef struct {
    MacAddress dmac;
    MacAddress smac;
    uint16_t type;
    uint8_t payload[0];
} EthHeader;
#pragma pack()

static inline MacAddress MAC(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e, uint8_t f)
{
    return MacAddress {a, b, c, d, e, f};
}

#pragma pack(1)
typedef uint32_t IPv4Address;

typedef struct {
    uint8_t version:4;
    uint8_t IHL:4;
    uint8_t ToS;
    uint16_t totalLength;

    uint16_t id;
    uint16_t flags:3;
    uint16_t offset:13;

    uint8_t TTL;
    uint8_t protocol;
    uint16_t checksum;

    IPv4Address src;

    IPv4Address dst;

    uint8_t options[0];
} IpHeader;

#pragma pack()

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

#endif
