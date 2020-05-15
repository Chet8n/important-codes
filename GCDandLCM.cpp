#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int gcd(int a, int b){

    if(b == 0)return a;
    else{
        return gcd(b,a%b);
    }
}

int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}


int main()
 {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << gcd(5,4);
       
    
}
