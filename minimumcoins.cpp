#include<bits/stdc++.h>
using namespace std;

int ab(int *a, int n, int x){

	int dp[x+1];

	dp[0] = 0;

	
	int subp;

	for(int i = 1; i < x+1; i++){
		dp[i] = INT_MAX;
		for(int j = 0; j < n; j++){
			if(i-a[j] >= 0){
				subp = dp[i-a[j]];
				if(subp != INT_MAX && subp+1 < dp[i])
					dp[i] = 1+ subp;


			}			
		}
			
	}

	
	return dp[x] == INT_MAX?-1:dp[x];
}



int main()
 {

 	ios::sync_with_stdio(0);
	cin.tie(0);

	 int t;
    cin >> t;
    while(t--){

        int x;
        cin >> x;
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i< n;i++){

            cin >> a[i];
        }
        
        
        cout << ab(a,n,x) << endl;
    }
    
	
    
}
