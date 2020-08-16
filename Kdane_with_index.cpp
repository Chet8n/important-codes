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


void solve() {

    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll meh = -inf;
    ll ans = -inf;
    ll s = -1;
    ll e = -1;
    ll start, end;
    start = end = -1;

    for (int i = 0; i < n; i++) {
        if (meh + a[i] >  a[i]) {
            meh = meh + a[i];
            e++;
        } else {
            meh = a[i];
            s = i;
            e = i;
        }

        if (meh > ans) {
            ans = meh;
            start = s;
            end = e;
        }
    }
    cout << start << " " << end << endl;


}

int32_t main()
{
    IOS
    // int T; cin >> T; while (T--)
    solve();
    return 0;
}
