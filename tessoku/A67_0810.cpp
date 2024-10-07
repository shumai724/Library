#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

class UnionFind{
    public:
    int par[100009];
    int siz[100009];

    //N頂点のUnion-findを作成
    void init(int N){
        for(int i = 1; i <= N; i++) par[i] = -1;
        for(int i = 1; i <= N; i++) siz[i] = 1;
    }

    int root(int x){
        while(true){
            if(par[x]==-1)break;
            x = par[x];
        
        }

        return x;
    }

    void unite(int u, int v){
        int RootU = root(u);
        int RootV = root(v);

        if(RootU == RootV)return;
        if(siz[RootU] < siz[RootV]){
            par[RootU] = RootV;
            siz[RootU] = siz[RootU] + siz[RootV];
        }else{
            par[RootV] = RootU;
            siz[RootU] = siz[RootU] + siz[RootV];
        }
    }

    bool same(int u,int v){
        if(root(u) == root(v))return true;
        else return false;
    }

};

int N,M;
int A[100009],B[100009],C[100009];
UnionFind UF;

int main(){
    cin >> N >> M;

    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i] >> C[i];
    }

    vector<pair<int,int>> P;
    for(int i = 1; i <= M; i++){
        P.push_back(make_pair(C[i],i));

    }

    SORT(P);

    int ans = 0;
    UF.init(N);

    for(int i = 0; i < P.size(); i++){
        int idx = P[i].second;

        if(UF.same(A[idx],B[idx])==false){
            UF.unite(A[idx],B[idx]);
            ans += C[idx];

        }
    }

    cout << ans << endl;
    return 0;
    
}

