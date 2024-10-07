#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())


bool prime_check(int x){

    for(int i = 2; i*i <= x; i++){
        if(x%i == 0){
            return false;
        }
    }

    return true;
}

int main(){
    int Q;
    cin >> Q;
    rep(i,Q){
        int xx;
        cin >> xx;
        if(prime_check(xx))cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }

}