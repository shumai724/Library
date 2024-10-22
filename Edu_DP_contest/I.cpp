#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main(){
    int N;
    cin >> N;
    vector<double> P(N+1);
    rrep(i,N)cin >> P[i];

    vector<vector<double>> DP(N+1,vector<double>(N+1));

    DP[0][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(j==0){
                DP[i][j] = DP[i-1][j] * (1-P[i]);
            }else{
                DP[i][j] = DP[i-1][j] * (1-P[i]) + DP[i-1][j-1]*P[i];
            }
        }
    }

    long double ans = 0;
    for(int j = (N+1)/2; j <= N; j++){
        ans += DP[N][j];
    }

    cout << setprecision(15);

    cout << ans << "\n";
    return 0;




}