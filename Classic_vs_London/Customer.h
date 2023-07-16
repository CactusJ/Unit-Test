#pragma once
#include "Store.h"

namespace classic
{
    class Customer
    {
    public:
        bool Purchase(Store& store, const Product product, unsigned int count);
        unsigned int GetInventory(const Product product) const;

    private:
        std::map<Product, unsigned int> inventory_;
    };
}

namespace london
{
    class Customer
    {
    public:
        bool Purchase(IStore& store, const Product product, unsigned int count);
        unsigned int GetInventory(const Product product) const;

    private:
        std::map<Product, unsigned int> inventory_;
    };
}