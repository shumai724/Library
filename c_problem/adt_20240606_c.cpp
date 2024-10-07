#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;



int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    ll sum = 0;

    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        sum += A[i];
        }

    sort(A.begin(),A.end());
    vector<int> B(N,sum/N);
    for(int i = 0; i < sum% N; i++){
        b[n-1-i]++;
    }
    ll ans = 0;

    for(int i = 0; i < N; i++){
        ans +=abs(a[i]-b[i]); 
    }

    cout << ans << endl;




}
