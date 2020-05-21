#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int arr[500] = {0};

void solve(){

    int n;
    cin >> n;
    int index = 0;
    int flag = n;
    int m = 0;
    while(flag){

        arr[index] = flag%10;
        flag = flag/10;
        index++;
        m++;

    }
    int temp = 0;
    int x = 0;
    index = 0;

    for(int i = 2;i <n;i++){

        temp = 0;
        for(index = 0;index < m;index++){
            x = arr[index]*i + temp;
            arr[index] = x%10;
            temp = x/10;
        }

        while(temp){
            arr[index] = temp%10;
            temp = temp/10;
            index++;
            m++;
        }
    }

    for(int i = m-1;i >=0;i--){
        cout << arr[i] ;
    }


}


int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }




    

}
