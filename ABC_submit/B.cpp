#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int H,W;
    cin >> H >> W;
    int si,sj;
    cin >> si >> sj;

    vector<vector<char>> vec(H+1,vector<char>(W+1));

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> vec[i][j];
        }
    }

    string X;
    cin >> X;
    rep(i,X.size()){
        char now = X[i];
        if(now=='L' && vec[si][sj-1]=='.'){
            sj--;
        }
        if(now=='R' && sj < W && vec[si][sj+1]=='.'){
            sj++;
        }
        if(now=='U' && vec[si-1][sj]=='.'){
            si--;
        }
        if(now=='D' && si < H && vec[si+1][sj]=='.'){
            si++;
        }
    }

    cout << si << " " << sj << "\n";
    return 0;

    

}
