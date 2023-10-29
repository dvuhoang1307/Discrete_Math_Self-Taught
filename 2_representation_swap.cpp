#include <bits/stdc++.h>
using namespace std;

int matr[1001][1001];
vector<int> v[1001];

void solve1(){
    memset(matr, 0, sizeof(matr));
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        matr[a][b] = matr[b][a] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
}
//Ok

void solve2(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(int i = 1; i <= n; i++){
        cout << i << ":";
        for(int j = 0; j < v[i].size(); j++) cout << " " << v[i][j];
        cout << endl;
    }
}
//OK

void solve3(){
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    memset(matr, 0, size(matr));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matr[i][j];
            if(j >= i & matr[i][j] > 0) v.push_back(make_pair(i, j));
        }
    }
    for(auto x : v) cout << x.first << " " << x.second << endl;
}
//OK

void solve4(){
    memset(matr, 0, sizeof(matr));

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matr[i][j];
            if(matr[i][j] > 0){
                v[i].emplace_back(j);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << i << ":";
        for(auto x : v[i]) cout << " " << x;
        cout <<endl;
    }
}
//OK

void solve5(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while(ss >> tmp) v[i].emplace_back(stoi(tmp));
    }
    memset(matr, 0, size(matr));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < v[i].size(); j++){
            matr[i][v[i][j]] = 1;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
}
//OK

void solve6(){
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while(ss >> tmp) v[i].emplace_back(stoi(tmp));
    }
    vector<pair<int, int>> res;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < v[i].size(); j++){
           if(i <= v[i][j]) res.emplace_back(make_pair(i, v[i][j]));
        }
    }
    for(auto x : res){
        cout << x.first << " " << x.second << endl;
    }
}
//OK
int main(){
    solve6();
    return 0;
}