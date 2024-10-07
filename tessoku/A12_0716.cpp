#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int N,K,A[100009];

bool check(ll x){
    ll sum = 0;
    for(int i = 0; i < N; i++){
        sum += x/A[i];
    }
    if(sum >= K)return true;
    else return false;
}

int main(){
    cin >> N >> K;

    rep(i,N)cin >> A[i];

    ll left = 0;

    ll right = 1000000001;

    while(left < right){
        ll mid = (left + right)/2;
        bool ans = check(mid);
        if(ans==false)left = mid+1;
        else right = mid;

    }

    cout << left << "\n";

}