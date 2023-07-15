#pragma once
#include <map>

enum class Product
{
    None,
    Shampoo
};

class Store
{
public:
    Store();
    virtual ~Store() = default;

    bool Purchase(Product product, unsigned int count);
    void AddInventory(Product product, unsigned int count);
    int GetInventory(Product product);

private:
    std::map<Product, unsigned int> products_;

    bool HasProduct_(Product product, unsigned int count);
};