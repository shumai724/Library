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

    vector<int> C(N),P(N);
    rep(i,N)cin >> C[i] >> P[i];

    vector<ll> sum1(N+1),sum2(N+1);

    rep(i,N){
        if(C[i]==1){
            sum1[i+1] = sum1[i] + P[i];
            sum2[i+1] = sum2[i];
        }else{
            sum2[i+1] = sum2[i] + P[i];
            sum1[i+1] = sum1[i];
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int L,R;
        cin >> L >> R;
        ll ans1 = sum1[R] - sum1[L-1];
        ll ans2 = sum2[R] - sum2[L-1];
        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}
