#ifndef ENGINE_H
#define ENGINE_H

#include "packet.h"
#include "table_interface.h"

typedef void (*EngineRx)(TableInterfaceKey interface, Packet* packet);
typedef void (*EngineTx)(TableInterfaceKey interface, Packet* packet);
typedef void (*EngineTxRegister)(EngineTx tx);

typedef struct {
    EngineRx rx;
    EngineTxRegister registerTx;
} Engine;

#endif
