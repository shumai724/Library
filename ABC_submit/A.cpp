#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N;
    cin >> N;
    bool ck = true;
    vector<string> S(N);
    rep(i,N)cin >> S[i];

    rep(i,N-1){
        if(S[i]==S[i+1] && S[i]=="sweet"){
            if(i != N-2)ck = false;
        }
    }

    if(ck)cout << "Yes" << "\n";
    else cout << "No" << "\n";



}
