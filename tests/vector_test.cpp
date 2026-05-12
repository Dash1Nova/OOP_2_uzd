#include <gtest/gtest.h>
#include "../include/vector.h"
#include <vector>
#include <iostream>

TEST(Vector, PushBack)
{
    std::vector<int> stdV;
    Vector<int> myV;

    for(int i = 0; i < 5; i++)
    {
        stdV.push_back(i);
        myV.push_back(i);
    }

    EXPECT_EQ(stdV.size(), myV.size());

    for(size_t i = 0; i < stdV.size(); i++)
    {
        EXPECT_EQ(stdV[i], myV[i]);
    }
}

TEST(Vector, PopBack)
{
    std::vector<int> stdV = {1,2,3,4};
    Vector<int> myV;

    for(int i = 1; i <= 4; i++)
        myV.push_back(i);

    stdV.pop_back();
    myV.pop_back();

    EXPECT_EQ(stdV.size(), myV.size());

    for(size_t i = 0; i < stdV.size(); i++)
        EXPECT_EQ(stdV[i], myV[i]);

    Vector<int> v;

    v.pop_back();

    EXPECT_EQ(v.size(), 0);
    EXPECT_TRUE(v.empty());
}

TEST(Vector, Insert)
{
    std::vector<int> stdV = {1,3};
    Vector<int> myV;

    myV.push_back(1);
    myV.push_back(3);

    stdV.insert(stdV.begin() + 1, 2);
    myV.insert(1, 2);

    EXPECT_EQ(stdV.size(), myV.size());

    for(size_t i = 0; i < stdV.size(); i++)
        EXPECT_EQ(stdV[i], myV[i]);
}

TEST(Vector, Erase)
{
    std::vector<int> stdV = {1,2,3,4};
    Vector<int> myV;

    for(int i = 1; i <= 4; i++)
        myV.push_back(i);

    stdV.erase(stdV.begin() + 1);
    myV.erase(1);

    EXPECT_EQ(stdV.size(), myV.size());

    for(size_t i = 0; i < stdV.size(); i++)
        EXPECT_EQ(stdV[i], myV[i]);

    Vector<int> v;
    v.push_back(1);

    ASSERT_THROW(v.erase(100), std::out_of_range);
}

TEST(Vector, Clear)
{
    std::vector<int> stdV = {1,2,3};
    Vector<int> myV;

    myV.push_back(1);
    myV.push_back(2);
    myV.push_back(3);

    stdV.clear();
    myV.clear();

    EXPECT_EQ(stdV.size(), myV.size());
    EXPECT_EQ(stdV.empty(), myV.empty());

    size_t capBefore = myV.capacity();
    myV.clear();
    EXPECT_EQ(myV.capacity(), capBefore);
}

TEST(Vector, Empty)
{
    std::vector<int> stdV;
    Vector<int> myV;

    EXPECT_EQ(stdV.empty(), myV.empty());

    stdV.push_back(1);
    myV.push_back(1);

    EXPECT_EQ(stdV.empty(), myV.empty());
}

TEST(Vector, Size)
{
    std::vector<int> stdV;
    Vector<int> myV;

    for(int i = 0; i < 10; i++)
    {
        stdV.push_back(i);
        myV.push_back(i);
    }

    EXPECT_EQ(stdV.size(), myV.size());
}

TEST(Vector, Resize)
{
    std::vector<int> stdV = {1,2};
    Vector<int> myV;

    myV.push_back(1);
    myV.push_back(2);

    stdV.resize(5);
    myV.resize(5);

    EXPECT_EQ(stdV.size(), myV.size());

    for(size_t i = 0; i < stdV.size(); i++)
        EXPECT_EQ(stdV[i], myV[i]);
}

TEST(Vector, Reserve)
{
    Vector<int> myV;
    myV.reserve(100);

    EXPECT_GE(myV.capacity(), 100);
}

TEST(Vector, FrontBack)
{
    std::vector<int> stdV = {10,20,30};
    Vector<int> myV;

    myV.push_back(10);
    myV.push_back(20);
    myV.push_back(30);

    EXPECT_EQ(stdV.front(), myV.front());
    EXPECT_EQ(stdV.back(), myV.back());

    Vector<int> v;

    ASSERT_THROW(v.front(), std::out_of_range);
    ASSERT_THROW(v.back(), std::out_of_range);
}

TEST(Vector, OperatorAccess)
{
    std::vector<int> stdV = {5,10,15};
    Vector<int> myV;

    myV.push_back(5);
    myV.push_back(10);
    myV.push_back(15);

    EXPECT_EQ(stdV[1], myV[1]);

    myV[1] = 100;
    EXPECT_EQ(myV[1], 100);
}

TEST(Vector, At)
{
    Vector<int> v;
    v.push_back(10);

    EXPECT_EQ(v.at(0), 10);

    ASSERT_THROW(v.at(5), std::out_of_range);
}

TEST(Vector, Iteration)
{
    std::vector<int> stdV = {1, 2, 3};
    Vector<int> myV;

    myV.push_back(1);
    myV.push_back(2);
    myV.push_back(3);

    EXPECT_EQ(stdV.size(), myV.size());

    auto it = myV.begin();

    for (size_t i = 0; i < stdV.size(); i++, ++it)
    {
        EXPECT_EQ(stdV[i], *it);
    }

    EXPECT_EQ(it, myV.end());
}

TEST(Vector, CopyConstructor) 
{
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    Vector<int> v2 = v1;

    EXPECT_EQ(v1.size(), v2.size()); 
    
    for (size_t i = 0; i < v1.size(); i++) 
        EXPECT_EQ(v1[i], v2[i]); 
}

TEST(Vector, CopyAssignment)
{
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    Vector<int> v2;
    v2 = v1;

    EXPECT_EQ(v1.size(), v2.size());

    for (size_t i = 0; i < v1.size(); i++)
        EXPECT_EQ(v1[i], v2[i]);
}

TEST(Vector, MoveConstructor)
{
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);

    Vector<int> v2 = std::move(v1);

    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2[0], 10);
    EXPECT_EQ(v2[1], 20);

    EXPECT_EQ(v1.size(), 0);
    EXPECT_TRUE(v1.empty());
}

TEST(Vector, MoveAssignment)
{
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    Vector<int> v2;
    v2 = std::move(v1);

    EXPECT_EQ(v2.size(), 2);
    for (size_t i = 0; i < v2.size(); i++)
        EXPECT_EQ(v2[i], i + 1);

    EXPECT_EQ(v1.size(), 0);
    EXPECT_TRUE(v1.empty());
}