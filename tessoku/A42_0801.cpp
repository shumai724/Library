#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k,n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N),B(N);
    rep(i,0,N)cin >> A[i] >> B[i];

    int ans = 0;

    rep(i,0,100){
        rep(j,0,100){

            int cnt = 0;

            for(int ii = 0; ii < N; ii++){
                if(A[ii]-i <= K && B[ii]-j <= K && A[ii] >= i && B[ii] >= j)cnt++;

            }

            ans = max(ans,cnt);



        }
    }

    cout << ans << endl;
    return 0;
    


}