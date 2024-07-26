#include<bits/stdc++.h>

using ll = long long int;

const int MAX_N = 1'000'000;

ll clients[MAX_N];
ll leader;
ll crew;

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    ll n;
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> clients[i];
    std::cin >> leader >> crew;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        clients[i] -= leader;
        ans += 1;
        if (clients[i] <= 0) continue;

        ans += 1 + clients[i] / crew;
    }

    std::cout << ans;
    return EXIT_SUCCESS;
}