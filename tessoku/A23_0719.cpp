#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> A(M+1,vector<int>(N+1));

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> A[i][j];
        }
    }

    int dp[109][1024];

    for(int i = 0; i <= M; i++){
        for(int j = 0; j <= (1<<N); j++){
            dp[i][j] = 10000;
        }
    }

    dp[0][0] = 0;
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < (1 << N); j++){

            int already[19];

            for(int k = 1; k <= N; k++){
                if((j / (1 << (k-1))) % 2 == 0){
                    already[k] = 0;
                }
                else{
                    already[k] = 1;
                }
            }

            int v = 0;
            for(int k = 1; k <= N; k++){
                if(already[k]==1 || A[i][k]==1){
                    v += (1 << (k-1));
                }
            }

            dp[i][j] = min(dp[i][j],dp[i-1][j]);
            dp[i][v] = min(dp[i][v],dp[i-1][j] + 1);
        }
    }

    if(dp[M][(1 << N)-1] == 10000)cout << -1 << "\n";
    else cout << dp[M][(1 << N) - 1] << "\n";
    return 0;

}