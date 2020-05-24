//Find the smallest window in a string containing all characters of another string
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int noc = 256; 


int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s,p;
    getline(cin,s);
    getline(cin,p);

    int l1 = s.length();
    int l2 = p.length();

    if(l1<l2){cout << "No String" << endl;return 0;}

    int hashs[noc] = {0}; 
    int hashp[noc] = {0}; 

    for(int i = 0;i <l2;i++){
        hashp[p[i]]++;
    }

    int count = 0;
    int start = 0, startindex = -1, minlen = INT_MAX;

    for(int i = 0;i<l1;i++){
        hashs[s[i]]++;

        if(hashp[s[i]]!=0 && hashs[s[i]] <= hashp[s[i]])count++;

        if(count == l2){

            while(hashp[s[start]] == 0 || hashs[s[start]] > hashp[s[start]]){

                if(hashs[s[start]] > hashp[s[start]]){
                    hashs[s[start]]--;

                }
                start++;
            }
            if(minlen > i - start +1){
                minlen = i - start +1;
                startindex = start;
            }
        }

    }

    if(startindex == -1){
        cout << "No String" << endl;
    }else{
        cout << s.substr(startindex,minlen) << endl;

    }



    

}
