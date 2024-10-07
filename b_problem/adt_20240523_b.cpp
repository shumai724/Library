#include<bits/stdc++.h>
using namespace std;


int N,M;





int main(){
  cin >> N >> M;
  int P[N];
  bool func[N][M] ={};
  for(int i = 0; i < n; i++){
    cin >> P[i];
    int c;
    cin >> c;
    for(int j = 0; j < c; j++){
      int f;
      cin >> f;
      f--;
      func[i][f] = true;
    }
  }

  bool ans = false;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N ;j++){
      bool hantei1 = false;
      bool hantei2 = true;
      bool hantei3 = false;

      if(P[i] >= P[j])hantei1 = true;

      for(int k = 0; k < m; k++){
        if(func[i][k] && !func[i][j]) hantei2 = false;
      }

      if(P[i]>P[j]) hantei3 = true;

      for(int k = 0; k < M; k++){
        if(func[j][k] && !func[i][k]) hantei3 = true;
      }

      if(hantei1 && hantei2 && hantei3) ans = true;




    }

  }

  if(ans == true) cout << "Yes" << endl;
  else cout << "No" << endl;





}