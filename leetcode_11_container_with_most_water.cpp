class Solution {
public:
    int maxArea(vector<int>& height) {
        // int n = height.size();
        // int capacity = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         int width = j-i;
        //         int h = min(height[i],height[j]);
        //         int area = h*width;
        //         capacity = max(area,capacity);
        //     }
        // }
        // return capacity;


        int n = height.size();
        int start = 0;
        int end = n-1;
        int capacity = 0;
        while(start<end){
            int h = min(height[start],height[end]);
            int width = end-start;
            int area = h*width;
            capacity = max(area,capacity);
            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return capacity;
    }
};
