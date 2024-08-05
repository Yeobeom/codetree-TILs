#include<iostream>
#include<cstring>

int board[20][20];

std::pair<int, int> bombs[10];
int bombsCount;

int dy[3][4] = { {-1,-2,1,2},{-1,0,1,0},{-1,-1,1,1} };
int dx[3][4] = { {0,0,0,0},{0,1,0,-1},{-1,1,1,-1} };
int path[20];
int N;
int ans = 0;

void dfs(int lv)
{
    if (lv == bombsCount)
    {
        std::memset(board, 0, sizeof(board));
        for (int i = 0; i < bombsCount; i++)
        {
            int y = bombs[i].first;
            int x = bombs[i].second;
            board[y][x] = 1;
            for (int j = 0; j < 4; j++)
            {
                int ny = y + dy[path[i]][j];
                int nx = x + dx[path[i]][j];

                if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;

                board[ny][nx] = 1;
            }
        }

        int sum = 0;
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < N; x++)
            {
                sum += (board[y][x] == 1);
            }
        }
        if (ans < sum) ans = sum;
    }
    else
    {
        for (int i = 0; i < 3; i++)
        {
            path[lv] = i;
            dfs(lv + 1);
        }
    }
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cin >> N;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            std::cin >> board[y][x];
            if (board[y][x] == 1) bombs[bombsCount++] = { y,x };
        }
    }

    dfs(0);
    std::cout << ans;

    return EXIT_SUCCESS;
}