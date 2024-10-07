#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())


int N,M,A[100009],B[100009];

int dist[100009];
vector<int> G[100009];
queue<int> Q;

int main(){
    cin >> N >> M;
    rrep(i,M){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    for(int i = 1; i <= N; i++)dist[i] = -1;

    Q.push(1);
    dist[1] = 0;

    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        for(int i = 0; i < G[pos].size(); i++){
            int to = G[pos][i];
            if(dist[to]==-1){
                dist[to] = dist[pos] + 1;
                Q.push(to);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << dist[i] << endl;
    }
    return 0;


}