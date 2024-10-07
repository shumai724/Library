#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,M;
    cin >> N >> M;

    vector<vector<int>> Gr(N+1,vector<int>());

    rep(i,M){
        int a,b;
        cin >> a >> b;
        Gr[a].push_back(b);
        Gr[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        cout << i << ": {";
        for(int j = 0; j < Gr[i].size(); j++){
            if(j >= 1)cout << ", ";
            cout << Gr[i][j];
        }
        cout << "}" << endl;
    }
    return 0;

}