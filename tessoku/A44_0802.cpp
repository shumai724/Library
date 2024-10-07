#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,Q;
    cin >> N >> Q;

    vector<int> A(N);

    for(int i = 0; i < N; i++){
        A[i] = i+1;
    }

    bool ck = true;


    rep(i,Q){
        int qq;
        cin >> qq;
        if(qq==1){
            int x,y;
            cin >> x >> y;
            if(ck==false){
                A[N-x] = y;
            }else{
                A[x-1] = y;
            }
        }

        if(qq==2){
            if(ck)ck = false;
            else ck = true;

        }

        if(qq==3){
            int x;
            cin >> x;
            if(ck==false){
                cout << A[N-x] << endl;
            }else{
                cout << A[x-1] << endl;
            }
        }
    }

    return 0;


}