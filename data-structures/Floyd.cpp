void Floyd(Graph &G, Dist** &D) {
	int i, j, k;
//

	for (k = 0; k < G.VerticesNum(); k++) {
		for (i = 0; i < G.VerticesNum(); i++) {
			for (j = 0; j < G.VerticesNum(); j++) {
				if (D[i][j].length > (D[i][k].length + D[k][j].length)) {
					D[i][j].length = D[i][k].length + D[k][j].length;
					D[i][j].pre = D[k][j].pre;
				}
			}
		}
	}

}