#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    ll N,A,B,C;
    cin >> N >> A >> B >> C;

    if(A < B)swap(A,B);
    if(B < C)swap(B,C);
    if(A < B)swap(A,B);

    int ans = 1e8;

    for(int i = 0; i <= N/A; i++){
        for(int j = 0; j*B + i*A <= N; j++){
            ll sum = N - i*A - j*B;
            if(sum%C == 0){

                ans = min(ans,i+j+(int)(sum/C));
            }
        }
    }

    cout << ans << endl;

}
