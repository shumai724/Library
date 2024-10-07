#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k,n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N;
    cin >> N;
    vector<int> L(N),R(N);
    rep(i,0,N)cin >> L[i] >> R[i];
    vector<pair<int,int>> P(N);
    rep(i,0,N){
        P[i] = make_pair(R[i],L[i]);
    }
    SORT(P);

    int ans = 0;
    int current_time = 0;
    rep(i,0,N){
        if(current_time <= P[i].second){
            ans++;
            current_time = P[i].first;
        }

    }

    cout << ans << endl;
    return 0;


}