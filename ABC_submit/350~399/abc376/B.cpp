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

    int now_l = 1,now_r = 2;
    ll ans = 0;
    rep(_,Q){
        char c;
        int j;
        cin >> c >> j;
        bool ck1 = true,ck2 = true;
        if(c=='L'){
            for(int i = 1; i <= N; i++){
                int L_tokei = (now_l + i)%N;
                int L_not = (now_l - i + N)%N;
                if(L_tokei == now_r)ck1 = false;
                if(L_not == now_r)ck2 = false;

                if(ck1 == true && L_tokei == j%N){
                    now_l = L_tokei;
                    ans += i;
                    i += N;
                }

                if(ck2 == true && L_not == j%N){
                    now_l = L_not;
                    ans += i;
                    i += N;
                }


            }
        }

        if(c=='R'){
            for(int i = 1; i <= N; i++){
                int R_tokei = (now_r + i)%N;
                int R_not = (now_r - i + N)%N;
                if(R_tokei == now_l)ck1 = false;
                if(R_not == now_l)ck2 = false;
                if(ck1 == true && R_tokei == j%N){
                    now_r = R_tokei;
                    ans += i;
                    i += N;
                }

                if(ck2 == true && R_not == j%N){
                    now_r = R_not;
                    ans += i;
                    i += N;
                }

            }
        }

    }

    cout << ans << "\n";


}