#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,K,H[100009],dp[100009];
    cin >> N >>K;


    for(int i = 1; i <= N; i++){
        cin >> H[i];
    }
    dp[1] = 0;

    for(int i = 2; i <= N; i++){
        dp[i] = dp[i-1] + abs(H[i-1]-H[i]);
        for(int j = 2; j <= K; j++){
            if(i-j >= 1){
                dp[i] = min(dp[i],dp[i-j]+abs(H[i-j]-H[i]));
            }
        }

    }


    cout << dp[N] << endl;




}