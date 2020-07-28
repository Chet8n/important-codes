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

int n, m;
const int N = 1007;

int sol[N][N] = {0};
char maze[N][N];
bool visited[N][N] = {0};

bool ratInMaze(int i, int j,int m, int n) {
	// base:

	//cout << i << " " << j << endl;
	if (i == m and j == n) {
		// print sol:
		sol[i][j] = 1;
		for (int ii = 0; ii <= m; ii++) {
			for (int jj = 0; jj <= n; jj++) {
				cout << sol[ii][jj] << " ";
			} cout << endl;
		}
		cout << endl;

		return true;
	}

	if (visited[i][j])return false;

	visited[i][j] = 1;
	sol[i][j] = 1;
	if (j + 1 <= n and maze[i][j + 1] != 'X') {
		bool right = ratInMaze(i, j + 1,m,n);
		if (right) {
			return true;
		}
	}
	if (i + 1 <= m and maze[i + 1][j] != 'X') {
		bool down = ratInMaze(i + 1, j,m,n);
		if (down) {
			return true;
		}
	}
	sol[i][j] = 0;
	return false;
}



void solve() {

	

	cin >> m;
	cin >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
			
		}
	}
	
	bool ans = ratInMaze(0, 0,m-1,n-1);

	if(!ans)cout << -1 << endl;
	

}


int32_t main()
{

	IOS

	//int T; cin >> T; while(T--)
	solve();
	return 0;


}
