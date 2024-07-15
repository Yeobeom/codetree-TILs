#include <iostream>
using namespace std;

constexpr int MAX_N = 100002;
int parent[MAX_N];

int main() {
    int n, s, e;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        std::cin >> s >> e;
        parent[e] = s;
    }

    for(int i = 2; i <= n; ++i)
    {
        std::cout << parent[i] << '\n';
    }
    return 0;
}