int find_Pivot(vector<int> &arr,int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        int mid = (start+end)/2;
        if(arr[mid]>=arr[0]){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    return start;
}
int binary_Search(vector<int>& arr,int start,int end,int k){
    if(start==end){
        if(arr[start]==k)
            return start;
        else
            return -1;
    }
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]>k){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int index = find_Pivot(arr,n);
    //cout<<index<<endl;
    int left = binary_Search(arr,0,index-1,k);
    if(left!=-1)
        return left;
    int right = binary_Search(arr,index,n-1,k);
    if(right!=-1)
        return right;
    return -1;

}
