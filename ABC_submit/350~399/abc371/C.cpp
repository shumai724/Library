#include <bits/stdc++.h>
#include <numeric>
#include <utility>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N;
    cin >> N;

    set<pair<int,int>> G,H;
    int mg;
    cin >> mg;

    rep(i,mg){
        int u,v;
        cin >> u >> v;
        u--,v--;
        G.emplace(u,v);
        G.emplace(v,u);

    }

    int mh;
    cin >> mh;
    rep(i,mh){
        int a,b;
        cin >> a >> b;
        a--,b--;
        H.emplace(a,b);
        H.emplace(b,a);
    }

    vector<vector<int>> A(N,vector<int>(N));

    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    int ans = 1e9+8;

    vector<int> P(N);
    iota(P.begin(),P.end(),0);

    do{
        int sum = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < i; j++){
                bool inG = G.find({P[i],P[j]}) != G.end();
                bool inH = H.find({i,j}) != H.end();

                if(inG != inH){
                    sum += A[i][j];
                }
                
            }
        }

        ans = min(ans,sum);


    }while(next_permutation(P.begin(),P.end()));

    cout << ans << endl;
    return 0;




}
