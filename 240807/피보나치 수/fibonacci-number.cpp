#include <iostream>
using namespace std;

constexpr int MAX_N = 50;

int main() {
    int n;
    cin >> n;
    int dp[MAX_N] = {};

    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[n];
    return 0;
}