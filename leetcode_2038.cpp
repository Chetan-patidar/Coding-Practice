class Solution {
public:
    int check(string &colors,int turn){
        int n =colors.size();
        if(n<=2)
            return -1;
        if(turn==1){
            for(int i=1;i<n-1;i++){
                if(colors[i-1]=='A'&&colors[i]=='A' && colors[i+1]=='A')
                    return i;
            }
        }
        else{
            for(int i=1;i<n-1;i++){
                if(colors[i-1]=='B'&&colors[i]=='B' && colors[i+1]=='B')
                    return i;
            }
        }
        return -1;
    }
    bool winnerOfGame(string colors) {
        // int turn = 1;
        // string temp = colors;
        // while(1){
        //     //cout<<turn<<"  "<<temp<<endl;
        //     int index = check(temp,turn);
        //     if(index==-1)
        //         return 1-turn;
        //     temp.erase(index,1);
        //     turn = 1-turn;
        // }
        // return false;
        int count_A = 0;
        int count_B = 0;
        int n = colors.size();
        int temp = 0;
        for(int i=0;i<n;i++){
            if(colors[i]=='A'){
                temp++;
                if(temp>=3){
                    count_A++;
                }
            }
            else{
                temp = 0;
            }
        }
        temp = 0;
        for(int i=0;i<n;i++){
            if(colors[i]=='B'){
                temp++;
                if(temp>=3){
                    count_B++;
                }
            }
            else{
                temp = 0;
            }
        }
        if(count_A>count_B){
            return true;
        }
        if(count_A<count_B){
            return false;
        }
        return false;
    }
};
