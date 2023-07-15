#include <gtest/gtest.h>

#include "../Classic_vs_London/Store.h"
#include "../Classic_vs_London/Customer.h"

namespace classic
{
    TEST(PurchaseClassic, SucceedsWhenEnoughInventory)
    {
        // �غ�
        Store store;
        store.AddInventory(Product::Shampoo, 10);

        Customer customer;

        // ����
        bool isSuccess{ customer.Purchase(store, Product::Shampoo, 5) };

        // ����
        EXPECT_TRUE(isSuccess);
        EXPECT_EQ(5, store.GetInventory(Product::Shampoo));
    }

    TEST(PurchaseClassic, FailsWhenNotEnoughInventory)
    {
        // �غ�
        Store store;
        store.AddInventory(Product::Shampoo, 10);

        Customer customer;

        // ����
        bool isSuccess{ customer.Purchase(store, Product::Shampoo, 20) };

        // ����
        EXPECT_FALSE(isSuccess);
        EXPECT_EQ(10, store.GetInventory(Product::Shampoo));
    }
}
