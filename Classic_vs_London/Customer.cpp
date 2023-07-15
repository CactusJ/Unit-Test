#include "Customer.h"
#include "Store.h"

bool Customer::Purchase(Store& store, const Product product, unsigned int count)
{
	return store.Purchase(product, count);
}