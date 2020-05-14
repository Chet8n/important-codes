#include<bits/stdc++.h>
using namespace std;

int knapsack(int *w, int *v,int n, int x){

    int dp[n+1][x+1];

    for(int i = 0; i < n+1; i++){
        dp[i][0] = 0;
    }

    for(int j = 1; j < x+1; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i< n+1; i++){
        for(int j =1; j< x+1; j++){

            if(w[i-1]<=j){
                dp[i][j] = max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }

        }
    }
    return dp[n][x];

}




int main()
{

  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >>t;
  while(t--){

    int n;
    cin >> n;
    int x;
    cin >> x;
    int w[n],v[n];
    for(int i = 0; i<n; i++)
        cin>>v[i];
    for(int i = 0; i<n; i++)
        cin>>w[i];

    cout << knapsack(w,v,n,x) << endl;


  }




}
