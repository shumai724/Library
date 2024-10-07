#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,A[100009],B[100009],C[100009],dp[100009][3];
    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> A[i] >> B[i] >> C[i];
    }

    for(int i = 1; i <= N; i++){
        dp[i][0] = max(dp[i-1][1]+A[i],dp[i-1][2]+A[i]);
        dp[i][1] = max(dp[i-1][0] + B[i],dp[i-1][2] + B[i]);
        dp[i][2] = max(dp[i-1][0] + C[i],dp[i-1][1]+C[i]);
    }

    int ans = max(dp[N][0],max(dp[N][1],dp[N][2]));

    cout << ans << endl;





}