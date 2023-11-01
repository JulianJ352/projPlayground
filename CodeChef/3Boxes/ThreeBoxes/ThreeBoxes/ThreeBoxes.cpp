// ThreeBoxes.cpp

#include <iostream>
#include <cstdlib>
using namespace std;

int boxCounter(int a, int b, int c, int d)
{
    int remainingStorage;
    int boxCount = 0;
    remainingStorage = a + b + c - d;
    boxCount++;
    if (remainingStorage <= 0)
    {
        
        return boxCount;
    }
    else
    {
        while (remainingStorage > 0)
        {
            remainingStorage -= d;
            boxCount++;
        }
        return boxCount;
    }
    return -1;
}
int main()
{
    int testCases, A, B, C, D;
    cin >> testCases;
    for (testCases; testCases > 0; testCases--)
    {
        cin >> A >> B >> C >> D;
        cout << boxCounter(A, B, C, D) << endl;
    }


    return 0;
}

