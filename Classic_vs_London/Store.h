#pragma once
#include <map>

enum class Product
{
    None,
    Shampoo
};

namespace classic
{
    class Store
    {
    public:
        Store();
        virtual ~Store() = default;

        bool Purchase(Product product, unsigned int count);
        void AddProduct(Product product, unsigned int count);
        unsigned int GetProductCount(Product product) const;

    private:
        std::map<Product, unsigned int> shelf;

        bool HasEnoughProduct_(Product product, unsigned int count);
    };
}

namespace london
{
    class IStore
    {
    public:
        virtual bool Purchase(Product product, unsigned int count) = 0;
        virtual void AddProduct(Product product, unsigned int count) = 0;
        virtual unsigned int GetProductCount(Product product) const = 0;
    };

    class Store : public IStore
    {
    public:
        Store();
        virtual ~Store() = default;

        bool Purchase(Product product, unsigned int count) override;
        void AddProduct(Product product, unsigned int count) override;
        unsigned int GetProductCount(Product product) const override;

    private:
        std::map<Product, unsigned int> shelf;

        bool HasEnoughProduct_(Product product, unsigned int count);
    };
}