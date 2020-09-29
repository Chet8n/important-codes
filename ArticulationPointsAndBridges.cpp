#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
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

const int N = 1e5+5;
vi g[N];
int n, m;
int disc[N], low[N], t = 1;
vi ap(N,0);
vector<pi> bridges;

void dfs(int u, int par) {

	disc[u] = low[u] = t++;
	int children = 0;

	for (auto v  : g[u]) {

		if (v == par)continue;
		if (!disc[v]) {

			dfs(v, u); children++;

			low[u] = min(low[u], low[v]);

			// articulation points:
			if (par and low[v] >= disc[u]) {
				ap[u] = 1;
			}

			// bridges:
			if (low[v] > disc[u]) {
				bridges.pb({u, v});
			}

		} else {
			low[u] = min(low[u], disc[v]);
		}

	}

	if (par == 0 and children >= 2) {
		ap.pb(u);
	}
}

void solve() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}

	dfs(1, 0);

	for (auto x : bridges) {
		cout << x.F << "-" << x.S << endl;
	}

}

int32_t main()
{
	IOS
	// int T; cin >> T; while (T--)
	solve();
	return 0;
}
