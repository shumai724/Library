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


int main(){
    ll a,b;

    cin >> a >> b;
    cout << Power(a,b,1000000007) << "\n";
    return 0;

}