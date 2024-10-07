#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k,n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    bool ck = false;

    rep(i,0,N-2){
        if(S[i]==S[i+1] && S[i+1]==S[i+2])ck = true;


    }

    if(ck)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
    

}