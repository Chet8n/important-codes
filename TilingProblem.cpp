/*Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . A tile can either be placed horizontally or vertically.

Input Format
First line of input contains an integer T denoting the number of test cases. Then T test cases follow.
The first line of each test case contains two integers N and M.

Constraints
1 <= T<= 1000
1 <= N,M <= 100000

Output Format
Print answer for every test case in a new line modulo 10^9+7.

Sample Input
2
2 3
4 4
Sample Output
1
2
*/

//Solution:

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
const ll N = 100000;


ll dp[N+7];


void solve() {

	ll n,m;
	cin >> n >> m;
	memset(dp,0,sizeof(dp));
	dp[1] = dp[0] = 1;
	for(int i = 2;i <=n;i++){
		if(i>=m){
			dp[i] = (dp[i-1] + dp[i-m])%mod;
		}else{
			dp[i] = dp[i-1];
		}
	}

	cout << dp[n] << endl;

    
}


int32_t main()
{

    IOS

    int T; cin >> T; while(T--)
    solve();
    return 0;


}
