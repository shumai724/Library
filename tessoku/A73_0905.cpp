#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N,M;
    cin >> N >> M;
    vector<int> A(M),B(M),C(M),D(M);
    vector<pair<int,int>> Gragh[N];
    rep(i,M)cin >> A[i] >> B[i] >> C[i] >> D[i];

    rep(i,M){

        if(D[i]==1){
            Gragh[A[i]-1].push_back(make_pair(B[i]-1,10000*C[i]-1));
            Gragh[B[i]-1].push_back(make_pair(A[i]-1,10000*C[i]-1));
            
        }else{
        Gragh[A[i]-1].push_back(make_pair(B[i]-1,10000*C[i]));
        Gragh[B[i]-1].push_back(make_pair(A[i]-1,10000*C[i]));


        }



       
    }

    //初期化
    






}


