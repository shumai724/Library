#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    ll N,X,Y;
    cin >> N >> X >> Y;

    vector<ll> A(N),B(N);
    rep(i,N){
        int aa;
        cin >> aa;
        A[i] = aa;

    }
    rep(i,N){
        int bb;
        cin >> bb;
        B[i] = bb;
    }
    SORT(A),SORT(B);
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    ll A_limit = X;
    ll B_limit = Y;

    int ans = 1e6;


    for(int i = 0; i < N; i++){
        if(A_limit < A[i]){
            ans = i+1;
            break;
        }else if(i==N-1){
            ans = N;
            
        }
        
        else{
            A_limit -= A[i];
        }

    }


    for(int i = 0; i < N; i++){
        if(B_limit < B[i]){
            ans = min(ans,i+1);
            break;
        }
        
        else{
            B_limit -= B[i];
        }

        

    }

    cout << ans << "\n";














    

}
