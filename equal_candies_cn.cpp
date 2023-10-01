#include <bits/stdc++.h> 

//commented approach is wrong
long long int equalCandies (vector<int> &candies, int n)
{
	// Write your code here.
	long long answer = INT_MAX;
	for(int i=0;i<n;i++){
		long long sum = 0;
		for(int j=0;j<n;j++){
			sum = sum + abs(candies[i]-candies[j]);
		}
		if(sum<answer)
			answer = sum;
	}
	//best approach O(nlogn)
	// sort(candies.begin(),candies.end());
	// long long mid = (0+n-1)/2;
	// long long ans = 0;
	// for(int i=0;i<n;i++){
	// 	sum += abs(candies[i]-candies[mid]);
	// }
	// return answer;
	return answer;
}
