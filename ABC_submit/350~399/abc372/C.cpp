#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int main(){
    int N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> X(Q);
    vector<char> C(Q);

    int ans = 0;

    for(int i = 0; i < N-2; i++){
        if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C')ans++;
    }




    rep(i,Q){
        cin >> X[i] >> C[i];

        for(int k = 1; k <= 3; k++){
            int idx = X[i] - k;
            if(idx >= 0 && idx + 2 < N){
                if(S[idx] == 'A' && S[idx+1] == 'B' && S[idx + 2] == 'C')ans--;

            }
        }

        S[X[i] - 1] = C[i];

        for(int k = 1; k <= 3; k++){
            int idx = X[i] - k;
            if(idx >= 0 && idx+2 < N){
                if(S[idx] == 'A' && S[idx + 1] == 'B' && S[idx+2] == 'C')ans++;
            }
        }

        cout << ans << endl;
    }
    
}