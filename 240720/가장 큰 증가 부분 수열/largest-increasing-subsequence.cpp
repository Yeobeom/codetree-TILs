#include<bits/stdc++.h>

constexpr int MAX = 1000;

std::pair<int,int> seq[MAX];
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
	for (int i = 0; i < n; i++)
	{
		std::cin >> seq[i].first;
		seq[i].second = i;
	}

	std::sort(seq, seq + n, cmp);

	int maxDist = 0;
	for (int i = 0; i < n; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = -1;
		for (int j = i - 1; j >= 0; --j)
		{
			// 만일 현재 인덱스 보다 이전 인덱스가 작다면
			if (seq[i].second > seq[j].second)
			{
				// 만일 현재 인덱스와 이전 인덱스를 추가한 길이가 현재 인덱스를 포함한 다른 길이보다 길다면
				if (dp[i][0] < dp[j][0] + 1)
				{
					dp[i][0] = dp[j][0] + 1;
					if (maxDist < dp[i][0]) maxDist = dp[i][0];
					dp[i][1] = j;
				}
			}
		}
	}

	int maxSum = -1;

	for (int i = n - 1; i >= 0; --i)
	{
		if (dp[i][0] == maxDist)
		{
			int next = dp[i][1];
			int sum = seq[i].first;
			while (next > -1)
			{
				sum += seq[next].first;
				next = dp[next][1];
			}
			if (maxSum < sum) maxSum = sum;
		}
	}

	std::cout << maxSum;

	return EXIT_SUCCESS;
}