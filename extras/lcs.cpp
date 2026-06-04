#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    int n = str1.length();
    int m = str2.length();

    int LCS[100][100];

    for(int i = 0; i <= n; i++){
        LCS[i][0] = 0;
    }
    for(int j = 0; j <= m; j++){
        LCS[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i-1] == str2[j-1]){
                LCS[i][j] = 1 + LCS[i-1][j-1];
            } else {
                if(LCS[i-1][j] > LCS[i][j-1]){
                    LCS[i][j] = LCS[i-1][j];
                } else {
                    LCS[i][j] = LCS[i][j-1];
                }
            }
        }
    }

    cout << "\nLCS Length: " << LCS[n][m] << endl;

    char lcs[100];
    int index = LCS[n][m];
    lcs[index] = '\0';

    int i = n, j = m;

    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            lcs[index - 1] = str1[i-1];
            i--;
            j--;
            index--;
        }
        else if(LCS[i-1][j] > LCS[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    cout << "LCS String: " << lcs << endl;

    return 0;
}
