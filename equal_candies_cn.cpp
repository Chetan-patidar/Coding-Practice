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
	// double sum = 0;
	// for(int i=0;i<n;i++){
	// 	sum += candies[i];
	// }
	// sum = sum/n;
	// long long x1 = ceil(sum);
	// long long x2 = floor(sum);
	// int index1 = 0;
	// long long s = INT_MAX;
	// for(int i=0;i<n;i++){
	// 	if(abs(candies[i]-x1)<s){
	// 		index1 = i;
	// 		s = abs(candies[i]-x1);
	// 	}
	// }
	// s = INT_MAX;
	// int index2 = 0;
	// for(int i=0;i<n;i++){
	// 	if(abs(candies[i]-x2)<s){
	// 		index2 = i;
	// 		s = abs(candies[i]-x2);
	// 	}
	// }
	// x1 = 0;x2 = 0;
	// for(int i=0;i<n;i++){
	// 	x1 += abs(candies[i]-candies[index1]);
	// }
	// for(int i=0;i<n;i++){
	// 	x2 += abs(candies[i]-candies[index2]);
	// }
	// return min(x1,x2);
	return answer;
}
