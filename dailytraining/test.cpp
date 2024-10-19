#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

vector<vector<int>> G;
vector<int> ans;

void dfs(int crr,int pre){
    ans.push_back(crr);
    for(int nxt:G[crr]){
        if(nxt != pre){
            dfs(nxt,crr);
            ans.push_back(crr);

        }
    }


}

int main(){
    int N;
    cin >> N;
    G.resize(N+1);
    vector<int> A(N-1),B(N-1);
    rep(i,N-1)cin >> A[i] >> B[i];

    vector<vector<int>> G(N+1);

    rep(i,N-1){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    for(int i = 1; i <= N; i++)SORT(G[i]);

    dfs(1,-1);

    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i];
        if(i != ans.size()-1)cout << " ";
    }

    cout << "\n";
    return 0;




    
}