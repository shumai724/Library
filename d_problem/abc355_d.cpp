#include<bits/stdc++.h>
using namespace std;
//https://atcoder.jp/contests/abc355/tasks/abc355_d





int main(){
  int N;
  cin >> N;

  vector<int> L(N),R(N);

  for(int i = 0; i < N; i++){
  cin >> L[i] >> R[i];
  }

  sort(L.begin(),L.end());
  sort(R.begin(),R.end());

  int cnt = N * (N-1)/2;
  int j = 0;

  for(int i = 0; i < N; i++){
    while(L[j] < R[i]){
      j += 1;
    }
    cnt -= j;
  }


  cout << cnt << endl;



}