#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    string S,T;
    cin >> S >> T;

    int mx = max(S.size(),T.size());

    for(int i = 0 ; i < mx; i++){
        if(i>S.size() || i > T.size()){
            cout << i+1 << endl;
            return 0;
        }

        if(S[i]!=T[i]){
            cout << i+1 << endl;
            return 0;
        }

    }

    cout << 0 << endl;
    return 0;

}