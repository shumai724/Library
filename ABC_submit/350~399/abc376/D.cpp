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


int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> G(N+1);

    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    vector<int> dist(N+1,-1);

    queue<int> Q;

    Q.push(1);
    dist[1] = 0;
    int ans = 1e9;
    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        for(int i = 0; i < G[pos].size(); i++){
            int to = G[pos][i];
            if(dist[to] == 0){
                ans = min(ans,dist[pos] + 1);

            }
            if(dist[to] == -1){
                dist[to] = dist[pos] + 1;
                Q.push(to);

            }
        }
    }

    if(ans==1e9)ans = -1;

    cout << ans << "\n";
    return 0;





}