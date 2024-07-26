#include<bits/stdc++.h>

using int64 = long long;


constexpr int64 INF = 0xFFFFFFFFFFFFFF;

int64 num[11];
int64 op[3];

static inline int64 Max(int64 a, int64 b) { return a > b ? a : b; }
static inline int64 Min(int64 a, int64 b) { return a < b ? a : b; }

std::pair<int64,int64> dfs(int level, int target, int64 sum)
{
    if (level == target) return { sum,sum };

    std::pair<int64, int64> ret1, ret2, ret3, ret4;
    ret1 = ret2 = ret3 = ret4 = { -INF,INF };

    if (op[0] > 0) {
        --op[0];
        ret1 = dfs(level + 1, target, sum + num[level]);
		++op[0];
	}
    if (op[1] > 0) {
		--op[1];
        ret2 = dfs(level + 1, target, sum - num[level]);
		++op[1];
	}
    if (op[2] > 0) {
        --op[2];
        ret3 = dfs(level + 1, target, sum * num[level]);
        ++op[2];
    }
    return { Max(ret4.first,Max(ret3.first,Max(ret1.first,ret2.first))), Min(ret4.second,Min(ret3.second,Min(ret1.second,ret2.second))) };
}

int main(int argc, char** argv) {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std:: cout.tie(0);

    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) std::cin >> num[i];
    for (int i = 0; i < 4; ++i) std::cin >> op[i];

    std::pair<int64,int64> ans = dfs(1, N, num[0]);

    std::cout << ans.second << ' '<< ans.first;

    return EXIT_SUCCESS;    
}