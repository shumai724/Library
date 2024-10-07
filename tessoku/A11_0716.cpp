#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int N,X,A[100009];

int binary_search(int x){
    int L = 1, R = N;

    while(L <= R){
        int M = (L+R)/2;
        if(x < A[M])R = M - 1;
        if(x == A[M])return M;
        if(x > A[M])L = M + 1;

    }
    return -1;
}

int main(){
    cin >> N >> X;
    rep(i,N)cin >> A[i];

    int Ans = binary_search(X);

    cout << Ans + 1 << "\n";

    
    
}