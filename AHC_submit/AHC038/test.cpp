#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    int N,M,V;
    cin >> N >> M >> V;

    vector<vector<char>> S(N,vector<char>(N)),T(N,vector<char>(N));


    rep(i,N){
        rep(j,N){
            cin >> S[i][j];
        }
    }

    rep(i,N){
        rep(j,N){
            cin >> T[i][j];

        }
    }

    ofstream file1("output.txt");
/*アームの数*/
    int armspoint = V;

    cout << armspoint << "\n";
    file1 << armspoint << "\n";
    vector<pair<int,int>> arms_loc(armspoint,make_pair(0,1));

    for(int i = 1; i < armspoint; i++){

        cout << 0 << " " << 1 << "\n";
        file1 << 0 << " " << 1 << "\n";
    }

    cout << 0 << " " << 0 << "\n";
    file1 << 0 << " " << 0 << "\n";

    vector<pair<int,int>> catch_tako,drop_tako;

    rep(i,N){
        rep(j,N){
            if(S[i][j]=='1' && T[i][j] =='0')catch_tako.push_back(make_pair(i,j));
            if(S[i][j]=='0' && T[i][j] =='1')drop_tako.push_back(make_pair(i,j));

        }
    }


    /*たこ焼き持ってるか判定*/
    vector<bool> Holding(armspoint,false);

    /*答えを格納するvector*/
    vector<string> Answer;

    int c_tako = 0,d_tako = 0;
    int now_x = 0,now_y = 1;

    /*回転部分のstring rotate*/
    string rotate(armspoint - 1,'.');



    while(true){

        for(int kk = 1; kk < armspoint; kk++){
            int dx = catch_tako[c_tako].first;
            int dy = catch_tako[c_tako].second;

            if(dx > now_x){
                int diff = dx - now_x;
                for(int i = 0; i < diff; i++){
                    string ss = "D" + rotate + rotate + ".";
                    Answer.push_back(ss);
                    
                }

            }

            if(dx < now_x){
                int diff = now_x - dx;
                for(int i = 0; i < diff; i++){
                    string ss = "U" + rotate + rotate + ".";
                    Answer.push_back(ss);
                    
                }

            }

            if(dy > now_y){
                int diff = dy - now_y;
                for(int i = 0; i < diff; i++){
                    string ss = "R" + rotate + rotate + ".";
                    Answer.push_back(ss);
                    
                }

            }

            if(dy < now_y){
                int diff =  now_y - dy;
                for(int i = 0; i < diff; i++){
                    string ss = "L" + rotate + rotate + ".";
                    Answer.push_back(ss);
                    
                }

            }

            now_x = dx;
            now_y = dy;

            string ss = "." + rotate;
            for(int i = 0 ; i < armspoint; i++){
                if(i==kk)ss += "P";
                else ss += ".";
            }

            Answer.push_back(ss);

            c_tako += 1;
            if(c_tako==catch_tako.size())break;




        }

        for(int kk = 0; kk < armspoint; kk++){
            int dx = drop_tako[d_tako].first;
            int dy = drop_tako[d_tako].second;


            if(dx > now_x){
                int diff = dx - now_x;
                for(int i = 0; i < diff; i++){
                    string ss = "D" + rotate + rotate + ".";
                    Answer.push_back(ss);
                    
                }

            }

            if(dx < now_x){
                int diff =  now_x - dx;
                for(int i = 0; i < diff; i++){
                    string ss = "U" + rotate + rotate + ".";
                    Answer.push_back(ss);
                    
                }

            }

            if(dy > now_y){
                int diff = dy - now_y;
                for(int i = 0; i < diff; i++){
                    string ss = "R" + rotate + rotate + ".";
                    Answer.push_back(ss);
                    
                }

            }

            if(dy < now_y){
                int diff = now_y - dy;
                for(int i = 0; i < diff; i++){
                    string ss = "L" + rotate + rotate + ".";
                    Answer.push_back(ss);
                    
                }

            }






            now_x = dx;
            now_y = dy;

            string ss = "." + rotate;
            for(int i = 0 ; i < armspoint; i++){
                if(i==kk)ss += "P";
                else ss += ".";
            }

            Answer.push_back(ss);

            d_tako += 1;
            if(d_tako==drop_tako.size())break;




        }

        if(c_tako==catch_tako.size() && d_tako==drop_tako.size())break;



    }

    for(int i = 0; i < Answer.size(); i++){
        cout << Answer[i] << "\n";
        file1 << Answer[i] << "\n";
    }

    file1.close();

    return 0;










}