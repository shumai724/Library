#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main(){
    int N;
    cin >> N;
    vector<int> A(N),B(N-1);
    rep(i,N)cin >> A[i];
    rep(i,N-1)cin >> B[i];

    SORT(A),SORT(B);
    REV(A),REV(B);
    int aa = 0, bb = 0;
    int ans = -1;
    int cnt = 0;
    while(true){
        int a_siz = A[aa];
        int b_siz = B[bb];
        if(a_siz <= b_siz){
            aa++;
            bb++;
        }else{
            cnt += 1;
            ans = a_siz;
            aa++;
        }

        if(aa>=N && bb>=N-1)break;
    }
    if(cnt != 1)ans = -1;

    cout << ans << "\n";





}