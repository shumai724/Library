#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,L;
    cin >> N >> L;

    vector<int> A(N);
    vector<char> B(N);
    rep(i,N)cin >> A[i] >> B[i];

    int ans = 0;

    rep(i,N){

        if(B[i]=='E')ans = max(ans,L-A[i]);
        if(B[i]=='W')ans = max(ans,A[i]);
    }

    cout << ans << endl;



}