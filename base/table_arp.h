#ifndef TABLE_ARP_H
#define TABLE_ARP_H

#include "protocol.h"

typedef struct {
    IPv4Address ip;
} TableArpKey;

typedef struct {
    MacAddress mac;
} TableArpEntry;

#endif
