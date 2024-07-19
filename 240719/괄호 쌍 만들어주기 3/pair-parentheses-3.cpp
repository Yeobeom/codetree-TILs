#include <iostream>
using namespace std;



int main() {
    string A;
    std::cin >> A;
    int cnt = 0;
    for(int i = 0; i < A.length(); i++)
    {
        if(A[i] == '(')
        {
        for(int j = i+1; j < A.length(); j++)
        {
            if(A[j] == ')') cnt++;
        }
        }
    }
    cout << cnt;
    return 0;
}