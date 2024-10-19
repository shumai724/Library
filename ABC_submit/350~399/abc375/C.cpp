#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int main(){
    int N;
    cin >> N;

    vector<vector<char>> A(N,vector<char>(N)),B(N,vector<char>(N));
    rep(i,N){
        rep(j,N){
            cin >> A[i][j];
        }
    }
    
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            int cnt = min({i+1,j+1,N-i,N-j});

            int ni = i,nj = j;

            for(int o = 0; o < cnt%4; o++){
                int ti = nj,tj = N-1-ni;
                ni = ti;
                nj = tj;
            }

            B[ni][nj] = A[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cout << B[i][j];
        }
        cout << "\n";
    }
    return 0;



}