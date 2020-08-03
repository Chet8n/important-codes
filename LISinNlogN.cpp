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



void solve() {

    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    vi lis;
    lis.pb(a[0]);
    for(int i = 1;i < n;i++){
    	int index = lower_bound(all(lis),a[i]) - lis.begin();
    	if(index == lis.size()){
    		lis.pb(a[i]);
    	}else{
    		lis[index] = a[i];
    	}

    }
    cout << lis.size();

    
    
}


int32_t main()
{

    IOS

    //int T; cin >> T; while(T--)
    solve();
    return 0;


}
