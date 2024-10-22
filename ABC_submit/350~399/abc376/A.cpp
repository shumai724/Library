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
    int N,C;
    cin >> N >> C;
    vector<int> T(N);
    rep(i,N)cin >> T[i];

    int time = 0;

    int ans = 0;
    for(int i = 0 ; i < N; i++){
        if(time <= T[i]){
            time = T[i] + C;
            ans += 1;
        }
    }

    cout << ans << "\n";


}