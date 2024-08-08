#include <iostream>
using namespace std;

int dp[1001];

int main() {
    int n;
    std::cin >> n;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;
    for(int i = 5; i <= 1000; i++)
    {
        dp[i] = (dp[i - 2] + dp[i - 3])%10007;
    }

    std::cout << dp[n];
    return 0;
}