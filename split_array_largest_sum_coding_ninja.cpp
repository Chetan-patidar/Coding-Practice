bool isPossible(vector<int> &arr,int k,long long mid){
	int count = 1;
	int sum = 0;
	int n = arr.size();
	for(int i=0;i<n;i++){
		if(sum+arr[i]<=mid){
			sum = sum + arr[i];
		}
		else{
			count++;
			if(count>k || arr[i]>mid)
				return false;
			sum = arr[i];
		}
	}
	return true;
}


int splitArray(vector<int> &arr, int k) {
	// Write your code here.
	int n = arr.size();
	long long start = 0;
	long long end = 0;
	if(n<k)
		return -1;
	for(int i=0;i<n;i++){
		end += arr[i];
	}

	int ans = -1;
	while(start<=end){
		long long mid = (start+end)/2;
		if(isPossible(arr,k,mid)){
			ans = mid;
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	return ans;
}
