#include <bits/stdc++.h>
using namespace std;
char matrix[10001][10001];
int row, col;
bool visited[10001][10001];

int dx[] = {0, -1, 0, 0, 1};
int dy[] = {0, 0, 1, -1, 0};

void inp(){
    memset(visited, false, sizeof(visited));
    cin >> row >> col;
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            cin >> matrix[i][j];
        }
    }
}
bool safe(int i, int j){
    if(i >= 1 && i <= row && j >= 1 && j <= col){
        return true;
    }
    return false;
}
void dfs(int i, int j){
    visited[i][j] = true;
    for(int x = 1; x <= 4; x++){
        int i1 = i + dx[x];
        int j1 = j + dy[x];
        if(safe(i1, j1) && matrix[i1][j1] == 'x' && visited[i1][j1] == false ){
            dfs(i1, j1);
        }
    }
}

void connectedComponent(){
    int ans = 0;
    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            if(!visited[i][j] && matrix[i][j] == 'x'){
                ++ans;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}
int main(){
    inp();
    connectedComponent();
}