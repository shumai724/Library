#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    string S,T;
    cin >> S >> T;
    int dp[2009][2009];

    dp[0][0] = 0;

    for(int i = 1; i <= (int)S.size(); i++){
        for(int j = 1; j <= (int)T.size(); j++){
            if(S[i-1]==T[j-1]){
                dp[i][j] = max(dp[i-1][j-1] + 1,max(dp[i-1][j],dp[i][j-1]));
            }else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }

        }
    
    }

    cout << dp[S.size()][T.size()] << "\n";


}