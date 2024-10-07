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
    vector<vector<int>> sum(1009,vector<int>(1009,0)),ans(1009,vector<int>(1009,0));
    rep(i,N){
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry;
        sum[lx][ly] += 1;
        sum[rx][ry] += 1;
        sum[rx][ly] -= 1;
        sum[lx][ry] -= 1;

    }

    for(int i = 0; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            sum[i][j] += sum[i][j-1];
        }
    }

    for(int j = 0; j <= 1000; j++){
        for(int i = 1; i <= 1000; i++){
            sum[i][j] += sum[i-1][j];
        }
    }

    vector<int> A(N+1,0);

    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            A[sum[i][j]] += 1;
        }
    }

    for(int i = 1; i <= N; i++){
        cout << A[i] << endl;
    }
    
}