#include <bits/stdc++.h> 
double Solve(vector<double>& prob,int target,int index,vector<vector<double>> &dp){
	int n = prob.size();
	
	if(index<n && target==0){
		double ans = 1;
		for(int i=index;i<n;i++){
			ans *= (1-prob[i]);
		}
		return ans;
	}
	if(index==n && target>0){
		return 0;
	}
	if(index==n && target==0){
		return 1;
	}
	if(dp[index][target]!=-1){
		return dp[index][target];
	}
	double head = 0,tail = 0;
	//take as a head
	head = prob[index]* Solve(prob,target-1,index+1,dp);


	//take as a tail
	tail = (1-prob[index])*Solve(prob,target,index+1,dp);
	return dp[index][target] = head+tail;
}
double tossStrangeCoins(vector<double> &prob, int target)
{
	// Write your code here.
	int n = prob.size();
	vector<vector<double>> dp(n,vector<double>(target+1,-1)); 
	double answer = Solve(prob,target,0,dp);
	//cout<<answer;
	return answer;
}
