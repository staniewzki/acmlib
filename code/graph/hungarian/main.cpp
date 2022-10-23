/*
 * Opis: Dla macierzy wag (mogą być ujemne) między dwoma warstami o rozmiarach n0 oraz n1 (n0 <= n1) wyznacza minimalną sumę wag skojarzenia pełnego.
 * Zwraca sumę wag oraz matching.
 * Czas: O(n_0^2\cdot n_1)
 */

pair<LL, vector<int>> hungarian(vector<vector<int>> a) {
	if(a.empty())
		return {0, {}};
	int n = ssize(a) + 1, m = ssize(a[0]) + 1;
	vector<int> p(m), ans(n - 1);
	vector<LL> u(n), v(m);
	FOR(i, 1, n - 1) {
		p[0] = i;
		int j0 = 0;
		vector<LL> dist(m, numeric_limits<LL>::max());
		vector<int> pre(m, -1);
		vector<bool> done(m + 1);
		do {
			done[j0] = true;
			int i0 = p[j0], j1 = -1;
			LL delta = numeric_limits<LL>::max();
			FOR(j, 1, m - 1) 
				if(!done[j]) {
					auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
					if(cur < dist[j])
						dist[j] = cur, pre[j] = j0;
					if(dist[j] < delta)
						delta = dist[j], j1 = j;
				}
			REP(j, m) {
				if(done[j])
					u[p[j]] += delta, v[j] -= delta;
				else
					dist[j] -= delta;
			}
			j0 = j1;
		} while(p[j0]);
		while(j0) {
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	FOR(j, 1, m - 1)
		if(p[j]) 
			ans[p[j] - 1] = j - 1;
	return {-v[0], ans};
}