#include<bits/stdc++.h>
using namespace std;

void solve(int arr[], int n){
    int i=0;
    while(i < n){
        int correct = arr[i] - 1;
        if(arr[i] != arr[correct]){
            swap(arr[i] , arr[correct]);
        }
        else{
            i++;
        }
    }
}

int main(){
    int arr[1000],n;
    string str;

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);
    solve(arr, n);
    for(int i=0; i<n; i++){
        str+=to_string(arr[i]);
    }
    cout<<str;
    return 0;
}