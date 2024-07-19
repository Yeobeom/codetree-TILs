#include <iostream>
using namespace std;

int A[101];

static long long  Abs(long long  num)
{
    if(num < 0) return -num;
    return num;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> A[i];

    long long min = 0xFFFFFF;
    long long  sum = 0;

    for(long long  i = 0; i < n; i++)
    {
        sum = 0;
        for(long long  j = 0; j < n; j++)
        {
            sum += A[j] * Abs(j - i);
        }
        if(min >= sum) min = sum;
    }

    cout << min;

    return 0;
}