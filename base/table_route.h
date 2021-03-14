#ifndef TABLE_ROUTE_H
#define TABLE_ROUTE_H

#include "protocol.h"

#include "table_interface.h"

typedef enum {
    ROUTE_ACTION_FORWARD
} TableRouteAction;

typedef struct {
    IPv4Address dest;
    uint32_t maskLength;
} TableRouteKey;

typedef struct {
    TableRouteAction action;
    IPv4Address nextHop;
    TableInterfaceKey interface;
} TableRouteEntry;

#endif
