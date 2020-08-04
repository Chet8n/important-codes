#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
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
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

struct dsu {

    vector<int> p;
    void init(int NN) {
        p.clear(); p.resize(NN);
        iota(p.begin(), p.end(), 0);
    }
    int get(int x) {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }
    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = max(x, y);
            p[y] = max(x, y);
        }
    }
};


void solve() {

    int n, m;
    cin >> n >> m;
    vvi edges(m);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        edges[i] = {w, x, y};
    }
    sort(all(edges));

    int ans = 0;

    dsu g;
    g.init(n);
    for(int i = 0;i < m;i++){
        int x = edges[i][1];
        int y = edges[i][2];
        int w = edges[i][0];

        if(g.get(x) != g.get(y)){
            cout << w << " " << x << " " << y << endl;
            g.unite(x,y);
            // you can also make graph:
            // g[x].pb(y);
            // g[y].pb(x);
            ans += w;
        }
    }
    cout << ans << endl;


}


int32_t main()
{

    IOS

    //int T; cin >> T; while(T--)
    solve();
    return 0;


}
