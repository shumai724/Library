#include <bits/stdc++.h>
using namespace  std;

const long long INF = 1LL << 60;

int N,A[100009],dp[100009];

int main(){
    cin >> N;

    for(int i=1; i<=N;i++) cin >> A[i];

    for(int i=0; i<100009;i++) dp[i] = INF;

    

    dp[0]=0;
    dp[1]=A[1];

    for(int i=2;i<=N;i++){
        dp[i] = min(abs(dp[i-1]-A[i]),abs(dp[i-2]-A[i]));

    }

    cout << dp[N] << endl;





    
}