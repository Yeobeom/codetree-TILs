#include<bits/stdc++.h>

constexpr int MAX = 10;
char board[MAX][MAX];

struct State {
    int rx, ry, bx, by, turn;
};

struct Node
{
    State state;
    Node* next;
} nodes[0x7fffff];

int node_count = 0;

char direction[4] = { 'L', 'R', 'U', 'D' };

Node* new_node(int rx = 0, int ry = 0, int bx = 0, int by = 0, int turn = 0)
{
    nodes[node_count].state = { rx, ry, bx, by, turn };
    nodes[node_count].next = nullptr;
    return &nodes[node_count++];
}

Node* new_node(State& state)
{
    nodes[node_count].state = state;
    nodes[node_count].next = nullptr;
    return &nodes[node_count++];
}

class Queue
{
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    void push(int rx, int ry, int bx, int by, int turn)
    {
        push(new_node(rx, ry, bx, by, turn));
    }

    void push(Node* node)
    {
        if (size == 0) head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
        }
        ++size;
    }

    Node* front() const
    {
        return head;
    }

    Node* back() const
    {
        return tail;
    }

    void pop()
    {
        if (size == 0) return;

        --size;
        head = head->next;
        if (head == nullptr) tail = nullptr;
    }

    bool empty() const { return size == 0; }

private:
    Node* head;
    Node* tail;
    unsigned int size;
};

bool inline move(int& y, int& x, char dir)
{
    if (dir == 'L')
    {
        if (board[y][x - 1] == '#') return true;
        --x;
        return false;
    }
    else if (dir == 'U')
    {
        if (board[y - 1][x] == '#') return true;
        --y;
        return false;
    }
    else if (dir == 'R')
    {
        if (board[y][x + 1] == '#') return true;
        ++x;
        return false;
    }
    else // dir == 'D'
    {
        if (board[y + 1][x] == '#') return true;
        ++y;     
        return false;
    }

}

bool Tilt(const int& cry, const int& crx, const int& cby, const int& cbx, const int& turn, char dir, Queue& q)
{
    int nry, nrx, nby, nbx;
    nrx = crx; nry = cry; nbx = cbx; nby = cby;
    while (true)
    {
        if (move(nry, nrx, dir)) break;
        if (board[nry][nrx] == 'O')
            break;
    }

    while (true)
    {
        if (move(nby, nbx, dir)) break;
        if (board[nby][nbx] == 'O')
            break;
    }

    // 만일 둘의 도착 위치가 같다면 서로 겹친다는 뜻이다.
     if (nby == nry && nbx == nrx)
    {
        // 만일 둘 다 구멍으로 빠지거나 이전 위치랑 같다면 의미 없다.
        if (board[nry][nrx] == 'O') return false;

        // 중요한건 먼저 도착하는 구슬의 위치는 변함이 없고, 뒤이어 도착한 구슬의 위치를 바꾼다는 것이다.
        // 만일 왼쪽으로 기울였는데 
        if (dir == 'L')
        {
            // 빨간 구슬이 더 왼쪽에 있었다면 빨간 구슬이 먼저 벽에 부딪치고 파란 구슬은 빨간 구슬 x 위치보다 +1 (즉 바로 오른쪽)에 있다.
            if (crx < cbx)
            {
                if (cbx == nbx + 1 && cby == nby && crx == nrx && cry == nry) return false;
                q.push(new_node(nrx, nry, nbx + 1, nby, turn));
            }
            // 빨간 구슬이 더 오른쪽에 있었다면 파란 구슬이 먼저 벽에 부딪치고 빨간 구슬은 파란 구슬 x 위치보다 + 1 (즉 바로 오른쪽)에 있다.
            else
            {
                if (cbx == nbx && cby == nby && crx == nrx + 1 && cry == nry) return false;
                q.push(new_node(nrx + 1, nry, nbx, nby, turn));
            }
        }

        // 만일 오른쪽으로 기울였는데
        else if (dir == 'R')
        {
            // 빨간 구슬이 더 왼쪽에 있었다면 파란 구슬이 먼저 벽에 부딪치고 빨간 구슬은 파란 구슬 바로 왼쪽에 있을 것이다. (-1 위치)
            if (crx < cbx)
            {
                if (cbx == nbx && cby == nby && crx == nrx - 1 && cry == nry) return false;

                q.push(new_node(nrx - 1, nry, nbx, nby, turn));
            }
            // 빨간 구슬이 더 오른쪽에 있었다면 빨간 구슬이 먼저 벽에 부딪치고 파란 구슬은 빨간 구슬 바로 왼쪽에 있을 것이다. (-1 위치)
            else
            {
                if (cbx == nbx - 1 && cby == nby && crx == nrx && cry == nry) return false;

                q.push(new_node(nrx, nry, nbx - 1, nby, turn));
            }
        }
        // 만일 위로 기울였는데
        else if (dir == 'U')
        {
            // 빨간 구슬이 더 위쪽에 있었다면 빨간 구슬이 먼저 벽에 부딪치고 파란 구슬은 빨간 구슬 바로 아래쪽에 있을 것이다. (+1 위치)
            if (cry < cby)
            {
                if (cbx == nbx && cby == nby + 1 && crx == nrx && cry == nry) return false;
                q.push(new_node(nrx, nry, nbx, nby + 1, turn));
            }
            // 빨간 구슬이 더 아래쪽에 있었다면 파란 구슬이 먼저 벽에 부딪치고 빨간 구슬은 파란 구슬 바로 아래쪽에 있을 것이다. (+1 위치)
            else
            {
                if (cbx == nbx && cby == nby && crx == nrx && cry == nry + 1) return false;
                q.push(new_node(nrx, nry + 1, nbx, nby, turn));
            }
        }
        // 만일 아래로 기울였는데
        else // dir == 'D'
        {
            // 빨간 구슬이 더 위쪽에 있었다면 파란 구슬이 먼저 벽에 부딪치고 빨간 구슬은 파란 구슬 바로 위쪽에 있을 것이다. (-1 위치)
            if (cry < cby)
            {
                if (cbx == nbx && cby == nby && crx == nrx && cry == nry - 1) return false;
                q.push(new_node(nrx, nry - 1, nbx, nby, turn));
            }
            // 빨간 구슬이 더 아래쪽에 있었다면 빨간 구슬이 먼저 벽에 부딪치고 파란 구슬은 빨간 구슬 바로 위쪽에 있을 것이다. (-1 위치)
            else
            {
                if (cbx == nbx && cby == nby - 1 && crx == nrx && cry == nry) return false;
                q.push(new_node(nrx, nry, nbx, nby - 1, turn));
            }
        }
    }
    // 만일 둘의 위치가 다르다면
    else
    {
        if(cbx == nbx && cby == nby && crx == nrx && cry == nry) return false;
        // 빨간 구슬이 구멍에 빠진다면 게임 끝
        if (board[nry][nrx] == 'O') return true;
        // 파란 구슬이 구멍에 빠진다면 넘어감
        if (board[nby][nbx] == 'O') return false;
        // 아니라면 그 상황을 큐에 넣는다.
        else
            q.push(new_node(nrx, nry, nbx, nby, turn));
    }
    // 안 빠졌다면 함수를 끝낸다.
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0), std:: cout.tie(0);

    int N, M;

    std::cin >> N >> M;

    State start;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            std::cin >> board[y][x];
            if (board[y][x] == 'R')
            {
                start.rx = x;
                start.ry = y;
            }
            if (board[y][x] == 'B')
            {
                start.bx = x;
                start.by = y;
            }
        }
    }
    start.turn = 0;
     
    Queue q;
    q.push(new_node(start));
    while (!q.empty())
    {
        Node* c = q.front();
        q.pop();
        int crx = c->state.rx;
        int cry = c->state.ry;
        int cbx = c->state.bx;
        int cby = c->state.by;
        int cturn = c->state.turn;

        
        if (cturn >= 10) break;
        ++cturn;
        for (auto& dir : direction)
        {
            if (Tilt(cry, crx, cby, cbx, cturn, dir, q))
            {
                std::cout << cturn;
                return EXIT_SUCCESS;
            }
        }
    }
    std::cout << -1;
    return EXIT_SUCCESS;    
}