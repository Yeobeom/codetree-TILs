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

	int dpSize = 1;
	int sum = 0;
	int maxSum = 0;
	for (int i = 1; i <= n; i++)
	{
		int* it = std::lower_bound(dp, dp + dpSize, seq[i]);
		int idx = it - dp;
		if (idx >= dpSize)
		{
			dp[idx] = seq[i];
			sum += seq[i];
			dpSize++;
		}
		else
		{
			if (dp[idx] >= seq[idx]) continue;
			sum -= dp[idx];
			sum += seq[i];
			dp[idx] = seq[i];
		}
	}

	std::cout << sum;

	return EXIT_SUCCESS;
}