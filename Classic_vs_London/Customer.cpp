#include "Customer.h"
#include <system_error>

bool Customer::Purchase(Store& store, const Product product, unsigned int count)
{
    if (!store.Purchase(product, count))
    {
        return false;
    }

    inventory_[product] += count;
    return true;
}

unsigned int Customer::GetInventory(const Product product) const
{
    try
    {
        return inventory_.at(product);
    }
    catch (std::out_of_range)
    {
        return 0;
    }
}