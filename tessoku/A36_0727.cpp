#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k,n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,K;
    cin >> N >> K;

    if(2*(N-1) <= K && K%2==0)cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}