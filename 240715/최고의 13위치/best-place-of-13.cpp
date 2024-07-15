#include <iostream>
using namespace std;

constexpr int MAX_N = 20;
int board[MAX_N][MAX_N];

int main() {
    int N;
    std::cin >> N;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            std::cin >> board[y][x];
        }
    }
    int max = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N - 2; x++)
        {
            int sum = board[y][x] + board[y][x + 1] + board[y][x + 2];
            if (sum > max) max = sum;
        }
    }
    std::cout << max;
    return 0;
}