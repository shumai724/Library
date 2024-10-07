#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int GCD(int A,int B){

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
    int A,B;
    cin >> A >> B;

    cout << GCD(A,B) << "\n";

}