void Prim(Graph &G, int s, Edge *&MST) {
	//初始化
	int MSTtag = 0;
	MST = new Edge[G.VerticesNum() - 1];
	Dist *D = new Dist[G.VerticesNum()];
	for (int i = 0; i < G.VerticesNum(); i++) {



	}

	int v = s;
	G.Mark[v] = VISITED;
	D[s].length = 0;
	for (i = 0; i < G.VerticesNum() - 1; i++) {
		if //非联通

		for (Edge e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)) {
				if (G.Mark[G.ToVertex(e)] == UNVISITED && (e.weight < D.ToVertex(e).length)
			}
}
}


int minVertex()