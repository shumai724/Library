#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k,n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,0,N)cin >> A[i];

    int XOR_sum = A[0];

    for(int i = 1; i < N; i++) XOR_sum = (XOR_sum ^ A[i]);

    if(XOR_sum!=0)cout << "First" << "\n";
    else cout << "Second" << "\n";

    return 0;


}