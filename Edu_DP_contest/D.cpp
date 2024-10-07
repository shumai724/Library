#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, W, weight[109],value[109],dp[109][100009];
    cin >> N >> W;

    for(int i = 1; i <= N; i++){
        cin >> weight[i] >> value[i];

    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= W; j++){
            if(j-weight[i]>=0)dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][W] << endl;






}