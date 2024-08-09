#include<bits/stdc++.h>

template<typename T>
void safe_delete(T& obj)
{
	if (obj) {
		delete obj;
		obj = nullptr;
	}
}

template<typename T>
struct Node {
	T value;
	bool visited;
	std::vector<Node*> neighbors;
	Node(T _value) : value(_value), visited(false) {};
};

template<typename T>
class Tree {
private:
	std::vector<Node<T>*> nodes;
	std::vector<T> log;
	void search(Node<T>*,int);
public:
	Tree() {};
	~Tree() {
		for (auto it : nodes)
			safe_delete(it);
		log.clear();
	};
	void insert(T);
	void search(int);
	void show() const;
};

template<typename T>
void Tree<T>::search(int height) {
	int max_height = nodes.size();	// 최대 도달 깊이 점검
	if (max_height == 0 || height < 0)
		return;
	else if (max_height < height)
		height = max_height;
	for(auto it : nodes)
		search(it, height-1);
}

template<typename T>
void Tree<T>::search(Node<T>* node, int height) {
	
	if (node->visited)
		return;			// 방문한 노드면 return
	else {
		node->visited = true;			// 방문체크
		log.push_back(node->value);		// log에 value 삽입

		if (height == 0) {				// 도달할 깊이에 도달함
			for (const auto& it : log)
				std::cout << it << ' ';	// 방문한 값들 나열
				std::cout << '\n';
		}
		else {
			for (auto it : node->neighbors)
				if(it->value >= node->value)
					search(it, height - 1);
		}
		node->visited = false;
		log.pop_back();
		return;
	}
}

template<typename T>
void Tree<T>::show() const {
	for (auto it : nodes)
		std::cout << it.value << ' ';
}

template<typename T>
void Tree<T>::insert(T _value) {
	Node<T>* node = new Node<T>(_value);

	for (auto it : nodes) {
		node->neighbors.push_back(it);
		it->neighbors.push_back(node);
	}
	nodes.push_back(node);
}

int main() {
	// cin 최적화 (scanf와 다른 독립된 버퍼만을 사용)
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Tree<int> tree;
	int N, M;
	std::cin >> N >> M;
	for (int i = 0; i != N; i++)
		tree.insert(i + 1);
	tree.search(M);

	return EXIT_SUCCESS;
}