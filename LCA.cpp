#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

typedef pair<int, int> pi;

#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

const int N = 2e5 + 5;

vector<int> g[N];
int depth[N], up[N][20];

void dfs(int u, int par) {

	up[u][0] = par;

	for (int i = 1; i < 20; i++) {
		if (up[u][i - 1] != -1) {
			up[u][i] = up[up[u][i - 1]][i - 1];
		} else {
			up[u][i] = -1;
		}
	}

	for (auto v : g[u]) {
		if (v == par)continue;
		depth[v] = depth[u] + 1;
		dfs(v, u);
	}

}

int nancestor(int u, int k) {

	for (int i = 19; i >= 0 and k and u > 0; i--) {
		if (k & (1 << i)) {
			u = up[u][i];
			k -= (1 << i);
		}
	}
	return u;
}

int lca(int u, int v) {
	if (depth[u] > depth[v]) {
		swap(u, v);
	}

	v = nancestor(v, depth[v] - depth[u]);

	if (u == v)return u;
	for (int i = 19; i >= 0; i--) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}

	return up[u][0];

}

int n, q;

void solve() {

	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(1, -1);

	while (q--) {
		int u, v;
		cin >> u >> v;
		int dist = depth[u] + depth[v] - 2 * depth[lca(u, v)];
		cout << dist << endl;
	}



}

int32_t main()
{
	IOS
	// int T; cin >> T; while (T--)
	solve();
	return 0;
}
