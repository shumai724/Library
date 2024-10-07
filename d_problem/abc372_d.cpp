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

    vector<pair<ll,ll>> G(N+1,vector<ll,ll>);

    vector<ll> u(M),v(M),w(M);
    rep(i,M){
        cin >> u[i] >> v[i] >> w[i];
        G[u[i]].push_back(make_pair(v[i],w[i]));

    }
    vector<ll> ans(N+1);
    int pos = 0;

    queue<pair<int,int>> Q;
    
    for(int i = 1; i <= N; i++){
        for(int j = 0 ; j < G[i].size(); j++){
            Q.push(G[i][j]);
        }
    }

    vector<int> visited(N+1,false);

    while(!Q.empty()){
        int pos = Q.front();
        Q.pop;
        

    }


    for(int i = 1; i <= N; i++){
        if(i >= 2)cout << ' ';
        cout << ans[i];
    }

    cout << "\n";
    return 0;

}