#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())

int main(){
    int N;
    char C;
    cin >> N >> C;
    string A;
    cin >> A;
    int score = 0;
    rep(i,N){
        if(A[i]=='B')score += 1;
        if(A[i]=='R')score += 2;
    }

    char end;

    if(score %3 == 0)end = 'W';
    if(score %3 == 1)end = 'B';
    if(score %3 == 2)end = 'R';

    if(C==end)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;


}