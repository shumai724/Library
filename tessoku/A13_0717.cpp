#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int N,K,A[100009],R[100009];

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++)cin >> A[i];
    //尺取り法

    for(int i = 1; i <= N-1; i++){
        if(i == 0)R[i] = 0;
        else R[i] = R[i-1];

        //ギリギリまで増やす
        while(R[i] < N && A[R[i]+1] - A[i] <= K){
            R[i] += 1;
        }

    }
    ll ans = 0;
    for(int i = 1; i <= N-1; i++){
        ans += (R[i] - i);
    }

    cout << ans << "\n";


}