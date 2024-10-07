#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

ll GCD(ll A,ll B){
    if(B==0){
        return A;
    }else{
       return GCD(B,A%B);
    }
}


int main(){
    ll A,B;
    cin >> A >> B;

    ll gg = gcd(A,B);

    


    
}