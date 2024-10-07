#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())


int main(){
    int N;
    cin >> N;
    int A[100009],dp[100009];

    for(int i = 1; i <= N; i++)cin >> A[i];

    int len = 0,L[100009];

    //動的計画法
    for(int i = 1; i <= N; i++){
        int pos = lower_bound(L+1, L+len+1, A[i]) - L;
        dp[i] = pos;

        //配列Lを更新

        L[dp[i]] = A[i];
        if(dp[i] > len)len += 1;
    }

    cout << len << "\n";



}