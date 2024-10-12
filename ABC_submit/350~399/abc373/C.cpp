#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())
int main(){
    int N;
    cin >> N;
    int max_a = -1e9;
    int max_b = -1e9;
    rep(i,N){
        int a;
        cin >> a;
        max_a = max(max_a,a);

    }
    rep(i,N){
        int b;
        cin >> b;
        max_b = max(max_b,b);
    }

    cout << max_a + max_b << endl;
    return 0;
}