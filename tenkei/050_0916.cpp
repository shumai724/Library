#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N,L;
    cin >> N >> L;

    vector<ll> dp(N+1,1);
    ll mod = 1e9+7;

    
    for(int i = L; i <= N; i++){
        dp[i] = (dp[i - 1] + dp[i - L])%mod;
    }

    cout << dp[N] << endl;
    return 0;


}
