/*Question:   you are given string S of length N. find the no. of special strings of length N which are  LEXICOGRAPHICALLY greater than S.
            A string is called special if every substring of length >=2 is not a palindrome.  */





string s;
    int n;
    long long dp[101][27][27][2];
    long long Solve(int index,int last,int second_last,int greater){
        if(index==n)
            return greater;
        long long &ans = dp[index][last][second_last][greater];
        if(ans != -1)
            return ans;
        ans = 0;
        int current = s[index]-'a';
        if(greater){
            current = 0;
        }
        for(int i=current;i<26;i++){
            if(i==last || i==second_last)
                continue;
            int ok = greater;
            if(i>current)
                ok = 1;
            ans = ans + Solve(index+1,i,last,ok);
            ans = ans %1000000007;
        }
        //return mp[temp] = answer%1000000007;
        return ans;
    }
    
    
    int specialStrings(int N, string &S) {
        // Code here.
        s = S;
        n = N;
        for(int i=0;i<101;i++){
            for(int j=0;j<=26;j++){
                for(int k=0;k<=26;k++){
                    for(int l=0;l<=1;l++){
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        long long answer = Solve(0,26,26,0);
        return answer%1000000007;
    }
