#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())


int main(){
    int N;
    cin >> N;

    int P[2009],A[2009],dp[2009][2009];

    for(int i = 1; i <= N; i++){
        cin >> P[i] >> A[i];
    }

    dp[1][N] = 0;

    for(int Len = N-2; Len >= 0; Len--){
        for(int l = 1; l <= N - Len; l++){
            int r = Len + l;
            int score1 = 0;
            if(l <= P[l-1] && P[l-1] <= r)score1 = A[l-1];

            int score2 = 0;
            if(l <= P[r+1] && P[r+1] <= r)score2 = A[r+1];

            if(l==1){
                dp[l][r] = dp[l][r+1] + score2;
            }else if(r==N){
                dp[l][r] = dp[l-1][r] + score1;
            }else{
                dp[l][r] = max(dp[l][r+1] + score2,dp[l-1][r] + score1);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans,dp[i][i]);
    }

    cout << ans << "\n";



}