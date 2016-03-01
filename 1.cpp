#include <iostream>
using namespace std;
 
char map[10000][10000];

int main()
{
    int i, j, m, n, tot;
    char ch = 'A';
    cin >> m >> n;
 
    for(i = 0; i < m; i++)
       for (j = 0; j < n; j++)
            map[i][j] = '0';
 
    i = j = tot = 0;
    map[i][j] = 'A';
    while (tot < n*m-1){//注意这里的判断！
          while (j+1 < n && map[i][j+1] == '0'){
                if (ch >= 90)  ch -= 26;
                j = j + 1;
                ch = ch + 1;
                map[i][j] = ch;
                tot = tot + 1;
          }
          while (i+1 < m && map[i+1][j] == '0'){
                if (ch >= 90)  ch -= 26;
                i = i + 1;
                ch = ch + 1;
                map[i][j] = ch;
                tot = tot + 1;
          }
          while (j-1 >= 0 && map[i][j-1] == '0'){
                if (ch >= 90)  ch -= 26;
                j = j - 1;
                ch = ch + 1;
                map[i][j] = ch;
                tot = tot + 1;
          }
          while (i-1 >= 0 && map[i-1][j] == '0'){
                if (ch >= 90)  ch -= 26;
                i = i - 1;
                ch = ch + 1;
                map[i][j] = ch;
                tot = tot + 1;
          }
    }
 
    for (i = 0; i < m; i++){
       for (j = 0; j < n; j++)
            cout << "   " << map[i][j];
       cout << endl;
    }
 
}
