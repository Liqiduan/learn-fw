#ifndef TABLE_INTERFACE_H
#define TABLE_INTERFACE_H

#include <stdint.h>

#include "protocol.h"

typedef struct {
    int index;
} TableInterfaceKey;

typedef struct {
    MacAddress mac;
    IPv4Address ip;
} TableInterfaceEntry;

#endif
