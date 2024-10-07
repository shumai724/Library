#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
int X[1509][1509],ans[1509][1509];

int main(){
    int H,W,N;
    cin >> H >> W >> N;

    rep(i,N){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        c++,d++;

        X[a][b] += 1;
        X[a][d] -= 1;
        X[c][b] -= 1;
        X[c][d] += 1;
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            ans[i][j] = ans[i][j-1] + X[i][j];
        }
    }

    for(int j = 1; j <= W; j++){
        for(int i = 1; i <= H; i++){
            ans[i][j] = ans[i-1][j] + ans[i][j];
        }
    }

    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cout << ans[i][j];
            if(j==W)cout << endl;
            else cout << " ";
        }
    }



}