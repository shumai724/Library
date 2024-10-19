#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = (int) k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int main(){
    int N,W;
    cin >> N >> W;
    vector<ll> Weight(N+1),V(N+1);
    for(ll i = 1; i <= N; i++)cin >> Weight[i] >> V[i];

    vector<vector<ll>> dp(109,vector<ll>(100009,1e18));

    for(int i = 0; i <= N; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i <= N; i++){
        ll value = V[i];
        for(int j = 1; j <= 100000; j++){
            if(value > j){
                dp[i][j] = dp[i-1][j];
            }else{
                if(dp[i-1][j] < dp[i-1][j-value] + Weight[i]){
                    dp[i][j] = dp[i-1][j];

                }else{
                    dp[i][j] = dp[i-1][j-value] + Weight[i];
                }
            }
        }
    }

    int ans = 0;

    for(int i = 1; i <= 100000; i++){
        if(dp[N][i]<=W){
            ans = max(ans,i);
        }
    }

    cout << ans << "\n";
    return 0;
}