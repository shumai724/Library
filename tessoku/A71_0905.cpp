#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N);
    rep(i,N)cin >> A[i];
    rep(i,N)cin >> B[i];
    SORT(A),SORT(B),REV(A);
    int ans = 0;
    rep(i,N)ans += A[i]*B[i];

    cout << ans << endl;
}