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
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

const int mxn = 10000;
int a[mxn];
int bit[mxn] = {0};

// Range sum query:
void update(int i, int inc, int N) {

    while (i <= N) {
        bit[i] += inc;
        i += (i & (-i));
    }
}

int query(int i) {
    int ans = 0;
    while (i > 0) {
        ans += bit[i];
        i -= (i & (-i));
    }
    return ans;
}

void solve() {

    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        update(i, a[i], n);
    }

    int ans = query(4);
    // query(l,r) = query(r)-query(l-1);
    cout << ans << endl;

}

int32_t main()
{
    IOS
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
