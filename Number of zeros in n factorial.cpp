#include <bits/stdc++.h>
using namespace std;

int trailingzeros(int n){
    int ans = 0;
    int p = 5;
    while((n/p) > 0){
        ans = ans + n/p;
        p = p*5;
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >>n;
    cout << trailingzeros(n) << endl;
}

