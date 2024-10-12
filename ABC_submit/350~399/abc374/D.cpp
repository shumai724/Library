#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N,S,T;
    cin >> N >> S >> T;

    vector<double> A(N),B(N),C(N),D(N);
    rep(i,N)cin >> A[i] >> B[i] >> C[i] >> D[i];

    long double ans = 1e18;

    vector<int> ss(N);
    rep(i,N)ss[i] = i;

    do{

        for(int i = 0 ; i < (1<<N); i++){
            long double dis = 0;
            int now_x = 0,now_y = 0;

            for(int j = 0; j < N; j++){

                if(i & (1<<j)){
                    dis += sqrt((A[ss[j]]-now_x)*(A[ss[j]]-now_x)+(B[ss[j]]-now_y)*(B[ss[j]]-now_y)) / S;

                    dis += sqrt((A[ss[j]]-C[ss[j]])*(A[ss[j]]-C[ss[j]])+(B[ss[j]]-D[ss[j]])*(B[ss[j]]-D[ss[j]])) / T;

                    now_x = C[ss[j]];
                    now_y = D[ss[j]]; 
                }else{
                    dis += sqrt((C[ss[j]]-now_x)*(C[ss[j]]-now_x)+(D[ss[j]]-now_y)*(D[ss[j]]-now_y))  / S;

                    dis += sqrt((A[ss[j]]-C[ss[j]])*(A[ss[j]]-C[ss[j]])+(B[ss[j]]-D[ss[j]])*(B[ss[j]]-D[ss[j]])) / T;

                    now_x = A[ss[j]];
                    now_y = B[ss[j]];
                }

            }

            ans = min(ans,dis);

        }



    }while(next_permutation(ss.begin(),ss.end()));

    cout << fixed << setprecision(20);

    cout << ans << "\n";
    return 0;

}