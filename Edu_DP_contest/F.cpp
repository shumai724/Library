#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = (int) k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int main(){
    string S,T;
    cin >> S >> T;

    vector<vector<int>> dp(S.size()+1,vector<int>(T.size()+1)),Log(S.size()+1,vector<int>(T.size()+1));

    for(int i = 1; i <= S.size(); i++){
        for(int j = 1; j <= T.size(); j++){
            char s_i = S[i-1],t_j = T[j-1];
            if(s_i == t_j){
                dp[i][j] = dp[i-1][j-1] + 1;
                Log[i][j] = 1;
            }else if(dp[i-1][j] > dp[i][j-1]){
                dp[i][j] = dp[i-1][j];
                Log[i][j] = 2;
            }else{
                dp[i][j] = dp[i][j-1];
                Log[i][j] = 3;
            }
        }
    }

    string ans = "";
    int ns = S.size(),nt = T.size();
    int crr = dp[ns][nt];
    while(ns >= 1 && nt >= 1){
        if(Log[ns][nt] == 1 ){
            ans += S[ns-1];
            ns--,nt--;
            continue;
        }

        if(Log[ns][nt] == 2){
            ns--;
            continue;
        }

        if(Log[ns][nt] == 3){
            nt--;
            continue;
        }

    }

    REV(ans);
    cout << ans << '\n';
    return 0;

}