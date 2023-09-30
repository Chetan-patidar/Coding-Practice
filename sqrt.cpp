long long int square_root(int start,int end,int k){
    long long int ans = -1;
    while(start<=end){
        long long int mid = (start+end)/2;
        long long int temp = mid*mid;
        if(temp==k)
            return mid;
        else if(temp>k){
            end = mid-1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
    }
    return ans;
}

int floorSqrt(int n)
{
    // Write your code here.
    int answer = square_root(0,n,n);
    return answer;
}
