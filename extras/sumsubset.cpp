#include <iostream>
using namespace std;

int main() {
    int n, sum;

    cin >> n;
    int arr[100];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> sum;

    int dp[100][100];

    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }

    for(int j = 1; j <= sum; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= sum; j++){
            if(arr[i-1] <= j){
                if(dp[i-1][j] == 1 || dp[i-1][j - arr[i-1]] == 1){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 0;
                }
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    if(dp[n][sum] == 0){
        cout << "No subset";
        return 0;
    }

    int i = n, j = sum;

    cout << "Subset: ";

    while(i > 0 && j > 0){
        if(dp[i-1][j] == 1){
            i--;
        } else {
            cout << arr[i-1] << " ";
            j = j - arr[i-1];
            i--;
        }
    }

    return 0;
}
