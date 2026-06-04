#include<bits/stdc++.h>
using namespace std;

int main(){
    string str1, str2;

    cout<<"Enter a string: ";
    cin>>str1;

    cout<<"Enter second string: ";
    cin>>str2;

    int n = str1.length();
    int m = str2.length();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int index = dp[n][m];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = n, j = m;

    while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
            index--;
            lcs[index] = str1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    cout<<"LCS: ";
    for(int i=0;i<dp[n][m];i++){
        cout<<lcs[i]<<" ";
    }

    cout<<endl<<"Length: "<<dp[n][m];

    return 0;
}
/*TC: O(nm)
SC: O(nm)*/
