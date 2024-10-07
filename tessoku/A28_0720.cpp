#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){

    int N;
    cin >> N;
    ll ans = 0;

    rep(i,N){
        char t;
        int a;
        cin >> t >> a;

        if(t=='+')ans += a;
        if(t=='-')ans -= a;
        if(t=='*')ans *= a;

        if(ans<0)ans += 10000;

        ans = ans%10000;

        cout << ans << "\n";

    }

}