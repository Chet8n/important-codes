/*
Take as input str, a string. Assume that value of a=1, b=2, c=3, d=4, …. z=26. 
Write a recursive function (return type Arraylist) to print all possible codes for the string.
E.g. for “1123” possible codes are aabc, kbc, alc, aaw, kw.

Input Format
Enter a number

Constraints
None

Output Format
Display all the possible codes

Sample Input
1125
Sample Output
[aabe, aay, ale, kbe, ky]
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

vector<string> v;
int n;
string k;
string s;

void rec(int i) {

	if (i > n) {
		//process string
		v.pb(k);
		return;
	}

	// picking only one char if you are in last pos
	if (i == n) {
		string temp = s.substr(i - 1, 1);
		char c = (char)('a' + stoi(temp) - 1);
		k += c;
		rec(i + 1);
		k.pop_back();
	}// 120 - in this case u cant pick 12,0 cause u'll be left with zero thus pick 1,20
	 else if (i + 2 <= n and s[i + 1] == '0') {
		string temp = s.substr(i - 1, 1);
		char c = (char)('a' + stoi(temp) - 1);
		k += c;
		rec(i + 1);
		k.pop_back();
	}
	else if (i + 1 <= n) {

		string temp = s.substr(i - 1, 2);
		// 20 - in such case pick 20, not 2,0
		if (temp <= "26" and temp[1] == '0') {
			char c = (char)('a' + stoi(temp) - 1);
			k += c;
			rec(i + 2);
			k.pop_back();
		}// 13 - in such case pick 1,3 and 13 if it is less than 26
		// if greater than 26 pick only single digits i,e for eg: 36 --> 3,6 not 36 
		else if (temp[1] != '0') {
			if (temp <= "26") {
				char c = (char)('a' + stoi(temp) - 1);
				k += c;
				rec(i + 2);
				k.pop_back();
			}

			string temp2 = s.substr(i - 1, 1);
			char cc = (char)('a' + stoi(temp2) - 1);
			k += cc;
			rec(i + 1);
			k.pop_back();


		}

	}
}

void solve() {


	cin >> s;
	n = s.length();
	rec(1);
	sort(all(v));

	cout << "[";

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
		if (i != v.size() - 1) {
			cout << ", ";
		}
	}
	cout << "]";


}


int32_t main()
{

	IOS

	//int T; cin >> T; while(T--)
	solve();
	return 0;


}
