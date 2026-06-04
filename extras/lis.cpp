#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int dp[n];
    for(int i = 0; i < n; i++){
        dp[i] = 1;
    }


    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maximum = dp[0];
    for(int i = 1; i < n; i++){
        if(dp[i] > maximum){
            maximum = dp[i];
        }
    }

    cout << "Longest Increasing Subsequence length is: " << maximum;

    return 0;
}
