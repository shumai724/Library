#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())
int main(){
    int K;
    cin >> K;
    if(K%9!=0){
        cout << 0 << endl;
        return 0;
    }

    vector<ll> dp(K+1);
    ll mod = 1e9+7;
    dp[0] = 1;

    for(int j = 1; j <= K; j++){
        for(int i = 1; i <= 9; i++){
            if((j-i)>=0){
                dp[j] = (dp[j-i] + dp[j]) % mod;
            }

        }
    }

    cout << dp[K] << endl;
    
    return 0;
    
}