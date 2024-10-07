#include <bits/stdc++.h>
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

    ll mod = 1e9+7;
    vector<vector<ll>> dp(7,vector<ll>(N+1));


    for(int i = 0; i < 7; i++){
        dp[i][0] = 0;
    }

    for(int j = 1; j <= N; j++){
        for(int i = 0; i < 7; i++){
            char ss = S[j-1];

            if(S[j-1]=='a'){
                dp[0][j] = dp[0][j-1]+1;
            }else{
                dp[0][j] = dp[0][j-1];
            }
            if(S[j-1]=='t'){
                dp[1][j] = (dp[1][j-1]+dp[0][j-1])%mod;
            }else{
                dp[1][j] = dp[1][j-1];
            }
            if(S[j-1]=='c'){
                dp[2][j] = (dp[2][j-1] + dp[1][j-1])%mod;
            }else{
                dp[2][j] = dp[2][j-1];
            }
            if(S[j-1]=='o'){
                dp[3][j] = (dp[3][j-1] + dp[2][j-1])%mod;
            }else{
                dp[3][j] = dp[3][j-1];
            }
            if(S[j-1]=='d'){
                dp[4][j] = (dp[4][j-1] + dp[3][j-1])%mod;
            }else{
                dp[4][j] = dp[4][j-1];
            }
            if(S[j-1]=='e'){
                dp[5][j] = (dp[5][j-1] + dp[4][j-1])%mod;
            }else{
                dp[5][j] = dp[5][j-1];
            }
            if(S[j-1]=='r'){
                dp[6][j] = (dp[6][j-1] + dp[5][j-1])%mod;
            }else{
                dp[6][j] = dp[6][j-1];
            }
        }

    }

    cout << dp[6][N] << endl;
    return 0;



}
