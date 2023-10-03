class Solution {
public:
    void reverse(string &s,int start,int end){
        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        string ans  = s;
        int n = ans.size();
        int start = 0;
        int end = 0;
        while(start<n && end<n){
            if(ans[end]!=' '){
                end = end + 1;
            }
            else{
                reverse(ans,start,end-1);
                start = end+1;
                end = end + 1;
            }
        }
        reverse(ans,start,end-1);
        return ans;
    }
};
