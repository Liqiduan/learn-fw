#ifndef ENGINE_H
#define ENGINE_H

#include "packet.h"
#include "table_interface.h"

typedef enum {
    ENGINE_STATUS_BUSY,
    ENGINE_STATUS_IDLE
} EngineStatus;

typedef Packet* (*EngineRx)(TableInterfaceKey interface);
typedef void (*EngineTx)(TableInterfaceKey interface, Packet* packet);

EngineStatus EnginePoll();
void EngineRegisterRx(EngineRx rx);
void EngineRegisterTx(EngineTx tx);

#endif
