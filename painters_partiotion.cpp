bool isPossible(vector<int>& boards,int mid,int k){
    int painterCount = 1;
    int time = 0;
    int n = boards.size();
    for(int i=0;i<n;i++){
        if(time+boards[i]<=mid){
            time += boards[i];
        }
        else{
            painterCount++;
            if(painterCount>k || boards[i]>mid)
                return false;
            time = boards[i];
        }
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int start = 0;
    int end = 0;
    int n = boards.size();
    if(n<k)
        return -1;
    for(int i=0;i<n;i++){
        end += boards[i];
    }

    int answer = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(isPossible(boards,mid,k)){
            answer = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return answer;
}
