

//find k th largest sum of subarray of n size array

#include<bits/stdc++.h>

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	//brute force approach
	// vector<int> temp;
	// int n = arr.size();
	// for(int i=0;i<n;i++){
	// 	int sum = 0;
	// 	for(int j=i;j<n;j++){
	// 		sum = sum + arr[j];
	// 		temp.push_back(sum);
	// 	}
	// }
	// sort(temp.begin(),temp.end(),greater<int>());
	// return temp[k-1];


	//optimized approach
	priority_queue<int,vector<int>,greater<int>> pq;
	int n = arr.size();
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			if(pq.size()<k){
				sum += arr[j];
				pq.push(sum);
			}
			else{
				sum = sum + arr[j];
				if(pq.top()<sum){
					pq.pop();
					pq.push(sum);
				}
			}
		}
	}
	// while(pq.size()>1){
	// 	pq.pop();
	// }
	return pq.top();

}
