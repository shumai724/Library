#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int N,M,A[100009],B[100009];
vector<int> G[100009];
bool visited[100009];

void dfs(int pos){
    visited[pos] = true;
    for(int i = 0; i < G[pos].size(); i++){
        int nex = G[pos][i];
        if(visited[nex]==false)dfs(nex);
    }
    return;

}

int main(){
    int N,M;
    cin >> N >> M;
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)visited[i] = false;

    dfs(1);

    for(int i = 1; i <= N; i++){
        if(visited[i] == false){
            cout << "The graph is not connected." << endl;
            return 0;
        }
    }

    cout << "The graph is connected." << endl;
    return 0;


}