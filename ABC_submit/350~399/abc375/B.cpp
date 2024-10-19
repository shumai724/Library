#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int main(){
    int N;
    cin >> N;

    vector<double> X(N),Y(N);
    rep(i,N){
        cin >> X[i] >> Y[i];
        
    }

    double ans = 0;

    double now_x = 0,now_y = 0;

    rep(i,N){
        ans += sqrt((X[i]-now_x)*(X[i]-now_x) + (Y[i]-now_y)*(Y[i]-now_y));
        now_x = X[i],now_y = Y[i];
    }

    ans += sqrt((now_x)*(now_x) + (now_y)*(now_y));


    cout << setprecision(20);
    cout << ans << "\n";
    return 0;

}