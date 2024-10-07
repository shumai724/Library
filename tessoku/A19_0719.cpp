#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,W;
    cin >> N >> W;

    vector<vector<ll>> dp(N+1,vector<ll>(W+1,0));

    dp[0][0] = 0;
    for(int j = 1; j <= W; j++){
        dp[0][j] = -1000000000000000;
    }
    for(int i = 1; i <= N; i++){
        ll w,v;
        cin >> w >> v;

        for(int j = 0; j <= W; j++){
            if(w<=j){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w]+v);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    ll ans = 0;

    for(int i = 0; i <= W; i++){
        ans = max(ans,dp[N][i]);
    }

    cout << ans << "\n";

}