#include <gtest/gtest.h>
#include <HippoMocks/hippomocks.h>

#include "protocol.h"
#include "table.h"

#include "table_interface.h"
#include "table_route.h"
#include "table_arp.h"

#include "packet.h"

#include "engine.h"

Packet* MockRx(TableInterfaceKey interface)
{
    return NULL;
}

void MockTx(TableInterfaceKey key, Packet* packet)
{
}

TEST(TestBasicFw, BasicIpv4Fw)
{
    int inIndex {1};
    MacAddress inMac = MAC(0XA0, 0x00, 0x00, 0x00, 0x00, 0x01);
    TableInterfaceEntry in {inMac, IP(10, 1, 1, 1)};
    TableInsert(TABLE_INTERFACE, &inIndex, &in);

    int outIndex {2};

    MacAddress outMac = MAC(0xB0, 0x00, 0x00, 0x00, 0x00, 0x01);
    TableInterfaceEntry out {outMac, IP(20, 1, 1, 1)};
    TableInsert(TABLE_INTERFACE, &outIndex, &out);

    IPv4Address dest = IP(100, 1, 1, 0);
    IPv4Address nextHop = IP(20, 1, 1, 2);
    TableRouteKey routeKey {dest, 24};
    TableRouteEntry routeEntry {ROUTE_ACTION_FORWARD, nextHop, outIndex};
    TableInsert(TABLE_INTERFACE, &routeKey, &routeEntry);

    TableArpKey arpKey {IP(20, 1, 1, 2)};
    TableArpEntry arpEntry {MAC(0xAB, 0xCD, 0xEF, 0x01, 0x02, 0x03)};
    TableInsert(TABLE_ARP, &arpKey, &arpEntry);

    Packet* packet = PacketEth(MAC(0xC0, 0x00, 0x00, 0x00, 0x00, 0x01), inMac,
                        PacketIP(IP(10, 1, 1, 2), dest,
                            PacketRaw(64)));

    EngineRegisterRx(MockRx);
    EngineRegisterTx(MockTx);

    MockRepository mocks;
    mocks.ExpectCallFunc(MockRx)
        .With(inIndex)
        .Return(packet);
    mocks.ExpectCallFunc(MockRx)
        .With(outIndex)
        .Return(NULL);

    Packet* resultPacket;
    mocks.ExpectCallFunc(MockTx)
        .With(outIndex, In(resultPacket));

    while (EnginePoll() == ENGINE_STATUS_BUSY) {}

    EthHeader* eth = (EthHeader*)(resultPacket->data + resultPacket->offset);
    EXPECT_EQ(eth->smac, out.mac);
    EXPECT_EQ(eth->dmac, arpEntry.mac);

    IpHeader* ip = (IpHeader*)(eth + 1);
    EXPECT_EQ(ip->dst, nextHop);

    PacketDrop(resultPacket);
}
