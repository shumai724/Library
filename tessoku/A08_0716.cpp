#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int H,W;
    cin >> H >> W;

    vector<vector<int>> X(H+1,vector<int>(W+1));
    for(int i = 1; i <= H; i++){

        for(int j = 1; j <= W; j++){
            cin >> X[i][j];

        }
    }

   vector<vector<int>> ans(H+1,vector<int>(W+1,0)),width(H+1,vector<int>(W+1,0));



    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            width[i][j] = width[i][j-1] + X[i][j];
        }

    }
    for(int j = 1; j <= W; j++){
        for(int i = 1; i <= H; i++){
            ans[i][j] = ans[i-1][j] + width[i][j];
        }

    }


    int Q;
    cin >> Q;
    rep(i,Q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        a--,b--;

        int answer = ans[c][d] - ans[a][d] - ans[c][b] + ans[a][b];

        cout << answer << endl;

    }

}