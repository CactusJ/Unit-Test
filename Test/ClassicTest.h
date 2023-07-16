#include <gtest/gtest.h>

#include "../Classic_vs_London/Store.h"
#include "../Classic_vs_London/Customer.h"

namespace classic
{
    TEST(PurchaseClassic, SucceedsWhenEnoughInventory)
    {
        // �غ�
        Store store;
        store.AddProduct(Product::Shampoo, 10);

        Customer customer;

        // ����
        bool isSuccess{ customer.Purchase(store, Product::Shampoo, 5) };

        // ����
        EXPECT_TRUE(isSuccess);
        EXPECT_EQ(5, customer.GetInventory(Product::Shampoo));
        EXPECT_EQ(5, store.GetProductCount(Product::Shampoo));  // ���⼭ �̰� �����ϴ°� �³�? sut�� customer�ε�
    }

    TEST(PurchaseClassic, FailsWhenNotEnoughInventory)
    {
        // �غ�
        Store store;
        store.AddProduct(Product::Shampoo, 10);

        Customer customer;

        // ����
        bool isSuccess{ customer.Purchase(store, Product::Shampoo, 20) };

        // ����
        EXPECT_FALSE(isSuccess);
        EXPECT_EQ(0, customer.GetInventory(Product::Shampoo));
        EXPECT_EQ(10, store.GetProductCount(Product::Shampoo));    // ���⼭ �̰� �����ϴ°� �³�? sut�� customer�ε�
    }
}
