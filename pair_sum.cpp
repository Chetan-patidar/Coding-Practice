#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   int n = arr.size();
   set<pair<int,int>> st;
   vector<vector<int>> answer;
   for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
         if(arr[i]+arr[j]==s){
            vector<int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);
            sort(temp.begin(),temp.end());
            answer.push_back(temp);
         }
      }
   }
   sort(answer.begin(),answer.end());
   return answer;
}
