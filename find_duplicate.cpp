int findDuplicate(vector<int> &arr) 
{
    // Write your code here
    int n = arr.size();
    vector<int> temp(n+1,-1);
    for(int i=1;i<=n;i++){
        temp[i] = arr[i-1];
    }
    int start = 1;
    while(start<=n){
        if(temp[start]==start){
            start++;
        }
        else{
            int p = temp[start];
            if(temp[p]==p)
                return p;
            swap(temp[start],temp[p]);
        }
    }
    return -1;
	
}
