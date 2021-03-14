#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>
#include <sys/types.h>

#include "table.h"
#include "table_arp.h"
#include "table_interface.h"
#include "table_route.h"

class TestTableParam {
    public:
        TableType type;
        void* key;
        void* entry;
};


class TestTable : public testing::TestWithParam<TestTableParam> {
};

TEST_P(TestTable, TableInsertShouldSuccess)
{
    auto param = GetParam();

    int ret = TableInsert(param.type, param.key, param.entry);
    EXPECT_EQ(ret, 0);

    void* result = TableQuery(param.type, param.key);
    EXPECT_EQ(result, param.entry);

    ret = TableDelete(param.type, param.key);
    EXPECT_EQ(ret, 0);
}

INSTANTIATE_TEST_SUITE_P(AllTableType,
                         TestTable,
                         testing::Values(
                             TestTableParam {
                                TABLE_ARP,
                                new TableArpKey{IP(10, 1, 1, 1)},
                                new TableArpEntry{MAC(0xa0, 0x00, 0x00, 0x00, 0x00, 0x01)}},
                             TestTableParam {
                                TABLE_INTERFACE,
                                new TableInterfaceKey{1},
                                new TableInterfaceEntry {
                                    MAC(0xa0, 0x00, 0x00, 0x00, 0x00, 0x01),
                                    IP(10, 1, 1, 1)}}
                             ));
