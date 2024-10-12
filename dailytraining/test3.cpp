#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int a;
    int N;
    cin >> a >> N;

    ll X = 1;
    int turn = 0;
    bool ck = false;
    while(true){
        if(X>=10 && X%10!=0){
            int c = X%10;
            ll p = X;
            int cnt = 0;
            while(p!=0){
                cnt ++;
                p /= 10;

            }
            ll after = 1;
            for(int i = 1; i < cnt; i++)after *= 10;
            after *= c;
            after += X/10;

            if(after == N){
                ck = true;
                turn += 1;
                break;

            } 
        }


        X *= a;
        if(X==N){
            ck = true;
            turn += 1;
            break;
        }


    }

    if(ck)cout << turn << "\n";
    else cout << -1 << "\n";
    return 0;






}
