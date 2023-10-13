/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int find(MountainArray &mountainArr,int start,int end,int n){
        if(start==end)
        return start;

        if(mountainArr.get(start)>mountainArr.get(start+1))
            return start;

        if(mountainArr.get(end)>mountainArr.get(end-1))
            return end;
        while(start<end){
            int mid = (start+end)/2;
            if(mid==start&& mountainArr.get(mid)>mountainArr.get(mid+1)){
                return mid;
            }
            else if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                start = mid+1;
            }
            else{
                end = mid;
            }
        }
        return start;
    }

    int search(MountainArray &mountainArr,int start,int end,int target){
        if(start>end)
            return -1;
        if(start==end){
            if(mountainArr.get(start)==target)
                return start;
            return -1;
        }
        while(start<=end){
            int mid = (start+end)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)>target){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return -1;
    }
    int search2(MountainArray &mountainArr,int start,int end,int target){
        if(start>end)
            return -1;
        if(start==end){
            if(mountainArr.get(start)==target)
                return start;
            return -1;
        }
        while(start<=end){
            int mid = (start+end)/2;
            if(mountainArr.get(mid)==target)
                return mid;
            else if(mountainArr.get(mid)>target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int position = find(mountainArr,0,n-1,n);
        cout<<position<<"  ";
        int answer = search(mountainArr,0,position,target);
        int answer2 = search2(mountainArr,position,n-1,target);
        cout<<answer<<"   "<<answer2;
        if(answer==-1 && answer2==-1)
            return -1;
        if(answer!=-1)
            return answer;
        return answer2;
    }
};
