#include <bits/stdc++.h> 
long long int bobsHomework(int n)
{
    // Write your code here.
    vector<int> arr;
    int p = n;
    while(p>0){
        arr.push_back(p%10);
        p = p/10;
    }   
    reverse(arr.begin(),arr.end());
    int s = arr.size();
    int start = s-1;
    bool check = false;
    while(start>0){
        if(arr[start-1]>=arr[start]){
            start--;
        }
        else{
            for(int i=s-1;i>=start;i--){
                if(arr[i]>arr[start-1]){
                    swap(arr[i],arr[start-1]);
                    break;
                }
            }
            int x = start;
            int y = s-1;
            while(x<y){
                swap(arr[x],arr[y]);
                x++;
                y--;
            }

            long long int answer = 0;
            x = s-1;
            p = 0;
            while(x>=0){
                answer += arr[x]*pow(10,p);
                p++;
                x--;
            }
            return answer;
        }
    }
    return -1;
}
