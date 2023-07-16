#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h> // nuget 설치 필요
#include "../Classic_vs_London/Store.h"

class MockStore : public Store
{
public:
    MOCK_METHOD(bool, Purchase, (Product product, unsigned int count));
    MOCK_METHOD(void, AddProduct, (Product product, unsigned int count));
    MOCK_METHOD(unsigned int, GetProductCount, (Product product), (const));
};