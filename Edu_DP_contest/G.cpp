#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = (int) k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int dp[100009];
vector<vector<int>> G;
int rec(int v){
    if(dp[v] != -1)return dp[v];

    int res = 0;
    for(auto nv:G[v]){
        chmax(res,rec(nv) + 1);

    }

    return dp[v] = res;
}

int main(){
    int N,M;
    cin >> N >> M;
    G.assign(N,vector<int>());

    for(int i = 0; i < M; i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        G[x].push_back(y);
    }

    for(int v = 0; v < N; v++) dp[v] = -1;

    int res = 0;
    for(int v = 0; v < N; v++)chmax(res,rec(v));
    cout << res << "\n";

}