#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,X,Y;
    cin >> N >> X >> Y;

    vector<int> A(N),B(N);
    rep(i,N)cin >> A[i] >> B[i];

    int dp[10009][10009];
    for(int n = 1; n <= N; n++){
        int aa = A[n-1];
        int bb = B[n-1];

        for(int i = 1; i <= X; i++){
            for(int j = 1; j <= Y; j++){
                if(i-aa >= 0 && j-bb >= 0 && aa-i <= X && bb-j <= Y){
                    dp[i][j] = max(dp[i][j],dp[i-aa][j-bb] + 1);
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }


    }

    cout  << dp[X][Y] + 1 << "\n";
    return 0;



    


    

}
