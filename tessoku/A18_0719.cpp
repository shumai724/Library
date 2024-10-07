#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())



int main(){
    int N,S;
    cin >> N >> S;
    

    bool dp[69][10009];

    dp[0][0] = true;

    for(int i = 1; i <= N; i++){
        int aa;
        cin >> aa;
        for(int j = 0; j <= S; j++){
            if(dp[i-1][j]==true)dp[i][j] = true;
            if( j >= aa && dp[i-1][j-aa]==true)dp[i][j] = true;
        }
    }

    if(dp[N][S]==true)cout << "Yes" << "\n";
    else cout << "No" << "\n"; 




}