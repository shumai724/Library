#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int N,M,A[100009],B[100009],C[100009],dist[100009];
vector<pair<int,int>> G[100009];

//ダイクストラ法
int cur[100009];
bool kakutei[100009];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;



int main(){
    cin >> N >> M;
    rrep(i,M){
        cin >> A[i] >> B[i] >> C[i];
        G[A[i]].push_back(make_pair(B[i],C[i]));
        G[B[i]].push_back(make_pair(A[i],C[i]));
    }

    //配列の初期化
    rrep(i,N)kakutei[i] = false;
    rrep(i,N)cur[i] = 2000000000;

    //スタート地点をqueueに追加

    cur[1] = 0;
    Q.push(make_pair(cur[1],1));

    //ダイクストラ法
    while(!Q.empty()){

        int pos = Q.top().second;
        Q.pop();

        if(kakutei[pos]==true)continue;

        kakutei[pos] = true;

        for(int i = 0; i < G[pos].size(); i++){
            int nex = G[pos][i].first;
            int cost = G[pos][i].second;
            if(cur[nex] > cur[pos] + cost){
                cur[nex] = cur[pos] + cost;
                Q.push(make_pair(cur[nex],nex));

            }
        }
    }

    for(int i = 1; i <= N; i++){
        if(cur[i]==2000000000)cout << -1 << endl;
        else cout << cur[i] << endl;
    }
    return 0;











}