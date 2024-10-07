#include <bits/stdc++.h>
#include <fstream>

using namespace std;
using ll  = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i <= (int)(n); i++)
#define SORT(a) sort(a.begin(), a.end())
#define REV(a) reverse(a.begin(),a.end())


int main(){
    //入力
    int N,M,V;
    cin >> N >> M >> V;
    vector<vector<char>> S(N,vector<char>(N));
    vector<vector<char>> T(N,vector<char>(N));
    //たこ焼きをキャッチする座標

    vector<pair<int,int>> catch_point;

    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> S[i][j];
        }
    }
    //たこ焼きをドロップする座標
    vector<pair<int,int>> drop_point;

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            cin >> T[i][j];
        }
    }

    set<pair<int,int>> catch_set,drop_set;

    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(S[i][j]=='1' && T[i][j]=='0'){
                catch_point.push_back(make_pair(i,j));
                catch_set.insert(make_pair(i,j));
            }

            if(S[i][j]=='0' && T[i][j]=='1'){
                drop_point.push_back(make_pair(i,j));
                drop_set.insert(make_pair(i,j));
            }
        }
    }

    //armspointが頂点数

    int armspoint = V;
    ofstream file1("output1.txt");


    cout << armspoint << endl;
    file1 << armspoint << endl;

    vector<bool> Holding(armspoint,false);

    rep(i,armspoint - 1){
        cout << i << " " << 2;
    }

    int root_x = 0,root_y = 0;
//ここで根に関する情報を持たせて出力

    cout << root_x << " " << root_y << endl;
    file1 << root_x << " " << root_y << endl;


    vector<string> ans;

    int now_x = root_x;
    int now_y = root_y;

    vector<pair<int,int>> arms_loc(armspoint);

    for(int i = 1; i < armspoint; i++){
        arms_loc[i] = make_pair(0,i*2);
    }

    //X方向とY方向に移動させるときのベクトルを作る
    vector<int> DX = {0,1,0,-1,0};
    vector<int> DY = {1,0,-1,0,0};
    vector<char> DIR = {'R','D','L','U','.'};

    while(true){
        string ss = "";

        vector<int> can_catch_arms;

        int score = 0;
        int idou_hantei = 0;

        for(int i = 0 ; i < 5; i++){
            int current_point = 0;
            for(int ii = 0 ; ii < armspoint; ii++){

                int xx = arms_loc[ii].first + DX[i];
                int yy = arms_loc[ii].second + DY[i];

                if(xx < 0 || xx >= N)continue;
                if(yy < 0 || yy >= N)continue;

                if(Holding[ii]==false){
                    if(S[xx][yy] == '1' && T[xx][yy]=='0'){
                        current_point += 1;
                    }
                }

                if(Holding[ii]==true){
                    if(S[xx][yy] == '0' && T[xx][yy]=='1'){
                        current_point += 1;
                    }

                }

            }
            if(current_point > score){
                score = current_point;
                idou_hantei = i;
            }

        }

        vector<int> p_catch(armspoint,false);

        if(score!=0){
            ss += DIR[idou_hantei];
            for(int ii = 0 ; ii < armspoint; ii++){

                int xx = arms_loc[ii].first + DX[idou_hantei];
                int yy = arms_loc[ii].second + DY[idou_hantei];

                arms_loc[ii] = make_pair(xx,yy);

                if(xx < 0 || xx >= N)continue;
                if(yy < 0 || yy >= N)continue;


                if(Holding[ii]==false){
                    if(S[xx][yy] == '1' && T[xx][yy]=='0'){
                        S[xx][yy] = '0';
                        p_catch[ii] = true;
                        Holding[ii] = true;
                    }
                }

                if(Holding[ii]==true){
                    if(S[xx][yy] == '0' && T[xx][yy]=='1'){
                        p_catch[ii] = true;
                        Holding[ii] = false;

                    }

                }



            }

        }else{
            for(int i = 0 ; i < armspoint; i++){

            }

        }

        for(int i = 1 ; i < armspoint; i++){
            ss += ".";
        }

        for(int i = 0 ; i < armspoint; i++){
            if(p_catch[i]){
                ss += "P";
            }else{
                ss += ".";
            }


        }

        ans.push_back(ss);

        if()



    }

    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << endl;
        file1 << ans[i] << endl;
    }

    file1.close();

    return 0;



























}