#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())
int main(){
    int N;
    cin >> N;
    vector<ll> A(N),B(N),C(N);
    rep(i,N)cin >> A[i];
    rep(i,N)cin >> B[i];
    rep(i,N)cin >> C[i];

    vector<ll> a(46),b(46),c(46);
    rep(i,N){
        a[A[i]%46] += 1;
        b[B[i]%46] += 1;
        c[C[i]%46] += 1;
    }
    ll ans = 0;
    for(int i = 0 ; i < 46; i++){
        for(int j = 0 ;j < 46; j++){
            for(int k = 0 ; k < 46; k++){
                if((i+j+k)%46==0) ans += a[i]*b[j]*c[k];
            }
        }
    }

    cout << ans << endl;
    
}