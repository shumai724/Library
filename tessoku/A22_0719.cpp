#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N);

    for(int i = 1; i <= N-1; i++){
        cin >> A[i];

    }
    for(int i = 1; i <= N-1; i++){
        cin >> B[i];
    }

    int dp[100009];

    dp[1] = 0;

    for(int i = 2; i <= N; i++)dp[i] = -1000000000;

    for(int i = 1; i <= N-1; i++){
        dp[A[i]] = max(dp[A[i]],dp[i]+100);
        dp[B[i]] = max(dp[B[i]],dp[i]+150);
    }

    cout << dp[N] << "\n";
}