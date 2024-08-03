#include <iostream>
using namespace std;

int path[10];
int num[10];

int N,K;

void dfs(int lv)
{
    if(lv == K)
    {
        for(int i = 0; i < K; i++) cout << path[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        path[lv] = i;
        dfs(lv+1);
    }
}

int main() {
    cin >> N >> K;
    dfs(0);
    return 0;
}