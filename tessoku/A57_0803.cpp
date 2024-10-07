#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())


ll power100[200009],T[200009],H[200009];
ll mod = 2147483647;

int main(){
    int N,Q;
    cin >> N >> Q;
    vector<int> A(N+1),X(Q+1),Y(Q+1);
    rrep(i,N)cin >> A[i];

    rrep(i,Q)cin >> X[i] >> Y[i];

    int dp[32][100009];

    for(int i = 1; i <= N; i++)dp[0][i] = A[i];

    for(int d = 1; d <= 29; d++){
        for(int i = 1; i <= N; i++){
            dp[d][i] = dp[d-1][dp[d-1][i]];
        }
    }

    for(int i = 1; i <= Q; i++){
        int current_place = X[i];

        for(int d = 29; d >= 0; d--){
            if((Y[i] / (1<<d)) % 2 != 0){
                current_place = dp[d][current_place];
            }

        }

        cout << current_place << endl;
    }



}