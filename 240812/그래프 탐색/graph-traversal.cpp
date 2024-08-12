#include <iostream>
using namespace std;

int N,M;
int adj[1001][1001];
int visited[1001];

void dfs(int v)
{
    visited[v] = 1;

    for(int next : adj[v])
    {
        if(!visited[next]) dfs(next);
    }
}

int main() {
    cin >> N >> M;
    int u,v;
    for(int i = 0; i < M; i++)
    {
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    dfs(1);
    int cnt = 0;
    for (auto& v : visited)
    {
        cnt += v;
    }

    cout << cnt;

    return 0;
}