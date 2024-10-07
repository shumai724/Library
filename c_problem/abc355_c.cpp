#include<bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc355/tasks/abc355_c




int main(){
    int N,T;

    cin >> N >>T;

    vector<int> A(T),yoko(N),tate(N),naname(2);
    int x,y;

    for(int i = 0; i < T; i++){
        int a;
        cin >> a;

        x = (a-1) / N;
        y = (a-1) % N;

        //横方向
        yoko[x] += 1;
        if(yoko[x]==N){
            cout << i+1 << endl;
            return 0;
        }


        //縦方向
        tate[y] +=1;
        if(tate[y]==N){
            cout << i+1 << endl;
            return 0;
        }
        //右斜め
        if(x==y){
            naname.at(0) +=1;
            if(naname.at(0) == N){
                cout << i+1 << endl;
                return 0;
            }
        }
        //左斜め
        if(x + y == N - 1){
            naname.at(1) += 1;
            if(naname.at(1) == N){
                cout << i+1 << endl;
                return 0;
            }
        }


        




    }

    cout << -1 << endl;
    return 0;

    






}