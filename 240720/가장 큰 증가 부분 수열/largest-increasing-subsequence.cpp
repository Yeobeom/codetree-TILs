#include<bits/stdc++.h>

constexpr int MAX = 1000;

int seq[MAX + 1];
int dp[MAX + 1];

struct Compare
{
	bool operator()(const std::pair<int, int>& l, const std::pair<int, int>& r) const
	{
		if (l.first != r.first) return l.first < r.first;
		return l.second > r.second;
	}
}cmp;

int main(int argc, char** argv)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	int n;
	std::cin >> n;
	seq[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> seq[i];
	}

	int maxDist = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			// 만일 현재 인덱스 보다 이전 인덱스가 작다면
			if (seq[i] > seq[j])
			{
				if (dp[i] < dp[j] + seq[i])
				{
					dp[i] = dp[j] + seq[i];
				}
			}
		}
	}
	int maxSum = -1;
	for (int i = 1; i <= n; i++)
	{
		if (maxSum < dp[i]) maxSum = dp[i];
	}

	std::cout << maxSum;

	return EXIT_SUCCESS;
}