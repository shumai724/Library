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


int N,Q;
int Query[100009],u[100009],v[100009];

int main(){
    cin >> N >> Q;
    rrep(i,Q) cin >> Query[i] >> u[i] >> v[i];

    UnionFind UF;
    UF.init(N);

    for(int i = 1; i <= Q; i++){
        if(Query[i]==1){
            UF.unite(u[i],v[i]);
        }

        if(Query[i]==2){
            if(UF.same(u[i],v[i])==true)cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;


}