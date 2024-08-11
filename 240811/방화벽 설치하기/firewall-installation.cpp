#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

constexpr int FIRE = 2;
constexpr int FIREWALL = 1;
constexpr int VOID = 0;
int n, m;
int ans;
int BOARD[8 * 8 + 1];
int TMPBOARD[8 * 8 + 1];
int VISITED[8 * 8 + 1];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

std::queue<int> q;

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    
    std::cin >> n >> m;
    int nm = n * m;
    ans = 0;
    for (int i = 0; i < nm; i++) std::cin >> BOARD[i];

    for (int i = 0; i < nm; i++)
    {
        if (BOARD[i] == VOID)
        {
            BOARD[i] = FIREWALL;
            for (int j = i + 1; j < nm; j++)
            {
                if (BOARD[j] == VOID)
                {
                    BOARD[j] = FIREWALL;

                    for (int k = j + 1; k < nm; k++)
                    {
                        if (BOARD[k] == VOID)
                        {
                            BOARD[k] = FIREWALL;

                            std::memset(VISITED, 0, sizeof(VISITED));
                            std::memcpy(TMPBOARD, BOARD, sizeof(TMPBOARD));
                            // BFS
                            for (int yx = 0; yx < nm; yx++)
                            {
                                if (TMPBOARD[yx] == FIRE)
                                {
                                    VISITED[yx] = 1;
                                    q.emplace(yx);
                                    while (!q.empty())
                                    {
                                        int v = q.front();
                                        q.pop();
                                        int y = v / m;
                                        int x = v % m;
                                        for (int d = 0; d < 4; d++)
                                        {
                                            int ny = y + dy[d];
                                            int nx = x + dx[d];
                                            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                                            int nv = ny * m + nx;
                                            if (VISITED[nv] == 1 || TMPBOARD[nv] == FIREWALL) continue;
                                            if (TMPBOARD[nv] == VOID)
                                            {
                                                TMPBOARD[nv] = FIRE;
                                                VISITED[nv] == 1;
                                                q.emplace(nv);
                                            }
                                        }
                                    }
                                }
                            }

                            // Count
                            int cnt = 0;
                            for (int l = 0; l < nm; l++)
                            {
                                if (TMPBOARD[l] == VOID) cnt++;
                            }
                            if (ans < cnt) ans = cnt;

                            BOARD[k] = VOID;
                        }
                    }

                    BOARD[j] = VOID;
                }
            }
            BOARD[i] = VOID;
        }
    }

    std::cout << ans;

    return EXIT_SUCCESS;
}