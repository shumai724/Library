#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,M;
    cin >> N >> M;
    vector<string> S(N);

    for(int i = 0; i < N; i++)cin >> S[i];

    int ans = N;
//ここでまず最大の値をとりあえず記録する。
    for(int bit = 0; bit < (1<<N); bit++){
        //bit変換
        vector<bool> exist(M);
        //すべてあるかどうかチェックするvector
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(bit >> i & 1){
                //これでそれぞれの桁について見る
            
                cnt++;
                for(int j  =0; j < M; j++){
                    if(S[i][j]=='o')exist[j]=true;
                }
            }
        }

        bool all_exist = true;
        //すべてが正しいか判定する
        for(int j = 0; j < M; j++){
            if(!exist[j])all_exist = false;
        }
        //より小さい方が答え
        if(all_exist)ans = min(ans,cnt);
    }

  cout << ans << endl;
  








}
