
// class Segment_Tree{
// public:
//     vector<pair<int,int>> arr;
//     Segment_Tree(int n){
//         arr.resize(4*n+1);
//     }
//     pair<int,int> query(int index,int low,int high,int l,int r){
//         //no overlap
//         if(high<l || r<low){
//             return {INT_MAX,INT_MIN};
//         }

//         //overlap
//         if(l<=low && high<=r){
//             return arr[index];
//         }

//         //partial overlap
//         int mid = (low+high)/2;
//         pair<int,int> left = query(2*index+1,low,mid,l,r);
//         pair<int,int> right = query(2*index+2,mid+1,high,l,r);
//         int mi = min(left.first,right.first);
//         int ma = max(left.second,right.second);
//         return {mi,ma};

//     }

//     void build(int index,int low,int high,vector<int> &nums){
//         if(low==high){
//             arr[index] = {nums[low],nums[low]};
//             return;
//         }

//         int mid = (low+high)/2;
//         build(2*index+1,low,mid,nums);
//         build(2*index+2,mid+1,high,nums);
//         int mi = min(arr[2*index+1].first,arr[2*index+2].first);
//         int ma = max(arr[2*index+1].second,arr[2*index+2].second);
//         arr[index] = {mi,ma};
//         return;
//     }
//     void print(int n){
//         for(int i=0;i<4*n;i++){
//             cout<<"("<<arr[i].first<<" ,"<<arr[i].second<<")   ";
//         }
//     }


// };





class Solution {
public:
    

    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,-1);
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            arr[i] = mini;
        }

        stack<int> st;

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(!st.empty()&&st.top()>arr[i] && st.top()<nums[i]){
                return true;
            }
            st.push(nums[i]);
        }
        return false;
        //segment tree fail case
        // int n = nums.size();
        // Segment_Tree st(n);
        // st.build(0,0,n-1,nums);
        // vector<int> arr(n,-1);
        // int mini = INT_MAX;
        // int index = -1;
        // for(int i=0;i<n;i++){
        //     arr[i] = index;
        //     if(mini>nums[i]){
        //         mini = nums[i];
        //         index = i;
        //     }
        // }
        // //st.print(n);
        // int mi,ma;
        // for(int i=1;i<n-1;i++){
        //     pair<int,int> temp = st.query(0,0,n-1,i+1,n-1);
        //     mi = nums[arr[i]]+1;
        //     ma = nums[i]-1;
        //     if(mi>ma)
        //         continue;
        //     if((temp.first<=mi && ma<=temp.second) || (temp.first<=mi && temp.second<=ma && temp.second>=mi) || (mi<=temp.first && temp.second>=ma && ma>=temp.first)){
        //         cout<<i<<"  "<<temp.first<<"  "<<temp.second<<" "<<mi<<"  "<<ma;
        //         return true;
        //     }
        // }
        //return false;


        

        //brute force approach time complexity is O(n^3)

        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]<nums[j] && nums[j]>nums[k] && nums[k]>nums[i])
        //                 return true;
        //         }
        //     }
        // }
        // return false;


        //Little bit optimization time complexity is O(n^2)
        // int n = nums.size();
        // vector<int> arr(n,-1);
        // int mini = INT_MAX;
        // int index = -1;
        // for(int i=0;i<n;i++){
        //     arr[i] = index;
        //     if(mini>nums[i]){
        //         mini = nums[i];
        //         index = i;
        //     }
        // }

        // for(int i=1;i<n;i++){
        //     int mi = nums[arr[i]];
        //     int ma = nums[i];
        //     for(int k=i+1;k<n;k++){
        //         if(nums[k]>mi && nums[k]<ma)
        //             return true;
        //     }
        // }
        // return false;
    }
};
