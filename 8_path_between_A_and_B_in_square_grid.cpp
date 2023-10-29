#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

char mtr[MAX][MAX];
int rows, cols;
int startX, startY, endX, endY;
bool visited[MAX][MAX];
int count1[MAX][MAX];

void inp(){
    memset(visited, false, size(visited));
    cin >> rows >> cols;
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= cols; j++){
            cin >> mtr[i][j];
            if(mtr[i][j] == 'A'){
                startX = i; startY = j;
            } else if(mtr[i][j] == 'B'){
                endX = i; endY = j;
            }
        }
    }
}

int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
void dfs(int start, int end){
    visited[start][end] = true;
    for(int k = 1; k <= 4; k++){
        int next1 = start + dx[k];
        int next2 = end + dy[k];
        if(next1 >= 1 && next1 <= rows && next2 >= 1 && next2 <= cols && mtr[next1][next2] != 'x' && visited[next1][next2] == false){
            visited[next1][next2] = true;
            dfs(next1, next2);
        }
    }
}

bool check_by_dfs(int start, int end){
    if(mtr[start][end] == 'B'){
        return true;
    }
    visited[start][end] = true;
    for(int k = 1; k <= 4; k++){
        int n1 = start + dx[k];
        int n2 = end + dy[k];
        if(n1 >= 1 && n1 <= rows && n2 >= 1 && n2 <= cols && mtr[n1][n2] != 'x' && visited[n1][n2] == false){
            if(check_by_dfs(n1, n2)){
                return true;
            }
        }
    }
    return false;
}

// Số bước đi ngắn nhất giữa 2 điểm dùng BFS()
void bfs(int start, int end){
    memset(count1, 0, size(mtr));
    //Lưu số bước từ start đến ô đó

    queue<pair<int,int>> q;
    q.push({start, end});
    visited[start][end] = true;
    while(!q.empty()){
        pair<int,int> u = q.front();
        q.pop();
        for(int i = 1; i <= 4; i++){
            int x = u.first + dx[i];
            int y = u.second + dy[i];
            if(x >= 1 && x <= rows && y >= 1 && y <= cols && mtr[x][y] != 'x' && visited[x][y] == false){
                visited[x][y] = true;
                count1[x][y] = count1[u.first][u.second] + 1;
                q.push({x, y});
            }
        }
    }
}

int main(){
    inp();
    //dfs(startX, startY);
    bfs(startX, startY);
    if(visited[endX][endY] == true ){
        cout << count1[endX][endY] << endl;
    } else cout << "Khong co duong di tu A den B" << endl;
    return 0;
}

//Aooxoo
//oxoooo
//oxoooo
//ooooxx
//Bxooxo
//oxoxxx

