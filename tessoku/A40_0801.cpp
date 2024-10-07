#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k,n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())


int main(){
    int N;
    cin >> N;

    ll A[109];
    rep(i,0,102)A[i] = 0;

    rep(i,0,N){
        int k;
        cin >> k;
        A[k]++;
    }
    ll ans = 0;

    rrep(i,1,100){
        ans += A[i] * (A[i]-1) * (A[i]-2) /6;

    }

    cout << ans << endl;
    return 0;





}