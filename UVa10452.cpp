#include <iostream>
#include <string>
using namespace std;
int t, n, m;
string result[8];
char arr[9] = { '@','I','E','H','O','V','A','#' };
char v[9][9];
bool valid(int i, int j) {
    return(i >= 0 && i < n&& j >= 0 && j < m);
}
void findPath(int i, int j, int s, string direction) {
    if (!valid(i,j) ||v[i][j] != arr[s] || s > 7) return;
    result[s] = direction;
    findPath(i, j - 1, s + 1, "left");
    findPath(i, j + 1, s + 1, "right");
    findPath(i - 1, j, s + 1, "forth");
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int b = n - 1, f;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> v[i][j];
                if (v[i][j] == '@') { b = i, f = j; }
            }
        }
        for (int j = 0; j < m; j++) {
            if (v[n - 1][j] == '@') { f = j; break; }
        }
        findPath(b, f, 0, "o");

        cout<<result[1];
        for (int i = 2; i < 8; i++) {
            cout << " "<< result[i] ;
        }
        cout<<endl;
    }
    return 0;
}
