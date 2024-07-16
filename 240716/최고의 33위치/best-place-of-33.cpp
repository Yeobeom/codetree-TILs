#include<bits/stdc++.h>

constexpr int MAX_N = 20;
int board[MAX_N][MAX_N];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int N;
    std::cin >> N;

    int ret = 0;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            std::cin >> board[y][x];
        }
    }

    for (int y = 0; y < N - 2; ++y)
    {
        for (int x = 0; x < N - 2; ++x)
        {
            int tmp = board[y][x] + board[y][x + 1] + board[y][x + 2] + board[y + 1][x] + board[y + 1][x + 1] + board[y + 1][x + 2]+board[y + 2][x] + board[y + 2][x + 1] + board[y + 2][x + 2];
            if (ret < tmp) ret = tmp;
        }
    }
    std::cout << ret;

    return EXIT_SUCCESS;
}