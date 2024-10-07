#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N;
    cin >> N;
    vector<vector<ll>> A(N,vector<ll>(N));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j];
        }
    }

    int M;
    cin >> M;

    ll ans = 1e15;

    vector<set<int>> S(N);

    rep(i,M){
        int x,y;
        cin >> x >> y;
        x--,y--;
        S[x].insert(y);
        S[y].insert(x);
        
        

    }
    vector<int> P(N);
    iota(P.begin(),P.end(),0);

    do{
        ll sum = 0;
        for(int i = 0; i < N; i++){
            sum += A[P[i]][i];
        }

        for(int i = 1; i < N; i++){
            if(S[P[i]].count(P[i-1])){
                sum += 1e9;
            }
        }

        ans = min(ans,sum);



    }while(next_permutation(P.begin(),P.end()));

    if(ans >= 1e9)ans = -1;

    cout << ans << endl;


}
