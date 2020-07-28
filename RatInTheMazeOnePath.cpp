/*
You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from position (i,j), down or right on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M). Find the rightmost path through which, rat can reach this position.
A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1), if there exists a path from (i,j+1) to (N,M).

Input Format
First line contains 2 integers, N and M, denoting the rows and columns in the grid. Next N line contains. 
M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.

Constraints
1<=N,M<=1000 GRID(i,j)='X' or 'O'

Output Format
If a solution exists: Print N lines, containing M integers each.
A 1 at a position (i,j) denotes that the (i,j)th cell is covered in the path and a 0 denotes that the cell is not covered in the path.
If solution doesn't exist, just print "-1".

Sample Input
5 4
OXOO
OOOX
OOXO
XOOO
XXOO
Sample Output
1 0 0 0 
1 1 0 0 
0 1 0 0 
0 1 1 1 
0 0 0 1 

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
