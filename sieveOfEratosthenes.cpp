#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int p[1000000];


void prime(int *p){

    p[2] = 1;
    p[0]=p[1]=0;

    for(int i =3;i < 1e6;i+=2){
        p[i] = 1;
    }

    for(ll i = 3;i< 1e6;i+=2){
        if(p[i] == 1){
            for(ll j = i*i;j< 1e6;j = j+i){
                p[j] =0;
            }
        }
    }

}


int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(p,0,sizeof(p));
    prime(p);

    
    
 

}
