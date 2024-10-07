#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,M;
    cin >> N >> M+
    vector<string> S(N);

    for(int i = 0; i < N; i++)cin >> S[i];

    int ans = N;
    for(int bit = 0; bit < (1<<N); bit++){
        vector<bool> exist(M);
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(bit >> i & 1){
                cnt++;
                for(int j  =0; j < M; j++){
                    if(S[i][j]=='o')exist[j]=true;
                }
            }
        }

        bool all_exist = true;
        for(int j = 0; j < M; j++){
            if(!exist[j])all_exist = false;
        }
        if(all_exist)ans = min(ans,cnt);
    }

  cout << ans << endl;
  








}
