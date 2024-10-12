#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())
int main(){
    string S;
    cin >> S;
    vector<int> loc(26);
    rep(i,26){
        int k = S[i] - 'A';
        loc[k] = i;
    }

    int ans = 0;

    for(int i = 1; i < 26; i++){
        ans += abs(loc[i-1] - loc[i]);

    }

    cout << ans << endl;
    return 0;
}