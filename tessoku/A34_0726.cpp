#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i,k,n) for (int i = k; i < (int)(n); i++)
#define rrep(i,k,n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N,X,Y;
    cin >> N >> X >> Y;
    vector<int> A(N+1);
    rrep(i,1,N)cin >> A[i];

    int Grundy[100009];

    //[Grundy数を求める]
    //変数 Grundy[i] 石がi個の時のGrudy数
    //変数 Transit[i] Grundy数がiとなるような遷移ができるか

    for(int i = 0; i <= 100000; i++){
        bool Transit[3] = {false,false,false};
        if(i >= X)Transit[Grundy[i-X]] = true;
        if(i >= Y)Transit[Grundy[i-Y]] = true;

        if(Transit[0]==false)Grundy[i] = 0;
        else if(Transit[1]==false)Grundy[i] = 1;
        else Grundy[i] = 2;
    }

    int XOR_sum = 0;
    for(int i = 1; i <= N; i++){
        XOR_sum = (XOR_sum ^ Grundy[A[i]]);
    }

    if(XOR_sum!=0)cout << "First" << "\n";
    else cout << "Second" << "\n";
    return 0;

}