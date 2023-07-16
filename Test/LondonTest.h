#include <gtest/gtest.h>

#include "../Classic_vs_London/Store.h"
#include "../Classic_vs_London/Customer.h"
#include "MockStore.h"

namespace london
{
    TEST(PurchaseLondon, SucceedsWhenEnoughInventory)
    {
        // �غ�
        FakeStore store;
        EXPECT_CALL(store, Purchase).WillOnce(testing::Return(true));

        Customer sut;
        
        // ����
        bool isSuccess{ sut.Purchase(store, Product::Shampoo, 5) };

        // ����
        EXPECT_TRUE(isSuccess);
        EXPECT_EQ(5, sut.GetInventory(Product::Shampoo));
    }

    TEST(PurchaseLondon, FailsWhenNotEnoughInventory)
    {
        // �غ�
        FakeStore store;
        EXPECT_CALL(store, Purchase).WillOnce(testing::Return(false));

        Customer sut;

        // ����
        bool isSuccess{ sut.Purchase(store, Product::Shampoo, 10) };

        // ����
        EXPECT_FALSE(isSuccess);
        EXPECT_EQ(0, sut.GetInventory(Product::Shampoo));
    }
}