#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int N,A[19];
int M,X[109],Y[109],Z[109];
int dist[1033];
vector<int> G[1033];

int Getnext(int pos,int idx){
    int State[19];

    for(int i = 1; i <= N; i++){
        int wari = (1 << (i-1));
        State[i] = (pos/wari) % 2;
    }

    State[X[idx]] = 1 - State[X[idx]];
    State[Y[idx]] = 1 - State[Y[idx]];
    State[Z[idx]] = 1 - State[Z[idx]];

    int ret = 0;
    for(int i = 1; i <= N; i++){
        if(State[i]==1)ret += (1<<(i-1));
    }

    return ret;
}



int main(){

    cin >> N >> M;

    rrep(i,N)cin >> A[i];


    rrep(i,M)cin >> X[i] >> Y[i] >> Z[i];

    for(int i = 0; i < (1<<N); i++){
        for(int j = 1; j <= M; j++){
            int NextState = Getnext(i,j);
            G[i].push_back(NextState);
        }
    }

    int Goal = (1<<N)-1;
    int Start = 0;
    for(int i = 1; i <= N; i++){
        if(A[i]==1)Start += (1 << (i-1)); 
    }

    queue<int> Q;

    for(int i = 0; i < (1<<N); i++){
        dist[i] = -1;
    }
    dist[Start] = 0;
    Q.push(Start);

    while(!Q.empty()){
        int pos = Q.front();
        Q.pop();
        for(int i = 0; i < G[pos].size();i++){
            int nex = G[pos][i];
            if(dist[nex]==-1){
                dist[nex] = dist[pos] + 1;
                Q.push(nex);
            }
        }


    }

    cout << dist[Goal] << endl;


    


}


