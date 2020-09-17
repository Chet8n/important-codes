// https://codeforces.com/problemset/problem/439/D

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

ll n, m;
vl a;
vl b;

ll get(ll x) {
	ll res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < x) {
			res += (x - a[i]);
		}
	}

	for (int i = 0; i < m; i++) {
		if (b[i] > x) {
			res += (b[i] - x);
		}
	}
	return res;
}


void solve() {

	cin >> n >> m;
	a = vl(n);
	b = vl(m);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	// you can notice that the function is convex:
	// try ternary search:

	ll s = 0;
	ll e = (ll)1e9 + 7;
	ll ans = 0;
	while (s + 2 <= e) {
		ll mid1 = (2 * s + e) / 3;
		ll mid2 = (s + 2 * e) / 3;
		if (get(mid1) <= get(mid2)) {
			e = mid2-1;
		} else {
			ans = mid1;
			s = mid1+1;
		}
	}


	cout << min({get(ans),get(ans+1), get(ans+2)});

}

int32_t main()
{
	IOS
	// int T; cin >> T; while (T--)
	solve();
	return 0;
}
