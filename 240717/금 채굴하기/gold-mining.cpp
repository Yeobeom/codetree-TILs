#include<iostream>

constexpr int MAX_N = 21;

int mine[MAX_N][MAX_N];

static int inline cost(int k)
{
	return (k * k + (k + 1) * (k + 1));
}

static bool inline IsRange(int y, int x, int& n)
{
	return y < n && y >= 0 && x < n && x >= 0;
}


// 마름모의 테두리를 훑어 금의 개수를 찾는 방법
// 각 꼭짓점을 기준으로 반 시계 방향으로 돈다고 생각하면 된다
// 위쪽 꼭짓점에서 (+1,-1) 방향 (좌하향)으로 k번 돌면
// k 크기의 마름모의 테두리를 훑게 된다.
int dy[] = { 1, 1, -1, -1 };
int dx[] = { -1,1, 1, -1 };
int sy[] = { -1,0, 1, 0 };
int sx[] = {0,-1, 0, 1 };

int GetGoldBorderCount(int y, int x, int& k, int& n)
{
	int ret = 0;
	for (int dir = 0; dir < 4; dir++)
	{
		int ty = y + sy[dir] * k;
		int tx = x + sx[dir] * k;
		for (int i = 0; i < k; i++)
		{
			if (IsRange(ty, tx, n)) ret += mine[ty][tx];
			ty += dy[dir];
			tx += dx[dir];
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;


	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			std::cin >> mine[y][x];
		}
	}

	// 최대로 돌아야 하는 K의 수
	// 마름모의 중심점이 격자 오른쪽 아래 끝점에 있다면 왼쪽 위 대각 끝점 까지 커버해야 한다.
	// k= {0,1} => 1 {2,3} => 2, {4,5} => 3 ... 이렇듯 2개씩 늘어나야 대각선 길이가 1 늘어나므로
	// 2*(n-1) 이 최대 K가 된다.
	int maxK = 2 * (n - 1);
	int maxGold = 0;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			int k = 1;
			int gold = mine[y][x];
			if (maxGold < gold) maxGold = gold;
			while (k <= maxK)
			{
				gold += GetGoldBorderCount(y, x, k, n);
				if (maxGold < gold && cost(k) <= gold*m) maxGold = gold;
				++k;
			}
		}
	}

	std::cout << maxGold;

	return EXIT_SUCCESS;
}