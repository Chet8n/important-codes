/*A knight is a piece used in the game of chess. The chessboard itself is square array of cells. Each time a knight moves, its resulting position is two rows and one column, or two columns and one row away from its starting position. Thus a knight starting on row r, column c – which we’ll denote as (r,c) – can move to any of the squares (r-2,c-1), (r-2,c+1), (r-1,c-2), (r-1,c+2), (r+1,c-2), (r+1,c+2), (r+2,c-1), or (r+2,c+1). Of course, the knight may not move to any square that is not on the board.

Suppose the chessboard is not square, but instead has rows with variable numbers of columns, and with each row offset zero or more columns to the right of the row above it. The figure to the left illustrates one possible configuration. How many of the squares in such a modified chessboard can a knight, starting in the upper left square (marked with an asterisk), not reach in any number of moves without resting in any square more than once? Minimize this number.

If necessary, the knight is permitted to pass over regions that are outside the borders of the modified chessboard, but as usual, it can only move to squares that are within the borders of the board.

Input Format
First line contains an integer n, representing the side of square of chess board. The next n line contains n integers separated by single spaces in which jjth integer is 1 if that cell(i,j) is part of chessboard and 0 otherwise.

Constraints
The maximum dimensions of the board will be 10 rows and 10 columns. That is, any modified chessboard specified by the input will fit completely on a 10 row, 10 column board.

Output Format
Print the minimum number of squares that the knight can not reach.

Sample Input
3
1 1 1
1 1 1
1 1 1
Sample Output
1

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
int board[15][15] = {0};
int filled = 0;

void go(int i, int j, int count){
    if(i<0 or i >9 or j<0 or j>9 or board[i][j] == 0){
        return;
    }

    board[i][j] = 0; // unset the current cell;

    filled = max(filled,count);

    // try all possible 8 moves:
    go(i-1,j-2,count+1);
    go(i-2,j-1,count+1);
    go(i+1,j-2,count+1);
    go(i+2,j-1,count+1);
    go(i-1,j+2,count+1);
    go(i-2,j+1,count+1);
    go(i+1,j+2,count+1);
    go(i+2,j+1,count+1);

    //Backtrack:
    board[i][j] = 1;

}



void solve() {

    cin >> n;
    int tot = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin >> board[i][j];
            if(board[i][j])tot++;
        }
    }

    go(0,0,1);
    cout << tot - filled;

    
}


int32_t main()
{

    IOS

    //int T; cin >> T; while(T--)
    solve();
    return 0;


}
