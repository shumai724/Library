#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())

int main(){
    int M;
    cin >> M;

    int N = 0;
    vector<int> A;

    while(M > 0){
        ll ck = 1;

        for(int i = 1; i <= 11; i++){
            ck = ck * 3;
            if(ck > M){
                A.push_back(i-1);
                N += 1;
                M -= ck / 3;
                break;

            }

        }
    }

    cout << N << endl;
    for(int i = 0; i < N; i++){
        if(i >= 1)cout << ' ';
        cout << A[i];
    }
    return 0;


    
}