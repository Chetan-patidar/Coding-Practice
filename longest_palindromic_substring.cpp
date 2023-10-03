class Solution {
public:
bool check(string &s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
string Solve_dp(string &s){
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,1));
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                dp[i][j] = 1;
            }
            else if(g==1){
                if(s[i]==s[j]){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
            else{
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    }
    string ans;
    int len = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(len<(j-i+1) && dp[i][j]==1){
                ans = s.substr(i,j-i+1);
                len = j-i+1;
            }
        }
    }
    return ans;
}
    string longestPalindrome(string s) {
        // int n = s.size();
        // string ans;
        // int length = INT_MIN;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         bool p = check(s,i,j);
        //         if(p){
        //             if(length<(j-i+1)){
        //                 ans = s.substr(i,j-i+1);
        //                 length = j-i+1;
        //             }
        //         }
        //     }
        // }
        // return ans;
        string result = Solve_dp(s);
        return result;
    }
};
