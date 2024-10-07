#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<char>> vec(H+1,vector<char>(W+1));
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> vec[i][j];
        }
    }
    ll dp[35][35];
    
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(i==1 && j==1)dp[i][j] = 1;
            else{
                dp[i][j] = 0;
                if(vec[i][j-1] == '.' && j >= 2)dp[i][j] += dp[i][j-1];
                if(vec[i-1][j] == '.' && i >= 2)dp[i][j] += dp[i-1][j];
            }
        }
    }

    cout << dp[H][W] << "\n";



}