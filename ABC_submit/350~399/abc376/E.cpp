#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void solve(){
    int N,K;
    cin >> N >> K;
    vector<pair<int,int>> P(N);
    rep(i,N)cin >> P[i].first;
    rep(i,N)cin >> P[i].second;

    SORT(P);
    ll ans = 1e18;
    ll sum = 0;
    priority_queue<int> pq;
    rep(i,N){
        if(pq.size() >= K-1){
            ans = min(ans,(sum + P[i].second)*P[i].first);
        }
        sum += P[i].second;
        pq.push(P[i].second);

        if(pq.size() == K){
            sum -= pq.top();
            pq.pop();
        }

    }

    cout << ans << "\n";


}


int main(){
    int T;
    cin >> T;
    rep(i,T)solve();
    return 0;


}