#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)




int main(){
    int N;
    cin >> N;

    vector<int> A(N+1),B(N+1);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        B[A[i]] = i;

    }
    int cnt = 0;
    vector<pair<int,int>> vec;

    for(int i = 1; i <= N; i++){
        if(A[i]!=i){
            cnt++;
            int j = B[i];
            vec.push_back({i,j});

            A[j] = A[i];
            B[A[i]] = j;
            A[i] = B[i] = i;

        }
    }

    cout << vec.size() << endl;
    for(auto &p : vec) cout << p.first << " " << p.second << "\n";





}
