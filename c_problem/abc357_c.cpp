#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using ll  = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main(){
    int N;
    cin >> N;
    int k = 1;
    for(int i = 0; i < N ;i++) k *= 3;

    vector<vector<char>> vec(k,vector<char>(k,'#'));

    int c = 1;


    for(int i = 0; i < N; i++){
        c *= 3;
        for(int l = 0; l < c; l++){
            for(int m = 0; m < c; m++){
                vec[l][m]=vec[l%(c/3)][m%(c/3)];
            }
        }
        for(int l = c/3; l < c*2/3; l++){
            for(int m = c/3; m < c*2/3; m++){
                vec[l][m]='.';
            }
        }

    }

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            cout << vec[i][j];
        }
        cout << endl;
    }










}
