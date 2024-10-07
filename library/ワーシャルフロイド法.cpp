//計算量　N^3
//すべての2頂点間の最短経路長を求める問題
//


#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int N,M;
int k;
ll d[400][400];
int u[(int)2e+5],v[(int)2e+5];
ll T[(int)2e+5];

vector<int> a;

ll solve(void){
    ll ans = (ll)1e+15;
    ll dp[5][2];
    vector<int> b;
    rep(i,k)b.push_back(i);
    while(true){
        dp[0][0] = d[0][v[a[b[0]]]]+T[a[b[0]]];
        dp[0][1] = d[0][u[a[b[0]]]]+T[a[b[0]]];

        rep(i,k-1){
            dp[i+1][0]=min(dp[i][0]+d[u[a[b[i]]]][v[a[b[i+1]]]],dp[i][1]+d[v[a[b[i]]]][v[a[b[i+1]]]])+T[a[b[i+1]]];

            dp[i+1][1]=min(dp[i][0]+d[u[a[b[i]]]][u[a[b[i+1]]]],dp[i][1]+d[v[a[b[i]]]][u[a[b[i+1]]]])+T[a[b[i+1]]];
        }

        ans = min(ans,dp[k-1][0]+d[u[a[b[k-1]]]][N-1]);
        ans = min(ans,dp[k-1][1]+d[v[a[b[k-1]]]][N-1]);
        if(!(next_permutation(b.begin(),b.end())))break;
    }

    return ans;
}

int main(){

    int x,Q;
    cin >> N >> M;

    rep(i,N){
        rep(j,N){
            if(i==j){
                d[i][j]=0;
            }else{
                d[i][j] = (ll)1e+15;
            }
        }
    }


    rep(i,M){
        cin >> u[i] >> v[i] >> T[i];
        u[i]--,v[i]--;

        d[u[i]][v[i]] = min(d[u[i]][v[i]],T[i]);
        d[v[i]][u[i]] = min(d[v[i]][u[i]],T[i]);
    }

    rep(i1,N){
        rep(i0,N){
            rep(i2,N){
                d[i0][i2] = min(d[i0][i2],d[i0][i1]+d[i1][i2]);

            }
        }
    }


    cin >> Q;
    rep(i,Q){
        cin >> k;
        a.clear();
        rep(ii,k){

            cin >> x;
            a.push_back(x-1);
        }

        cout << (solve()) << endl;

    }

    return 0;







}


