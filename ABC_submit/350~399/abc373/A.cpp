#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())
int main(){
    vector<string> vec(12);
    rep(i,12)cin >> vec[i];
    int ans = 0;
    rep(i,12){
        if(vec[i].size() == i+1){
            ans++;
        }
    }

    cout << ans << endl;

    
}