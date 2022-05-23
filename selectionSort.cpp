#include<bits/stdc++.h> 
using namespace std;

void selectionSort(vector<int> &v){
	
	for(int i=0;i<v.size()-1;i++)
	{
		int min=i;
		for(int j=i+1;j<v.size();j++){
			if(v[min]>v[j])
				min=j;
		}
		swap(v[min],v[i]);
	}
}
int main(){
	int n;
	cin>> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	selectionSort(arr);
	for(int i=0;i<n;i++){
	cout<<arr[i]<<" ";
	}
}