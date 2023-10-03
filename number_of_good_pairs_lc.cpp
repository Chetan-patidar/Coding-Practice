class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // int n = nums.size();
        // int answer = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]==nums[j])
        //             answer++;
        //     }
        // }
        // return answer;

        unordered_map<int,int> mp;
        int answer = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                answer = answer + mp[nums[i]];
                mp[nums[i]]++;
            }
            else
                mp[nums[i]] = 1;
        }
        return answer;
    }
};
