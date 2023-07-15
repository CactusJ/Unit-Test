#pragma once

enum class Product;
class Store;

class Customer
{
public:
	bool Purchase(Store& store, const Product product, unsigned int count);

private:
};

