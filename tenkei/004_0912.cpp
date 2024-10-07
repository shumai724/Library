#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<int>> A(H,vector<int>(W));

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }

    vector<ll> R(H),C(W);

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            R[i] += A[i][j];
            C[j] += A[i][j];

        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(j>=1)cout << ' ';
            cout << R[i] + C[j] - A[i][j];
            
        }

        cout << endl;
    }

    return 0;
}