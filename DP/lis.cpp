#include<bits/stdc++.h>
#define maxx 100
using namespace std;
int LIS(int n,int p[maxx],int dp[maxx]){
   for(int i=0;i<n;i++){
    dp[i]=1;
   }
   for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
        if(p[j]<p[i]){
            dp[i]=max(dp[i],dp[j]+1);
        }
    }
   }

   return dp[n-1] ;
}
int main(){
int dp[maxx];
int p[maxx];
int n;
cout<<"Enter the number of elements in the array: ";
cin>>n;
cout<<"Enter the array: ";
for(int i=0;i<n;i++){
    cin>>p[i];
}
cout<<"The array is: ";
for(int i=0;i<n;i++){
    cout<<p[i]<<" ";
}
cout<<endl;
int maxElements=LIS(n,p,dp);
cout<<"The elements in LIS is: "<<maxElements<<endl;
cout<<"LIS: ";
int lis[maxElements];
int k=maxElements;
for(int i=n;i>=0;i--){
    if(k==dp[i]){
        lis[k-1]=p[i];
        k--;
    }
}
for(int i=0;i<maxElements;i++){
    cout<<lis[i]<<" ";
}
return 0;
}

/*TC: O(n(n))
SC: O(n)*/

