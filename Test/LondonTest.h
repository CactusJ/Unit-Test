#include <gtest/gtest.h>

#include "../Classic_vs_London/Store.h"
#include "../Classic_vs_London/Customer.h"
#include "MockStore.h"

namespace london
{
    TEST(PurchaseLondon, SucceedsWhenEnoughInventory)
    {
        // 준비
        FakeStore store;
        EXPECT_CALL(store, Purchase).WillOnce(testing::Return(true));

        Customer sut;
        
        // 실행
        bool isSuccess{ sut.Purchase(store, Product::Shampoo, 5) };

        // 검증
        EXPECT_TRUE(isSuccess);
        EXPECT_EQ(5, sut.GetInventory(Product::Shampoo));
    }

    TEST(PurchaseLondon, FailsWhenNotEnoughInventory)
    {
        // 준비
        FakeStore store;
        EXPECT_CALL(store, Purchase).WillOnce(testing::Return(false));

        Customer sut;

        // 실행
        bool isSuccess{ sut.Purchase(store, Product::Shampoo, 10) };

        // 검증
        EXPECT_FALSE(isSuccess);
        EXPECT_EQ(0, sut.GetInventory(Product::Shampoo));
    }
}