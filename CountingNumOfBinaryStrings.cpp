/*
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
Explanation
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101

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

int n;
ll dp[100][2];

ll rec(ll i, int prev){
    if(i > n)return 1;

    if(dp[i][prev]!=-1)return dp[i][prev];

    
    ll ans = 0;
    // if prev wasn't 1
    if(!prev){
        ll op1 = rec(i+1,1);
        ll op2 = rec(i+1,0);
        ans = ans + op1 + op2;
    }//if prev was 1
    else{
        ll op1 = rec(i+1,0);
        ans = ans + op1;
    }

    return dp[i][prev] = ans;


}



void solve() {

    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout << rec(1,0) << endl;
    
}


int32_t main()
{

    IOS

    int T; cin >> T; while(T--)
    solve();
    return 0;


}
