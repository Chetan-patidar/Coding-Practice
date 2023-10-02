int solve(int N, string S) {
        // code here
        int answer = 0;
        vector<int> arr(26,0);
        for(int i=0;i<N;i++){
            arr[S[i]-'a']++;
        }
        sort(arr.begin(),arr.end(),greater<int>());
        for(int i=1;i<26;i++){
            if(arr[i]!=0)
                answer++;
        }
        
        return answer;
    }
