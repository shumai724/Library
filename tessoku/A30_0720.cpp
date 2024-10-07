#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

ll Power(ll a, ll b, ll m){
    ll answer = 1, p = a;
    for(int i = 0; i <= 30; i++){
        int wari = (1<<i);
        if((b / wari) % 2 == 1){
            answer = (answer * p) % m;
        }
        p = (p*p)%m;
    }

    return answer;
}

ll Division(ll a,ll b, ll c){
    return (a*Power(b, c-2, c)) % c;
}

int main(){
    const ll M = 1000000007;
    ll n , r;
    cin >> n >> r;

    ll a = 1;
    for(int i = 1; i <= n; i++)a = (a* i)% M;

    ll b = 1;
    for(int i = 1; i <= r; i++)b = (b * i) % M;
    for(int i = 1; i <= n-r; i++)b = (b*i) % M;

    cout << Division(a,b,M) << "\n";
    return 0;


}