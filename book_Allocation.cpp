bool isPossible(int A[],int N,int M,int mid){
        int studentCount = 1;
        int pagesCount = 0;
        for(int i=0;i<N;i++){
            if(pagesCount+A[i]<=mid){
                pagesCount += A[i];
            }
            else{
                studentCount++;
                if(studentCount>M || A[i]>mid)
                    return false;
                pagesCount = A[i];
            }
        }
        return true;
    }


int findPages(int A[], int N, int M) 
    {
        //code here
        int end = 0;
        int start = 0;
        if(N<M)
            return -1;
        for(int i=0;i<N;i++){
            end += A[i];
        }
        int answer = -1;
        while(start<=end){
            int mid = (start+end)/2;
            if(isPossible(A,N,M,mid)){
                answer = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return answer;
    }
