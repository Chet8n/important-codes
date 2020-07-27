/*
Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once.
Find out the total number of ways in which friends can remain single or can be paired up.

Input Format
First line contains an integer t denoting the number of test cases. Next t lines contain an integer n each.

Constraints
1<= n < 30

Output Format
Output t lines each line describing the answer.

Sample Input
1
3
Sample Output
4
Explanation
{1}, {2}, {3} : all single
{1}, {2,3} : 2 and 3 paired but 1 is single. 
{1,2}, {3} : 1 and 2 are paired but 3 is single. 
{1,3}, {2} : 1 and 3 are paired but 2 is single. 
Note that {1,2} and {2,1} are considered same.

*/
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

ll n;
ll dp[100];

// Recursion / top down DP
ll rec(ll n) {

    if (n == 1 or n == 0)return 1;

    if (dp[n] != -1)return dp[n];

    //remain single
    ll op1 = rec(n - 1);

    // get paired with any of n-1 ppl;
    ll op2 = (n - 1) * rec(n - 2);

    return dp[n] = op1 + op2;


}

// Bottom up DP
ll BU() {

    dp[0] = dp[1] = 1;
    for(int i = 2;i <= n;i++){
        // dp[i] = ans if he remains single + ans if he gets paired with anyone else
        dp[i] = dp[i-1] + ((i-1)*dp[i-2]);
    }

   return dp[n];
}



void solve() {

    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << BU() << endl;


}


int32_t main()
{

    IOS

    int T; cin >> T; while (T--)
        solve();
    return 0;


}
