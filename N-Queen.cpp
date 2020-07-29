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

int board[20][20];
int n;

bool isSafe(int i, int j) {

    for (int k = 0; k < i; k++) {
        if (board[k][j]) {
            return false;
        }
    }

    int x = i;
    int y = j;

    while (x >= 0 and y >= 0) {
        if (board[x][y])return false;
        x--; y--;

    }

    x = i;
    y = j;

    while (x >= 0 and y < n) {
        if (board[x][y])return false;
        x--; y++;

    }

    return true;


}

bool ok = false;
int cnt = 0;

bool NQueen(int i) {

    // base:
    if (i == n) {
        // print the board;
        // Uncomment to Print all possible boards

        for(int a = 0;a < n;a++){
            for(int b = 0;b < n;b++){
                cout << board[a][b];
            }cout << endl;
        }
        cout << endl;

        return true;


        
    }

    //Rrecurrsive Case:
    for (int j = 0; j < n; j++) {
        // place the queen
        if (isSafe(i, j)) {
            // place at i,j 
            board[i][j] = 1;
            bool next = NQueen(i+1);
            if(next){
                return true;
            }
            
            // cant place at i,j so backtrack:
            board[i][j] = 0;


        }
    }
    return false;
    
}



void solve() {

    memset(board,0, sizeof(board));
    cin >> n;
    bool pos = NQueen(0);
    //cout << pos;
    



}


int32_t main()
{

    IOS

    //int T; cin >> T; while (T--)
        solve();
    return 0;


}
