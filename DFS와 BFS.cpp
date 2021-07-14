#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>v[10005];
queue<int>q;
bool visited_dfs[1005];
bool visited_bfs[1005];

void DFS(int V) {
	visited_dfs[V] = true;
	cout << V << " ";

	for (int i = 0; i < v[V].size(); i++) {
		if (visited_dfs[v[V][i]] != true) {
			DFS(v[V][i]);
		}
	}
}
void BFS(int V) {
	q.push(V);
	visited_bfs[V] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 0; i < v[now].size(); i++) {
			if (visited_bfs[v[now][i]] != true){
				q.push(v[now][i]);
				visited_bfs[v[now][i]] = true;
			}
		}
	}
}

int main() {
	int N, M, V; //���� ����, ���� ����, Ž�� ���� ����
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);	//�����
	}

	for (int i = 0; i < M; i++) {
		sort(v[i].begin(), v[i].end());	//���� ��ȣ ���� �ͺ���
	}

	DFS(V);
	cout << "\n";
	BFS(V);

	return 0;
}