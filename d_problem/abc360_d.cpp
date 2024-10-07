#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())



int main(){
    ll N,T;
    cin >> N >> T;
    string S;
    cin >> S;
    vector<ll> x1,x2;
    rep(i,N){
        ll x;
        cin >> x;
        if(S[i]== '1'){
            x1.push_back(x);
        }else{
            x2.push_back(x);
        }

    }

    SORT(x1);
    SORT(x2);
    int l = 0, r = 0;
    ll ans = 0;

    for(int i = 0; i < (int)x1.size(); i++){
        while(l < (int)x2.size() && x2[l] < x1[i])l++;
        while(r < (int)x2.size() && x2[r] <= x1[i] + 2* T )r++;
        ans += r-l;
    }

    cout << ans << endl;
    return 0;







}
