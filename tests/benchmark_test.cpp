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

    size_t reallocStd = 0;
    size_t oldCapStd = v1.capacity();

    for (size_t i = 0; i < sz; i++)
    {
        v1.push_back(i);

        if (v1.capacity() != oldCapStd)
        {
            reallocStd++;
            oldCapStd = v1.capacity();
        }
    }

    auto end1 = high_resolution_clock::now();

    auto timeStd =
        duration_cast<milliseconds>(end1 - start1).count();

    auto start2 = high_resolution_clock::now();

    Vector<int> v2;

    size_t reallocCustom = 0;
    size_t oldCapCustom = v2.capacity();

    for (size_t i = 0; i < sz; i++)
    {
        v2.push_back(i);

        if (v2.capacity() != oldCapCustom)
        {
            reallocCustom++;
            oldCapCustom = v2.capacity();
        }
    }

    auto end2 = high_resolution_clock::now();

    auto timeCustom =
        duration_cast<milliseconds>(end2 - start2).count();

    cout << "std::vector:\n";
    cout << "Time: " << timeStd << " ms\n";
    cout << "Reallocations: " << reallocStd << "\n\n";

    cout << "Vector:\n";
    cout << "Time: " << timeCustom << " ms\n";
    cout << "Reallocations: " << reallocCustom << "\n";

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