#pragma once
#include <map>

enum class Product
{
    Shampoo
};

class Store
{
public:
    Store();
    virtual ~Store() = default;

    virtual bool Purchase(Product product, unsigned int count);
    virtual void AddProduct(Product product, unsigned int count);
    virtual unsigned int GetProductCount(Product product) const;

private:
    std::map<Product, unsigned int> shelf;

    bool HasEnoughProduct_(Product product, unsigned int count);
};