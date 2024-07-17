#include<iostream>

constexpr int MAX_N = 21;

int mine[MAX_N][MAX_N];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	int n, m, goldCount;
	std::cin >> n >> m;
	
	goldCount = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			std::cin >> mine[y][x];
			goldCount += mine[y][x];
		}
	}
	int maxGold = 1;
	int k = 1;

	while ((k * k + (k + 1) * (k + 1)) <= (goldCount * m))
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				int currentGold = 0;
				int dx = 0;
				for (int yy = y - k; yy < y; yy++)
				{
					for (int xx = x - dx; xx <= x + dx; xx++)
					{
						if (yy < 0 || yy >= n || xx < 0 && xx >= n) continue;
						currentGold += mine[yy][xx];
					}
					dx++;
				}
				for (int xx = x - k; xx <= x + k; xx++)
				{
					if (y < 0 || y >= n || xx < 0 && xx >= n) continue;
					currentGold += mine[y][xx];
				}
				dx = 0;
				for (int yy = y + k; yy > y + k; yy--)
				{
					for (int xx = x - dx; xx <= x + dx; xx++)
					{
						if (yy < 0 || yy >= n || xx < 0 && xx >= n) continue;
						currentGold += mine[yy][xx];
					}
					dx++;
				}

				if (maxGold < currentGold) maxGold = currentGold;
			}
		}
		++k;
	}
	std::cout << maxGold;

	return EXIT_SUCCESS;
}