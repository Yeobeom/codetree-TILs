#include<iostream>

constexpr int MAX_N = 101;
int N;
int BOARD[MAX_N][MAX_N];
int* TMP[MAX_N*MAX_N + 1];
int TMP_IDX;
int r, c, m1, m2, m3, m4, dir;

// 우상, 좌상, 좌하, 우하
int dy[] = {-1,-1,1,1};
int dx[] = {1,-1,-1,1};

void roll(int& y, int& x, int& M, int& d)
{
	for (int i = 0; i < M; i++)
	{
		y += dy[d];
		x += dx[d];
		TMP[TMP_IDX++] = &BOARD[y][x];
	}
}

void shift()
{
	int dxy = 0;
	int y = r;
	int x = c;

	roll(y, x, m1, dxy);
	++dxy;
	roll(y, x, m2, dxy);
	++dxy;
	roll(y, x, m3, dxy);
	++dxy;
	roll(y, x, m4, dxy);

	if (dir == 1)
	{
		int left = *TMP[0];
		for (int i = 0; i < TMP_IDX - 1; i++) *TMP[i] = *TMP[i + 1];
		*TMP[TMP_IDX - 1] = left;
	}
	else
	{
		int right = *TMP[TMP_IDX - 1];
		for (int i = TMP_IDX - 1; i > 0; i--) *TMP[i] = *TMP[i - 1];
		*TMP[0] = right;
	}
}

void show()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			std::cout << BOARD[y][x] << ' ';
		}
		std::cout << '\n';
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
			std::cin >> BOARD[y][x];
		}
	}

	std::cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
	--r; --c;
	shift();
	show();
	return EXIT_SUCCESS;
}