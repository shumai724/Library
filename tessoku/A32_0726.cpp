#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k, n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,A,B;
    cin >> N >> A >> B;
    bool dp[100009];

    for(int i = 0; i <= N; i++){
        if(i >= A && dp[i-A]==false) dp[i] = true;
        else if(i >= B && dp[i-B]==false) dp[i] = true;
        else dp[i] = false;
    }

    if(dp[N]==true)cout << "First" << "\n";
    else cout << "Second" << "\n";

}