#include<iostream>

constexpr int MAX_N = 20;
int board[MAX_N][MAX_N];

int dy[] = {-1,-1,1,1};
int dx[] = {1,-1,-1,1};

static bool inline IsRange(int& y, int& x, int& n)
{
	return y >= 0 && y < n && x >= 0 && x < n;
}

int Calculate(int ty, int tx, int& width, int& height, int& n)
{
	int sum = 0;
	for (int i = 0; i < width; i++)
	{
		ty += dy[0];
		tx += dx[0];
		if (!IsRange(ty, tx, n)) return 0;
		sum += board[ty][tx];
	}
	for (int i = 0; i < height; i++)
	{
		ty += dy[1];
		tx += dx[1];
		if (!IsRange(ty, tx, n))  return 0;
		sum += board[ty][tx];
	}
	for (int i = 0; i < width; i++)
	{
		ty += dy[2];
		tx += dx[2];
		if (!IsRange(ty, tx, n)) return 0;
		sum += board[ty][tx];
	}
	for (int i = 0; i < height; i++)
	{
		ty += dy[3];
		tx += dx[3];
		if (!IsRange(ty, tx, n)) return 0;
		sum += board[ty][tx];
	}
	return sum;
}

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	int n;
	std::cin >> n;
	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			std::cin >> board[y][x];
		}
	}

	int maxLength = n;
	int maxSum = 0;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			for (int width = 1; width <= maxLength; width++)
			{
				for (int height = 1; height <= maxLength; height++)
				{
					int sum = Calculate(y, x, width, height, n);
					if (maxSum < sum) maxSum = sum;
				}
			}
		}
	}

	std::cout << maxSum;

	return EXIT_SUCCESS;
}