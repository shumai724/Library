#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())
int main(){
    int N,K;
    cin >> N >> K;

    vector<int> A(N);
    rep(i,N)cin >> A[i];

    int ans = 0;
    map<int,int> M;
    int cnt = 0;
    rep(i,N){
        if(M.count(A[i])){
            M[A[i]] += 1;
        }else{
            M[A[i]] = 1;
            while(M.size() > K){
                M[A[cnt]] -= 1;
                if(M[A[cnt]]==0){
                    M.erase(A[cnt]);
                }
                cnt++;
            }
        }

        ans = max(ans,i-cnt+1);


    }

    cout << ans << endl;

    
}