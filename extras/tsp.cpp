#include <iostream>
#include <climits>
using namespace std;

int n;
int cost[10][10];
int dp[20][10];

int min(int a, int b){
    return (a < b) ? a : b;
}

int tsp(int mask, int pos){
    if(mask == (1 << n) - 1){
        return cost[pos][0];
    }

    if(dp[mask][pos] != -1){
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    for(int i = 0; i < n; i++){
        if((mask & (1 << i)) == 0){
            int temp = cost[pos][i] + tsp(mask | (1 << i), i);
            ans = min(ans, temp);
        }
    }

    dp[mask][pos] = ans;
    return ans;
}

int main(){
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 10; j++){
            dp[i][j] = -1;
        }
    }

    cout << "Minimum cost: " << tsp(1, 0);

    return 0;
}
