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

    EXPECT_TRUE(myV.capacity(), 100);
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
    std::vector<int> stdV = {1,2,3};
    Vector<int> myV;

    myV.push_back(1);
    myV.push_back(2);
    myV.push_back(3);

    int s1 = 0, s2 = 0;

    for(int x : stdV) s1 += x;

    for(auto it = myV.begin(); it != myV.end(); ++it)
        s2 += *it;

    EXPECT_EQ(s1, s2);
}