#include <gtest/gtest.h>

#include "../Classic_vs_London/Store.h"
#include "../Classic_vs_London/Customer.h"

namespace classic
{
    TEST(PurchaseClassic, SucceedsWhenEnoughInventory)
    {
        // 준비
        Store store;
        store.AddProduct(Product::Shampoo, 10);

        Customer customer;

        // 실행
        bool isSuccess{ customer.Purchase(store, Product::Shampoo, 5) };

        // 검증
        EXPECT_TRUE(isSuccess);
        EXPECT_EQ(5, customer.GetInventory(Product::Shampoo));
        EXPECT_EQ(5, store.GetProductCount(Product::Shampoo));  // 여기서 이걸 검증하는게 맞나? sut는 customer인데
    }

    TEST(PurchaseClassic, FailsWhenNotEnoughInventory)
    {
        // 준비
        Store store;
        store.AddProduct(Product::Shampoo, 10);

        Customer customer;

        // 실행
        bool isSuccess{ customer.Purchase(store, Product::Shampoo, 20) };

        // 검증
        EXPECT_FALSE(isSuccess);
        EXPECT_EQ(0, customer.GetInventory(Product::Shampoo));
        EXPECT_EQ(10, store.GetProductCount(Product::Shampoo));    // 여기서 이걸 검증하는게 맞나? sut는 customer인데
    }
}
