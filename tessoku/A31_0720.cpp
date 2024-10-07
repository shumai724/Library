#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    ll N;
    cin >> N;

    ll sum1 = N/3;
    ll sum2 = N/5;
    ll sum3 = N/15;

    cout << sum1 + sum2 - sum3 << "\n";
}