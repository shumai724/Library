#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N;
    string S;
    cin >> N >> S;
    int ans = 0 ;
    for(int i = 0 ; i < N-2; i++){
        if(S[i]=='#' && S[i+1] == '.' && S[i+2] == '#')ans++;
    }

    cout << ans << "\n";
    return 0;

}