#ifndef TABLE_H
#define TABLE_H

typedef enum {
    TABLE_INTERFACE,
    TABLE_ROUTE,
    TABLE_ARP
} TableType;

void* TableQuery(TableType type, void* key);
int TableInsert(TableType type, void* key, void* entry);
int TableUpadte(TableType type, void* key, void* entry);
int TableDelete(TableType type, void* key);

#endif
