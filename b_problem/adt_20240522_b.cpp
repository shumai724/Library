//https://atcoder.jp/contests/adt_easy_20240522_1/editorial/6441//


#include<bits/stdc++.h>
using namespace std;




int main(){
  int n,m;
  cin >> n >> m;

  vector<vector<int>>  A(m,vector<int>(n)),vec(n,vector<int>(n));

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> A[i][j];
    }
  }
  int ans = 0;


  for(int i = 1; i <= n; i++){
    for(int j = i+1;j <= n; j++){
      bool flag = false;
      for(int k = 0; k < m; k++){
        for(int l = 0;l < n-1;l++){
          if(A[k][l]==i && A[k][l+1] == j)flag = true;
          if(A[k][l]==j && A[k][l+1] == i)flag = true;
        }
      }

      if(!flag)ans++;



    }
  }

  cout << ans << endl;
  return 0;






}