// Đếm số thành phần liên thông - Kiểm tra tính liên thông của đồ thị
#include <bits/stdc++.h>
using namespace std;

vector<int> dsk[10001];
bool visited[10001];
int V, E;

void inp(){
    memset(visited, false, size(visited));
    cin >> V >> E;
    for(int i = 1; i <= E; i++){
        int x, y;
        cin >> x >> y;
        dsk[x].emplace_back(y);
        dsk[y].emplace_back(x);
    }
}
void dfs(int i){
    cout << i << " ";
    visited[i] = true;
    for(auto x : dsk[i]){
        if(!visited[x]) dfs(x);
    }
}

int connectedComponent(){
    int ans = 0;
    for(int i = 1; i <= V; i++){
        if(!visited[i]){
            ++ans;
            cout << "Cac dinh thuoc thanh phan lien thong so " << ans << "la: ";
            dfs(i);
            cout << endl;
        }
    }
    return ans;
}
int main(){
    inp();
    cout << connectedComponent() << endl;
    return 0;
}