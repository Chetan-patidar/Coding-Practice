#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main(){
    map<string,set<pair<int,int>>> mp;
    vector<int> answer;
    int n;
    cin>>n;
    while(n){
        string op;
        cin>>op;
        if(op=="supply"){
            string itemName,count,price;
            cin>>itemName>>count>>price;
            int c = stoi(count);
            int p = stoi(price);
            if(mp[itemName].find({p,c})==mp[itemName].end()){
                mp[itemName].insert({p,c});
            }
            else{
                mp[itemName].erase({p,c});
                mp[itemName].insert({p+p,c});
            }
            
        }
        else if(op=="sell"){
            string itemName,count;
            cin>>itemName>>count;
            int c = stoi(count);
            int result = 0;
            while(c){
                int price = mp[itemName].begin()->first;
                int available = mp[itemName].begin()->second;
                if(available>c){
                    result  += price *c;
                    
                    mp[itemName].erase({price,available});
                    mp[itemName].insert({price,available-c});
                    c = 0;
                    break;
                }
                else{
                    result += price * available;
                    c = c - available;
                    mp[itemName].erase({price,available});
                }
                
            }
            answer.push_back(result);
        }
        else{
            string itemName,count,nprice,oprice;
            cin>>itemName>>count>>oprice>>nprice;
            int c = stoi(count);
            int p = stoi(nprice);
            if(mp[itemName].find({p,c})==mp[itemName].end()){
                mp[itemName].insert({p,c});
            }
            else{
                mp[itemName].erase({p,c});
                mp[itemName].insert({p+p,c});
            }
        }
        n = n-1;
    }
    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<"  ";
    }
    return 0;
    
}
