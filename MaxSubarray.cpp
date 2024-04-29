#include <bits/stdc++.h>
using namespace std;

int max(int a,int b){
    return (a>b)? a:b;
}

int max(int a,int b,int c){
    return max(max(a,b),c);
}

int maxCrossingSum(int arr[],int l,int m,int h){
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i =m;i >=l;i--){
        sum += arr[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }

    sum = 0;
    int right_sum = INT_MIN;
    for(int i=m;i < h;i++){
        sum += arr[i];
        if(sum > right_sum){
            right_sum = sum;
        }
    }

    return max(left_sum + right_sum - arr[m],left_sum,right_sum);
}

int MaxSubarraySum(int arr[],int l,int h){
    if(l > h){
        return INT_MIN;
    }

    if( l== h){
        return arr[l];
    }

    int m = (l+h)/2;

    return max(MaxSubarraySum(arr,l,m-1),MaxSubarraySum(arr,m+1,h),maxCrossingSum(arr,l,m,h));
}

int main(){
    int n;
    cout << "enter size of array : ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum = MaxSubarraySum(arr,0,n-1);
    cout << "max sub sum is : "<<sum;
}