#include<bits/stdc++.h>

constexpr int MAX_N = 200;
int vect[MAX_N][MAX_N];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            std::cin >> vect[y][x];
        }
    }

    int ret = 0;

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            if (y - 1 >= 0 && x - 1 >= 0)
            {
                int tmp = vect[y][x] + vect[y - 1][x] + vect[y][x - 1];
                ret = ret < tmp ? tmp : ret;
            }

            if (y - 1 >= 0 && x + 1 < m)
            {
                int tmp = vect[y][x] + vect[y - 1][x] + vect[y][x + 1];
                ret = ret < tmp ? tmp : ret;
            }

            if (y + 1 < n && x - 1 >= 0)
            {
                int tmp = vect[y][x] + vect[y + 1][x] + vect[y][x - 1];
                ret = ret < tmp ? tmp : ret;
            }

            if (y - 1 >= 0 && x + 1 < m)
            {
                int tmp = vect[y][x] + vect[y + 1][x] + vect[y][x + 1];
                ret = ret < tmp ? tmp : ret;
            }

            if (y + 2 < n)
            {
                int tmp = vect[y][x] + vect[y + 1][x] + vect[y + 2][x];
                ret = ret < tmp ? tmp : ret;
            }

            if (x + 2 < m)
            {
                int tmp = vect[y][x] + vect[y][x + 1] + vect[y][x + 2];
                ret = ret < tmp ? tmp : ret;
            }
        }
    }

    std::cout << ret;

    return EXIT_SUCCESS;
}