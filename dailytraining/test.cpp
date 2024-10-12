#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<ll>> B(N,vector<ll>(M));
    rep(i,N){
        rep(j,M){
            cin >> B[i][j];
        }
    }

    bool hantei = true;

    ll start = B[0][0];

    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < M; j++){
            if(B[i][j]!=start + (i*7)+j)hantei = false;


        }
    }


    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M-1; j++){
            ll oo = (B[i][j])%7;
            ll pp = (B[i][j+1])%7;
            if(oo==6){
                if(pp!=0)hantei = false;
            }else{
                if(oo!=pp-1)hantei = false;
            }
        }
    }
    
    if(hantei)cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;





}