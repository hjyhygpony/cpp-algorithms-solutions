#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

class Edge {
	public:
		int to, weight;
		Edge(int t, int w) : to(t), weight(w) {}
};

class Graph {
	public:
		int verticesNum;
		vector<Edge> edges[10005];
		int mark[10005];

		void addEdge(int from, int to, int weight) {
			edges[from].push_back(Edge(to, weight));
		}

		void reset() {
			fill(mark, mark + verticesNum, 0);
		}
};

class Dist {
	public:
		int index;
		int length;
		int pre;
};

int minVertex(Graph &G, Dist *D) {
	int minIndex = -1;
	int minDist = INF;
	for (int i = 0; i < G.verticesNum; i++) {
		if (G.mark[i] == 0 && D[i].length < minDist) {
			minDist = D[i].length;
			minIndex = i;
		}
	}
	return minIndex;
}

void getPath(int v, Dist *D, vector<int> &path) {
	if (v == -1)
		return;
	getPath(D[v].pre, D, path);
	path.push_back(v + 1);
}

void Dijkstra(Graph &G, int s) {
	Dist *D = new Dist[G.verticesNum];
	for (int i = 0; i < G.verticesNum; i++) {
		G.mark[i] = 0;
		D[i].index = i;
		D[i].length = INF;
		D[i].pre = -1;
	}
	D[s].length = 0;

	for (int i = 0; i < G.verticesNum; i++) {
		int v = minVertex(G, D);
		if (v == -1 || D[v].length == INF)
			break;
		G.mark[v] = 1;

		for (const Edge &e : G.edges[v]) {
			if (D[v].length + e.weight < D[e.to].length) {
				D[e.to].length = D[v].length + e.weight;
				D[e.to].pre = v;
			}
		}
	}

	for (int i = 0; i < G.verticesNum; i++) {
		cout << i + 1 << ": ";
		if (D[i].length == INF) {
			cout << "0;" << endl;
		} else {
			vector<int> path;
			getPath(i, D, path);
			cout << D[i].length << "; ";
			for (size_t j = 0; j < path.size(); j++) {
				if (j > 0)
					cout << " ";
				cout << path[j];
			}
			cout << endl;
		}
	}

	delete[] D;
}

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	Graph G;
	G.verticesNum = n;
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		G.addEdge(from - 1, to - 1, weight);
	}

	Dijkstra(G, s - 1);

	return 0;
}