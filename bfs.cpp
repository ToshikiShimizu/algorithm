#include<bits/stdc++.h>
#define INF 1e9
using namespace std;

vector<vector<int> > BFS(vector<vector<int> > valid, int x, int y){
    vector<vector<int> > dist(valid.size(), vector<int>(valid[0].size(), INF));
    queue<tuple<int,int,int>> Q;
    tuple<int,int,int> t;
    int d;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
    if (valid[x][y])Q.push(make_tuple(x, y, 0));
    while(!Q.empty()){
        t = Q.front();Q.pop();
        x = get<0>(t);y = get<1>(t);d = get<2>(t);
        if (dist[x][y] <= d)continue;
        dist[x][y] = d;
        for (int i=0;i<4;i++){
            if (0<=x+dx[i] && x+dx[i]<valid.size() && 0<=y+dy[i] && y+dy[i]<valid[0].size()){
                if(valid[x+dx[i]][y+dy[i]]){
                    int d_next = d;
                    d_next++;   
                    if (dist[x+dx[i]][y+dy[i]]>d_next)
                        Q.push(make_tuple(x+dx[i],y+dy[i],d_next));
                }
            }
        }
    }
    return dist;
}

void print_vector(vector<vector<int> > vector){
    for (int i = 0; i < vector.size(); i++){
        for (int j = 0; j < vector[i].size(); j++)
            cout << vector[i][j] << " ";
        cout << endl;
    }
}

int main(){
    int H,W;
    H = 10;
    W = 8;
    vector<vector<int> > valid(H, vector<int> (W, 1) );
    valid[4][4]=0;
    print_vector(BFS(valid,4 ,5));
}