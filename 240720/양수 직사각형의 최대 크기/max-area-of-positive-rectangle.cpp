#include<bits/stdc++.h>

constexpr int MAX = 20;
constexpr int MIN_VALUE = -0x7f7f7f;
int board[MAX][MAX];

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			std::cin >> board[y][x];
		}
	}

	int squaresSize = 0;
	bool isNegative;
	int maxArea = MIN_VALUE;
	for (int sy = 0; sy < n; sy++)
	{
		for (int sx = 0; sx < m; sx++)
		{
			for (int ey = sy; ey < n; ey++)
			{
				for (int ex = sx; ex < m; ex++)
				{
					isNegative = false;
					int area = 0;
					for (int ty = sy; ty <= ey; ty++)
					{
						for (int tx = sx; tx <= ex; tx++)
						{
							if (board[ty][tx] < 0)
							{
								isNegative = true;
								break;
							}
							area++;
						}
						if (isNegative) break;
					}
					if (!isNegative)
					{
						if (maxArea < area) maxArea = area;
					}
				}
			}
		}
	}

	if (maxArea == MIN_VALUE)
		std::cout << -1;
	else
		std::cout << maxArea;


	return EXIT_SUCCESS;
}