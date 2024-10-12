#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N,M;
    cin >> N >> M;

    vector<int> u(M),v(M),w(M);
    
    vector<vector<pair<int,ll>>> G(N+1);


    rep(i,M){
        cin >> u[i] >> v[i] >> w[i];
        G[u[i]].push_back(make_pair(v[i],w[i]));
        G[v[i]].push_back(make_pair(u[i],-1*w[i]));
    }

    vector<int> visited(N+1,false);
    vector<ll> ans(N+1,0);

    queue<int> Q;

    for(int i = 1; i <= N; i++){
        if(visited[i])continue;
        Q.push(i);
        visited[i] = true;
        while(!Q.empty()){

            int u = Q.front();
            Q.pop();

        
            for(int j = 0; j < G[u].size(); j++){
                int kk = G[u][j].first;
                if(visited[kk]==false){
                   visited[kk] = true;
                   ans[kk] = ans[u] + G[u][j].second;
                   Q.push(kk);
                }

            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(i >= 2)cout << ' ';
        ll c = ans[i];
        cout << c;
    }

    cout << "\n";
    return 0;

}