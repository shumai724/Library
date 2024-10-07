#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N),B(N);
    vector<ll> ans(N);
    ll now_point = 0;

    rep(i,N){
        cin >> A[i];
        now_point += A[i];
        B[i] = A[i];
        
    }

    SORT(B);
    REV(B);
    









}
