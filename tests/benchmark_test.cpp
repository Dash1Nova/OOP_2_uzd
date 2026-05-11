#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "../include/Vector.h"

using namespace std;
using namespace std::chrono;

void runTest(size_t sz)
{
    cout << "Size: " << sz << "\n";

    auto start1 = high_resolution_clock::now();

    std::vector<int> v1;
    for (size_t i = 0; i < sz; i++)
        v1.push_back(i);

    auto end1 = high_resolution_clock::now();

    auto timeStd = duration_cast<milliseconds>(end1 - start1).count();

    auto start2 = high_resolution_clock::now();

    Vector<int> v2;
    for (size_t i = 0; i < sz; i++)
        v2.push_back(i);

    auto end2 = high_resolution_clock::now();

    auto timeCustom = duration_cast<milliseconds>(end2 - start2).count();

    cout << "std::vector: " << timeStd << " ms\n";
    cout << "Vector: " << timeCustom << " ms\n";
    cout << "-----------------------------\n";
}

int main()
{
    runTest(10000);
    runTest(100000);
    runTest(1000000);
    runTest(10000000);
    runTest(100000000);
    return 0;
}