#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    vector<int> T;

    for(int i = 0; i < N; i++)T.push_back(A[i]);
    sort(T.begin(),T.end());

    T.erase(unique(T.begin(),T.end()),T.end());

    for(int i = 0; i < N; i++){
        B[i] = lower_bound(T.begin(),T.end(),A[i]) - T.begin();
        B[i] += 1;
    }

    for(int i = 0; i < N; i++){
        cout << B[i];
        if(i==N-1)cout << "\n";
        else cout << " ";
    }

    return 0;

}