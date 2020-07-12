#include<iostream>
using namespace std;
int n;

char grid[100][100];
bool visited[100][100] = {0};
bool valid(int i,int j){
    return (i >= 0 && i < n && j >= 0 && j < n);
}
void dfs(int i,int j){
    if(!valid(i,j) || grid[i][j] == '.' || visited[i][j]) return;
    visited[i][j] = 1;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

int cntShips(){
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 'x' && !visited[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    for(int times = 0 ;times < t ; times++){
        //inserting case
        cin>>n;
        for (int i = 0; i <n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> grid[i][j];
            }
        }
        cout << "Case " << times+1 <<": " << cntShips() << endl;

        for (int i = 0; i <n; ++i) {
            for (int j = 0; j < n; ++j) {
               visited[i][j] = 0;
            }
        }

    }
}
