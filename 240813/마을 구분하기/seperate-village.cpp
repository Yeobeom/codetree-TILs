#include<iostream>
#include<cstring>
#include<algorithm>

int N;
constexpr int MAX_N = 25;
constexpr int WALL = 0;
constexpr int PERSON = 1;

int BOARD[MAX_N][MAX_N];
int VISITED[MAX_N][MAX_N];

int VILLAGE[MAX_N*MAX_N];
int VILLAGE_SIZE = 0;

int dfs(int y, int x)
{
	if(y < 0 || y >= N || x < 0 || x >= N || BOARD[y][x] == WALL || VISITED[y][x]) return 0;

    VISITED[y][x] = 1;

	return dfs(y-1,x) + dfs(y + 1, x) + dfs(y, x - 1) + dfs(y, x + 1) + 1;
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    
    std::cin >> N;
    for(int y = 0; y < N; y++) for(int x = 0; x < N; x++) std::cin >> BOARD[y][x];

    int answer = 0;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            if(BOARD[y][x] == PERSON && !VISITED[y][x])
			{
                VILLAGE[VILLAGE_SIZE++] = dfs(y,x);
			}
        }
    }
    std::sort(VILLAGE, VILLAGE + VILLAGE_SIZE);

    std::cout << VILLAGE_SIZE << '\n';
    for(int i = 0; i < VILLAGE_SIZE; i++) std::cout << VILLAGE[i] << '\n';

    return EXIT_SUCCESS;
}