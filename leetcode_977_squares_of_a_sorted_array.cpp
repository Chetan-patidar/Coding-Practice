class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //brute force approach
        
        // vector<int> answer;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int sq = nums[i]*nums[i];
        //     answer.push_back(sq);
        // }
        // sort(answer.begin(),answer.end());
        // return answer;


        int n = nums.size();
        vector<int> answer(n,0);
        int start = 0;
        int end = n-1;
        int index = n-1;
        while(start<=end){
            if(nums[start]*nums[start] >nums[end]*nums[end]){
                answer[index--] = nums[start]*nums[start];
                start++;
            }
            else{
                answer[index--] = nums[end]*nums[end];
                end--;
            }
        }
        return answer;
    }
};
