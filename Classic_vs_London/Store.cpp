#include "Store.h"
#include <Windows.h>

Store::Store()
{
    products_.insert({Product::Shampoo, 0});
}

int Store::GetInventory(Product product)
{
    return products_[product];
}

void Store::AddInventory(Product product, unsigned int count)
{
    products_[product] += count;
}

bool Store::Purchase(Product product, unsigned int count)
{
    if (!HasProduct_(product, count))
    {
        return false;
    }
    products_[product] -= count;
    
    return true;
}

bool Store::HasProduct_(Product product, unsigned int count)
{
    unsigned int productCountInStore{ products_[product] };
    if (count <= productCountInStore)
    {
        return true;
    }
    
    return false;
}