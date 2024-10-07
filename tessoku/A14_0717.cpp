#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int N,K,A[1009],B[1009],C[1009],D[1009];
int P[1000009],Q[1000009];

int main(){
    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> B[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> C[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> D[i];
    }
    //配列Pの作成
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            P[(i-1)*N + j] = A[i] + B[j];
        }
    }
    //配列Qの作成
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            Q[(i-1)*N + j] = C[i] + D[j];
        }
    }
    sort(Q+1,Q+(N*N)+1);

    for(int i = 1; i <= N*N; i++){
        int pos1 = lower_bound(Q+1,Q+(N*N)+1, K-P[i]) - Q;

        if(pos1 <= N*N && Q[pos1] == K-P[i]){
            cout << "Yes" << "\n";
            return 0;
        }
    }

    cout << "No" << "\n";
    return 0;
}