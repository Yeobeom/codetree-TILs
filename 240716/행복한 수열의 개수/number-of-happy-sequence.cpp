#include<bits/stdc++.h>

constexpr int MAX_N = 100;
int vect[MAX_N][MAX_N];

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            std::cin >> vect[y][x];
        }
    }

    int ans = 0;

    if (m == 1)
    {
        ans = 2 * n;
    }
    else
    {
        for (int y = 0; y < n; ++y)
        {
            int prev = vect[y][0];
            int cnt = 1;
            for (int x = 1; x < n; ++x)
            {
                if (prev != vect[y][x]) cnt = 1;
                else
                {
                    if (++cnt >= m)
                    {
                        ans++;
                        break;
                    }
                }

                prev = vect[y][x];
            }
        }

        for (int x = 0; x < n; ++x)
        {
            int prev = vect[0][x];
            int cnt = 1;
            for (int y = 1; y < n; ++y)
            {
                if (prev != vect[y][x]) cnt = 1;
                else
                {
                    if (++cnt >= m)
                    {
                        ans++;
                        break;
                    }
                }
                prev = vect[y][x];
            }
        }
    }



    std::cout << ans;

    return EXIT_SUCCESS;
}