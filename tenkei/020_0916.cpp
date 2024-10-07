#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    ll a,b,c;
    cin >> a >> b >> c;

    ll cc = c;

    for(int i = 2; i <= b; i++){
        cc *= c;

    }

    if(a<cc)cout << "Yes" << endl;
    else cout << "No" << endl;
}
