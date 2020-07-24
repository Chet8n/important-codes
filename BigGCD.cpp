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


ll POW(ll a, ll b, ll m) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b = b >> 1;
	}
	return res;
}

ll multiplicativeInverse(ll k){
	return POW(k, mod-2, mod);
}

ll gcd(ll a, ll b){

	if(b == 0){
		return a;
	}

	return gcd(b, a%b);
}



void solve() {

	string m;
	ll n;
	cin >> n;
	cin >> m;
	if(n == 0){
		cout << m << endl;
		return;
	}
	ll len = m.length();
	ll y = 0;
	for(int i = 0;i < len;i++){
		ll dig = m[i] - '0';
		dig = dig%n;
		ll secondPart = POW(10,len-i-1,n);
		y = (y + (dig*secondPart)%n)%n;

	}

	cout << gcd(y,n);

}


int32_t main()
{

	IOS

	//int T; cin >> T; while(T--)
	solve();
	return 0;


}
