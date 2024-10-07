#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())



int N,M;
int A[409],B[409],C[409];
MaximumFlow Z;

int main(){
    cin >> N >> M;
    for(int i = 1; i <= M; i++)cin >> A[i] >> B[i] >> C[i];

    Z.init(N);

    for(int i = 1; i <= M; i++){
        Z.add_edge(A[i],B[i],C[i]);
    }

    cout << Z.max_flow(1,N) << endl;
    return 0;
}

