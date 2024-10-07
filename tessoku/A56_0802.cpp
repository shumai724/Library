#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())


ll power100[200009],T[200009],H[200009];
ll mod = 2147483647;

ll hash_value(ll x,ll y){
    ll value = H[y] - (H[x-1] * power100[y-x+1] %mod);
    if(value<0)value += mod;
    return value; 
}


int main(){
    ll n,q;
    cin >> n >> q;
    string S;
    cin >> S;

    vector<ll> A(q+1),B(q+1),C(q+1),D(q+1);

    rrep(i,q)cin >> A[i] >> B[i] >> C[i]>> D[i];

    for(int i = 0; i < n; i++){
        T[i+1] = (S[i] - 'a') + 1;
    }

    power100[0] = 1;
    for(int i = 1; i <= n; i++){
        power100[i] = 100LL * power100[i-1] % mod;
    }

    H[0] = 0;
    rrep(i,n){
        H[i] = (100LL * H[i-1] + T[i]) % mod;
    }

    for(int i = 1; i <= q; i++){
        ll hash1 = hash_value(A[i],B[i]);
        ll hash2 = hash_value(C[i],D[i]);

        if(hash1 == hash2)cout << "Yes" << endl;
        else cout << "No" << endl;

    }



}