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
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    SORT(A);

    int Q;
    cin >> Q;
    while(Q--){
        ll B;
        cin >> B;

        int p = lower_bound(A.begin(),A.end(),B) - A.begin();


        ll ans = 1e15+8;

        if(p<N)ans = min(ans,abs(B - A[p]));

        if(p > 0)ans = min(ans,abs(B - A[p-1]));





        cout << ans << endl;



    }
    return 0;
}