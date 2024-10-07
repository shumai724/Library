#include <bits/stdc++.h>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N;
    cin >> N;
    if(N%2==1)return 0;

    vector<char> A(N,')');

    for(int i = 0; i < N/2; i++){
        A[i] = '(';
    }

    do{
        string S = "";
        int score = 0;
        bool ck = true;
        for(int i = 0; i < N; i++){
            S += A[i];
            if(A[i]=='(')score++;
            else score--;
            if(score<0)ck = false;
        }

        if(score!=0)ck = false;

        if(ck)cout << S << endl;
    }while(next_permutation(A.begin(),A.end()));

    return 0;


}