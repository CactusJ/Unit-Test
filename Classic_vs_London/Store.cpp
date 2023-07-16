#include "Store.h"
#include <Windows.h>

namespace classic
{
    Store::Store()
    {
        shelf.insert({ Product::Shampoo, 0 });
    }

    unsigned int Store::GetProductCount(Product product) const
    {
        return shelf.at(product);
    }

    void Store::AddProduct(Product product, unsigned int count)
    {
        shelf[product] += count;
    }

    bool Store::Purchase(Product product, unsigned int count)
    {
        if (!HasEnoughProduct_(product, count))
        {
            return false;
        }
        shelf[product] -= count;

        return true;
    }

    bool Store::HasEnoughProduct_(Product product, unsigned int count)
    {
        unsigned int productCountInStore{ shelf[product] };
        if (count <= productCountInStore)
        {
            return true;
        }

        return false;
    }
}

namespace london
{
    Store::Store()
    {
        shelf.insert({ Product::Shampoo, 0 });
    }

    unsigned int Store::GetProductCount(Product product) const
    {
        return shelf.at(product);
    }

    void Store::AddProduct(Product product, unsigned int count)
    {
        shelf[product] += count;
    }

    bool Store::Purchase(Product product, unsigned int count)
    {
        if (!HasEnoughProduct_(product, count))
        {
            return false;
        }
        shelf[product] -= count;

        return true;
    }

    bool Store::HasEnoughProduct_(Product product, unsigned int count)
    {
        unsigned int productCountInStore{ shelf[product] };
        if (count <= productCountInStore)
        {
            return true;
        }

        return false;
    }
}