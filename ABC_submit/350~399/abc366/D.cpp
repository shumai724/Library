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
    vector<vector<vector<int>>> A(N,vector<vector<int>>(N,vector<int>(N,0)));

    rep(i,N){
        rep(j,N){
            rep(k,N){
                cin >> A[i][j][k];
            }
        }
    }

    vector<vector<vector<ll>>> B(N+1,vector<vector<ll>>(N+1,vector<ll>(N+1)));

    rep(i,N){
        rep(j,N){
            rep(k,N){
                B[i+1][j+1][k+1] = B[i][j+1][k+1] + B[i+1][j][k+1] + B[i+1][j+1][k] 
                                  - B[i][j][k+1] - B[i][j+1][k] - B[i+1][j][k]
                                  + B[i][j][k] + A[i][j][k]; 
            }
        }
    }

    int Q;
    cin >> Q;

    for(int i = 0 ; i < Q; i++){
        int lx,rx,ly,ry,lz,rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        lx--,ly--,lz--;
        ll ans = B[rx][ry][rz] - B[lx][ry][rz] - B[rx][ly][rz] -
                 B[rx][ry][lz] + B[lx][ly][rz] + B[lx][ry][lz] +
                 B[rx][ly][lz] - B[lx][ly][lz];

        cout << ans << endl;

    }
    return 0;





}