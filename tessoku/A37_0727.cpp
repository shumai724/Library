#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k,n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    ll N,M,B;
    cin >> N >> M >> B;
    ll ans = 0;

    vector<ll> A(N),C(M);
    rep(i,0,N)cin >> A[i];
    rep(j,0,M)cin >> C[j];

    rep(i,0,N)ans += A[i] * M;
    ans += B * N * M;
    rep(j,0,M)ans += C[j] * N;


    

    cout << ans << "\n";
    return 0;
    


}