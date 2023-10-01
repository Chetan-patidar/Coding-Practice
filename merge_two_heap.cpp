void heapify(vector<int> &merge_array,int largest){
        int n = merge_array.size();
        if(largest>=n)
            return;
        int temp = largest;
        if(2*largest+1<n && merge_array[temp]<merge_array[2*largest+1]){
            temp = 2*largest+1;
        }
        if(2*largest+2<n && merge_array[temp]<merge_array[2*largest+2]){
            temp = 2*largest+2;
        }
        if(temp==largest)
            return;
        else{
            swap(merge_array[largest],merge_array[temp]);
            heapify(merge_array,temp);
        }
        return;
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> merge_array;
        for(int i=0;i<n;i++){
            merge_array.push_back(a[i]);
        }
        for(int i=0;i<m;i++){
            merge_array.push_back(b[i]);
        }
        
        int size = merge_array.size();
        int start = (size/2)-1;
        for(int i=start;i>=0;i--){
            heapify(merge_array,i);
        }
        return merge_array;
    }
