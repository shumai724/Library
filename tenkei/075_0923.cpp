#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

ll is_prime(ll x){
    for(ll i = 2; i*i <= x; i++){
        if(x%i==0){
            return i;
        }
    }
    return -1;
}



int main(){
    ll N;
    cin >> N;
    
    int cnt = 0;

    while(true){
        if(is_prime(N) == -1)break;
        else{
            cnt++;
            N /= is_prime(N);
        }
    }

    for(int i = 0; i <= 63; i++){
        ll cnt_a = (1<<i) - 1;
        if(cnt <= cnt_a){
            cout << i << endl;
            return 0;
        }
    }

    return 0;



    
}