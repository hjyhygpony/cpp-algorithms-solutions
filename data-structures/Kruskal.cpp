//构造非联通图ST(V,{});

//k=i=0；————k记录选中的边数
//while(k<n-1){
//	++i;
//	检查边集E中第i条权值最小的边(u,v);
//	若(u,v)加入ST后不使ST中产生回路，
//	则输出边(u,v);且k++；
//}

//

void Kruskal(Graph &G, Edge *&MST) {
	ParTree<int>A(G.VerticesNum());
	MinHeap<Edge>H(G.EdgeNum());//用最小堆来快速寻找边中的最小值
	MST = new

	for (int i = 0; i < G.VerticesNum(); i++) {
		for (Edge e = G.)
		}

	int EquNum = G.VerticesNum(); //刚开始有v个等价类
	while (EquNum > 1) {
		Edge e = H.RemoveMin();
		if (e.weight == INFINITY) {

		}

		int from = G.FromVertex(e);
		int to = G.ToVertex(e);
		if (A.differ(from, to)) {

		}
	}
}