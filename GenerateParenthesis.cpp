/*

Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.

Input Format
Single line containing an integral value 'n'.

Constraints
1<=n<=11

Output Format
Print the balanced parentheses strings with every possible solution on new line.

Sample Input
2
Sample Output
()() 
(()) 


/*
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
string s;
vector<string> v;

void rec(int a, int b){

    if(a == n and b ==n){
        //process string
        v.pb(s);
    }

    if(a==b and a < n){
        s+='(';
        rec(a+1,b);
        s.pop_back();
    }else{
        if(a > b and a!= n){
            s+='(';
            rec(a+1,b);
            s.pop_back();
        }
        if(a > b){
            s+=')';
            rec(a,b+1);
            s.pop_back();
        }
    }
}



void solve() {

    
    cin >> n;
    rec(0,0);
    sort(all(v),greater<string>());
    for(auto x : v){
        cout << x << endl;
    }    
}


int32_t main()
{

    IOS

    //int T; cin >> T; while(T--)
    solve();
    return 0;


}
