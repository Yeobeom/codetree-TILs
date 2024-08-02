#include<iostream>

int board[201][201];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n;
	std::cin >> n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			std::cin >> board[y][x];
		}
	}
	int r, c;
	std::cin >> r >> c;
	--r, --c;
	
	int dist = board[r][c];
	for (int i = 0; i < dist; i++)
	{
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = r + dy[dir] * i;
			int nx = c + dx[dir] * i;

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

			board[ny][nx] = 0;
		}
	}
	int tmp[201];
	int tmp_idx = 0;
	for (int x = 0; x < n; x++)
	{
		for (int i = 0; i < n; i++) tmp[i] = 0;
		tmp_idx = 0;
		for (int y = n - 1; y >= 0; y--)
		{
			if (board[y][x] == 0) continue;
			tmp[tmp_idx++] = board[y][x];
		}
		int y = n - 1;
		for (int i = 0; i < tmp_idx; i++)
		{
			board[y--][x] = tmp[i];
		}
		while (y >= 0) board[y--][x] = 0;
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			std::cout << board[y][x] << ' ';
		}
		std::cout << '\n';
	}

	return EXIT_SUCCESS;
}