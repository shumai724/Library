#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k,n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int D,N;
    cin >> D >> N;

    vector<int> H(D+1,24);

    rep(i,0,N){
        int L,R,HH;
        cin >> L >> R >> HH;

        for(int j = L; j <= R; j++){
            H[j] = min(H[j],HH);
        }

    }

    int ans = 0;

    for(int i = 1; i <= D; i++){
        ans += H[i];

    }

    cout << ans << endl;

}