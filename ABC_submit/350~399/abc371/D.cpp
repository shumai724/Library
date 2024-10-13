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
    vector<int> X(N),P(N);
    rep(i,N)cin >> X[i];
    rep(i,N)cin >> P[i];

    vector<ll> sum(N+1);
    rep(i,N){
        sum[i+1] = sum[i] + P[i];
    }

    int Q;
    cin >> Q;
    while(Q--){
        int L,R;
        cin >> L >> R;

        int lp = lower_bound(X.begin(),X.end(),L) - X.begin();
        int rp = upper_bound(X.begin(),X.end(),R) - X.begin();

        ll ans = sum[rp] - sum[lp];



        cout << ans << endl;


    }

}
