#include<bits/stdc++.h>

constexpr int MAX = 1000;

std::pair<int,int> seq[MAX + 1];
int dp[MAX + 1][2];

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
	seq[0] = { 0,0 };
	for (int i = 1; i <= n; i++)
	{
		std::cin >> seq[i].first;
		seq[i].second = i;
	}

	std::sort(seq, seq + n + 1, cmp);

	int maxDist = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			// 만일 현재 인덱스 보다 이전 인덱스가 작다면
			if (seq[i].second > seq[j].second)
			{
				if (dp[i][0] < dp[j][0] + 1)
				{
					dp[i][0] = dp[j][0] + 1;
					dp[i][1] = seq[i].first + dp[j][1];
				}
				if (maxDist < dp[i][0]) maxDist = dp[i][0];
			}
		}
	}
	int maxSum = -1;
	for (int i = 1; i <= n; i++)
	{
		if (dp[i][0] == maxDist)
		{
			if (dp[i][1] > maxSum) maxSum = dp[i][1];
		}
	}



	std::cout << maxSum;

	return EXIT_SUCCESS;
}