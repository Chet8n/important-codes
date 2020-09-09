#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
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
#define ar array
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mod = 1e9 + 7;
const ll inf = 2e9 + 5;
double PI = 3.14159265358979323846;

class Trie {
public:
    struct Node {
        Node* arr[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++) {
                arr[i] = NULL;
            }
            isEnd = false;
        }
    };

    char base = 'a';
    Node *root;
    Trie() {root = new Node(); }

    void insert (const string& s) {
        Node *cur = root;
        for (char ch : s) {
            if (!cur->arr[ch - base])
                cur->arr[ch - base] = new Node();
            cur = cur->arr[ch - base];
        }
        cur->isEnd = true;
    }

    bool search(const string& s) {
        Node *cur = root;
        for (char ch : s) {
            if (!cur->arr[ch - base])
                return false;
            cur = cur->arr[ch - base];
        }
        return (cur != NULL and cur->isEnd);
    }

};

void solve() {

	Trie t;
	t.insert("chethan");
	t.insert("dhoni");
	t.insert("kohli");
	t.insert("elon");
	t.insert("tourist");
	t.insert("benq");

	cout << t.search("tourist");

}

int32_t main()
{
	IOS
	// int T; cin >> T; while (T--)
	solve();
	return 0;
}
