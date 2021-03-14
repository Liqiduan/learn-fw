#include <map>

#include "table.h"

#include "table_arp.h"
#include "table_route.h"
#include "table_interface.h"

using namespace std;

class TableManager {
    public:
        map<TableArpKey, TableArpEntry> arp;
        map<TableInterfaceKey, TableInterfaceEntry> interface;
        map<TableRouteKey, TableRouteEntry> route;
};

TableManager g_tableManager;

void* TableQuery(TableType type, void* key)
{
    switch (type) {
        case TABLE_ARP:
            return (void*)&g_tableManager.arp.find((TableArpKey&)key)->second;
        case TABLE_INTERFACE:
            return (void*)&g_tableManager.interface.find((TableInterfaceKey&)key)->second;
        case TABLE_ROUTE:
            return (void*)&g_tableManager.route.find((TableRouteKey&)key)->second;
    }
}

int TableInsert(TableType type, void* key, void* entry)
{
    return 0;
}

int TableUpadte(TableType type, void* key, void* entry)
{
    return 0;
}

int TableDelete(TableType type, void* key)
{
    return 0;
}
