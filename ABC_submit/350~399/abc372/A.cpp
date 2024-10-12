#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int main(){
    string S,ans;
    cin >> S;
    for(int i = 0; i < S.size(); i++){
        if(S[i]!='.')ans += S[i];
    }

    cout << ans << endl;
    return 0;


    
}