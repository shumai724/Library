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
    int N,Q;
    cin >> N >> Q;

    int L = 1,R = 2;
    ll ans = 0;
    rep(_,Q){
        char c;
        int j;
        cin >> c >> j;
        j %= N;
        bool ck1 = true,ck2 = true;
        if(c=='L'){
            int clo_dis = abs(L - j);
            int no_clo_dis = N - clo_dis;

            if(L + clo_dis >= N) j += N;

            if(L - no_clo_dis < 0){
                L += N;
                R += N;
            }

            if(clo_dis < no_clo_dis){
                if(L > R && j > L){
                    ans += clo_dis;
                }else{
                    ans += no_clo_dis;
                }
            }else{
                if(R > L && L > j){
                    ans += no_clo_dis;
                }else{
                    ans += clo_dis;
                }

            }

            L = j%N;



        }

        if(c=='R'){
            int clo_dis = abs(R - j);
            int no_clo_dis = N - clo_dis;

            if(R + clo_dis >= N) j += N;

            if(R - no_clo_dis < 0){
                L += N;
                R += N;
            }

            if(clo_dis < no_clo_dis){
                if(R > L && j > R){
                    ans += clo_dis;
                }else{
                    ans += no_clo_dis;
                }
            }else{
                if(L > R && R > j){
                    ans += no_clo_dis;
                }else{
                    ans += clo_dis;
                }

            }

            R = j%N;



        }

    }

    cout << ans << "\n";


}