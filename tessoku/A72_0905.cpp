#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int H,W,K;
int ans = 0;
char S[10][109],d[10][100];

int paint(int remain_step){

    vector<pair<int,int>> Column;

    for(int j = 0; j < W; j++){
        int cnt = 0;
        for(int i = 0; i < H; i++){
            if(d[i][j]=='.')cnt++;

        }

        Column.push_back(make_pair(cnt,j));
    }

    SORT(Column);
    REV(Column);

    for(int j = 0; j < remain_step; j++){
        int idx = Column[j].second;
        for(int i = 0; i < H; i++){
            d[i][idx] = '#';
        }
    }

    int ret = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(d[i][j]=='#')ret++;
        }
    }
    return ret;
}



int main(){
    cin >> H >> W >> K;

    vector<vector<char>> S(H,vector<char>(W));
    rep(i,H)rep(j,W)cin >> S[i][j];

    for(int t = 0; t < (1<<H); t++){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                d[i][j] = S[i][j];
            }
        }

        int remain_step = K;

        for(int i = 0; i < H; i++){
            int wari = (1 << i);

            if((t / wari)%2 == 0)continue;

            remain_step--;
            for(int j = 0; j < W; j++){
                d[i][j] = '#';
            }
        }

        if(remain_step >= 0){
            int ans2 = paint(remain_step);
            ans = max(ans,ans2);
        }
    }

    cout << ans << endl;
    return 0;



}