int first_Position(vector<int>& arr,int start,int end,int x){
    if(start==end){
        if(arr[start]==x){
            return start;
        }
        else{
            return -1;
        }
    }
    if(start>end)
        return -1;

    int mid = (start+end)/2;
    if(arr[mid]==x){
        if(mid-1<start)
            return mid;
        else if(arr[mid-1]!=x)
            return mid;
        else{
            return first_Position(arr,start,mid-1,x);
        }
        
    }
    else if(arr[mid]>x){
        return first_Position(arr,start,mid-1,x);
    }
    else{
        return first_Position(arr,mid+1,end,x);
    }
    return -1;
}

int last_Position(vector<int>& arr,int start,int end,int x){
    if(start==end){
        if(arr[start]==x){
            return start;
        }
        else{
            return -1;
        }
    }
    if(start>end)
        return -1;

    int mid = (start+end)/2;
    if(arr[mid]==x){
        if(mid+1>end)
            return mid;
        else if(arr[mid+1]!=x)
            return mid;
        else{
            return last_Position(arr,mid+1,end,x);
        }
        
    }
    else if(arr[mid]>x){
        return last_Position(arr,start,mid-1,x);
    }
    else{
        return last_Position(arr,mid+1,end,x);
    }
    return -1;
}



pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    // int mid,i,j,firstposition=-1,lastposition=-1;
    pair <int,int> pair1;
    // i=0;
    // j=n-1;
    // while(i<=j)
    // {
    //     mid = i + (j-i)/2;
    //     if(arr[mid]==k && arr[mid-1]!=k)
    //     {
    //         firstposition =mid;
    //         break;
    //     }
    //     else if(arr[mid]==k && arr[mid-1]==k)
    //     {
    //         if(mid-1==0)
    //         {
    //             firstposition=0;
    //             break;
    //         }
    //         j=mid-1;
    //     }
    //     else if(arr[mid]>k)
    //     {
    //         j=mid-1;
    //     }
    //     else
    //     {
    //         i=mid+1;
    //     }
    // }
    // i=0;
    // j=n-1;
    // while(i<=j)
    // {
    //     mid = i + (j-i)/2;
    //     if(arr[mid]==k && arr[mid+1]!=k)
    //     {
    //         lastposition =mid;
    //         break;
    //     }
    //     else if(arr[mid]==k && arr[mid+1]==k)
    //     {
    //         if(mid+1==n-1)
    //         {
    //             lastposition=n-1;
    //             break;
    //         }
    //         i=mid+1;
    //     }
    //     else if(arr[mid]>k)
    //     {
    //         j=mid-1;
    //     }
    //     else
    //     {
    //         i=mid+1;
    //     }
    // }
    pair1.first = first_Position(arr,0,n-1,k);
    pair1.second = last_Position(arr,0,n-1,k);
    return pair1;
}
