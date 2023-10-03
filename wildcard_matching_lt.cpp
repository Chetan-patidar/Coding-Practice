class Solution {
public:
    int Solve(int index1,int index2,string &s,string &p,vector<vector<int>>& dp){
        int n = s.size();
        int m = p.size();
        if(index1==n && index2==m)
            return 1;
        if(index1<n && index2==m)
            return 0;
        if(index1==n){
            for(int i=index2;i<m;i++){
                if(p[i]!='*')
                    return 0;
            }
            return 1;
        }
        
        if(dp[index1][index2]!=-1){
            return dp[index1][index2];
        }
        int c1 = 0,c2 = 0,skip = 0,question=0,final=0;
        if(p[index2]=='*'){
            //consider
            //consider case1
            c1 = Solve(index1+1,index2,s,p,dp);

            //consider case 2
            //c2 = Solve(index1+1,index2+1,s,p,dp);

            //skip
            skip = Solve(index1,index2+1,s,p,dp);
            return dp[index1][index2] = (c1||c2||skip);
            
        }
        if(p[index2]=='?'|| p[index2]==s[index1]){
            question = Solve(index1+1,index2+1,s,p,dp);
            return dp[index1][index2] = question;
        }
        else{
            if(p[index2]!=s[index1])
                return dp[index1][index2] = 0;
            // else{
            //     final = Solve(index1+1,index2+1,s,p,dp);
            // }
        }
        return 0 ;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        bool ans = Solve(0,0,s,p,dp);
        return ans;
    }
};
