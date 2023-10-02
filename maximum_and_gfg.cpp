int maxAnd(int N, vector<int> &A){
        // code here
        int result = INT_MIN;
        bool check = true;
        int previous = -1;
        for(int i=31;i>=0;i--){
            int bit_mask = 1<<i;
            int count = 0;
            int index = 0;
            for(int j=0;j<N;j++){
                if((A[j]&bit_mask) == 0){
                    count++;
                    index = j;
                }
            }
            if(count==1 && (index==previous || check)){
                check = false;
                previous = index;
                A[index] = A[index]|bit_mask;
                int answer = INT_MAX;
                for(int p=0;p<N;p++){
                    answer = answer & A[p];
                }
                result = max(result,answer);
            }
        }
        if(result!=INT_MIN)
            return result;
        int answer = INT_MAX;
        for(int i=0;i<N;i++){
            answer = answer & A[i];
        }
        return answer;
    }
