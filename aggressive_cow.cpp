bool isPossible(vector<int>& stalls,int k,int mid){
    int cowsCount = 1;
    int prev = stalls[0];
    int n = stalls.size();
    for(int i=1;i<n;i++){
        if(abs(prev-stalls[i])>=mid){
            cowsCount++;
            if(cowsCount==k)
                return true;
            prev = stalls[i];
        }
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int start = 0;
    int end = stalls[n-1];
    
    int answer = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(isPossible(stalls,k,mid)){
            answer = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return answer;
}
