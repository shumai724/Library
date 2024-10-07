#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

ll GCD(ll A,ll B){

    while(A >= 1 && B >= 1){
        if(A>=B){
            A = A%B;
        }else{
            B = B%A;
        }
    }

    if(A!=0)return A;
    else return B;

}


int main(){
    ll a,b,c;
    cin >> a >> b >> c;

    ll min = GCD(a,GCD(b,c));

    cout << (a/min + b/min + c/min) - 3 << endl;
    return 0;

}
