#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> A(H,vector<char>(W));

    rep(i,H)rep(j,W)cin >> A[i][j];

    vector<vector<ll>> dp(H+1,vector<ll>(W+1,0));

    ll MOD = 1e9+7;
    dp[1][1] = 1;

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(A[i-1][j-1]=='.'){
                if(i==1&&j==1){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MOD;
            }
        }
    }

    cout << dp[H][W] << "\n";
    return 0;

}