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
    vector<ll> K(N);
    rep(i,N)cin >> K[i];

    ll ans = 1e18;
    ll sum0 = 0;
    rep(i,N)sum0 += K[i];

    for(int i = 0 ; i < (1<<N); i++){
        ll sum1 = 0;
        for(int k = 0 ; k < N; k++){
            if((i /(1<<k)) %2 == 1){
                sum1 += K[k];
            }


        }
        ll sum = max(sum1,sum0 - sum1);

        ans = min(ans,sum);
    }

    cout << ans << endl;
    return 0;


}