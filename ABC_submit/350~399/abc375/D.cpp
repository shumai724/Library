#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int main(){
    string S;
    cin >> S;

    vector<ll> moji(26),sum(26);
    ll ans = 0;

    int N = S.size();

    rep(i,N){
        int v = S[i] - 'A';
        ans += (i-1) * moji[v] - sum[v];
        moji[v] += 1;
        sum[v] += i;
    }

    cout << ans << "\n";
    return 0;

}