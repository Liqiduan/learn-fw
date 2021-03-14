#ifndef PACKET_H
#define PACKET_H

#include <stdint.h>

#include "protocol.h"

typedef struct {
    uint16_t size;
    uint16_t offset;
    uint16_t length;
    uint16_t flags;
    uint8_t data[0];
} Packet;

void PacketDrop(Packet* packet);
Packet* PacketRaw(uint32_t length);
Packet* PacketIP(IPv4Address src, IPv4Address dest, Packet* payload);
Packet* PacketEth(MacAddress src, MacAddress dest, Packet* payload);

#endif
