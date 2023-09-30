#include <bits/stdc++.h> 
bool isPossible(int k,vector<int>& time,long long int mid){
	long long daysCount = 1;
	long long int allocated = 0;
	int n = time.size();
	for(int i=0;i<n;i++){
		if(allocated+time[i]<=mid){
			allocated += time[i];
		}
		else{
			daysCount++;
			if(daysCount>k || time[i]>mid)
				return false;
			allocated = time[i];
		}
	}
	return true;
}


long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long int start = 0;
	long long int end = 0;
	for(int i=0;i<m;i++){
		end += time[i];
		//start = max(start,time[i]);
	}
	long long  ans = -1;
	while(start<=end){
		long long int mid = (start+end)/2;
		if(isPossible(n,time,mid)){
			ans = mid;
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return ans;

}
