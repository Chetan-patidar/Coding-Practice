#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> answer;
	int start1 = 0;
	int start2 = 0;
	while(start1<n && start2<m){
		if(arr1[start1]==arr2[start2]){
			answer.push_back(arr1[start1]);
			start1++;
			start2++;
		}
		else if(arr1[start1]<arr2[start2]){
			start1++;
		}
		else{
			start2++;
		}
	}
	return answer;
}
