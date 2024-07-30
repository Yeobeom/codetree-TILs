#include<iostream>

constexpr int MAX_NM = 100;
constexpr int MAX_DIR = 4;
int MAP[MAX_NM][MAX_NM];
int TMPMAP[MAX_NM][MAX_NM];
int* TMPARR[MAX_NM * 4];
int N, M, Q;

int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

void shift(int r1, int c1, int r2, int c2)
{
	int idx = 0;
	for (int x = c1; x < c2; x++) TMPARR[idx++] = &MAP[r1][x];
	for (int y = r1; y < r2; y++) TMPARR[idx++] = &MAP[y][c2];
	for (int x = c2; x > c1; x--) TMPARR[idx++] = &MAP[r2][x];
	for (int y = r2; y > r1; y--) TMPARR[idx++] = &MAP[y][c1];

	int right = *TMPARR[idx - 1];
	for (int i = idx - 2; i >= 0; i--) *TMPARR[i + 1] = *TMPARR[i];
	*TMPARR[0] = right;

	for (int y = r1; y <= r2; y++)
	{
		for (int x = c1; x <= c2; x++)
		{
			int sum = MAP[y][x];
			int cnt = 1;
			for (int dir = 0; dir < MAX_DIR; dir++)
			{
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;

				sum += MAP[ny][nx];
				++cnt;
			}
			TMPMAP[y][x] = sum / cnt;
		}
	}
	for (int y = r1; y <= r2; y++)
	{
		for (int x = c1; x <= c2; x++)
		{
			MAP[y][x] = TMPMAP[y][x];
		}
	}

}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> N >> M >> Q;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			std::cin >> MAP[y][x];
		}
	}

	for (int i = 0; i < Q; i++)
	{
		int r1, c1, r2, c2;
		std::cin >> r1 >> c1 >> r2 >> c2;
		shift(r1 - 1, c1 - 1, r2 - 1, c2 - 1);
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			std::cout << MAP[y][x] << ' ';
		}
		std::cout << '\n';
	}

	return EXIT_SUCCESS;
}