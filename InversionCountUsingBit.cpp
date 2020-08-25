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



const ll mxn = 2e5+5;
vl a(mxn);
vl bit(mxn,0);
// can use any of methods:
// BIT
// PBDS or a set

void update(ll i, ll N) {
	while (i <= N) {
		bit[i] += 1;
		i += (i & (-i));
	}
}

ll query(ll i) {
	ll ans = 0;
	while (i > 0) {
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}



void solve() {

	ll n;
	cin >> n;
	ll ans = 0;
	set<ll> s;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(a[i]);
	}
	//co ordinate compression
	map<ll,ll> m;
	ll ind = 1;
	for(auto it : s){
		ll num = (it);
		m[num] = ind;
		ind++;
	}

	for (ll i = n; i >= 1; i--) {

		ans += query(m[a[i]] - 1);
		update(m[a[i]], mxn);
	}
	cout << ans << endl;

	
	for(int i = 0;i < mxn;i++){
		bit[i] = 0;
	}



}

int32_t main()
{
	IOS
	int T; cin >> T; while (T--)
		solve();
	return 0;
}
