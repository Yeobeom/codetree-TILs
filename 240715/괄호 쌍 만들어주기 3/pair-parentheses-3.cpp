#include <iostream>
using namespace std;

int main() {
    string str;
    std::cin >> str;
    int N = str.size(), cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            if(str[i] == '(' && str[j] == ')') cnt++;
        }
    }
    std::cout << cnt;
    return 0;
}