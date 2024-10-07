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
    vector<ll> A(N),sum1(N+1);
    rep(i,N)cin >> A[i];
    SORT(A);
    ll mod = 1e8;

    int r = N;
    ll cnt = 0,res = 0;
    for(int i = 0; i < N; i++){
        r = max(r,i+1);
        while(r - 1 > i && A[r-1] + A[i] >= mod){
            r--;
        }

        cnt += N - r;
    }

    for(int i = 0 ; i < N; i++){
        res += ll(A[i]) * (N-1);
    }
    res -= cnt * mod;
    cout << res << endl;
    return 0;



}
