#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	vector<int> answer;
	int startA = 0;
	int startB = 0;
	int carry = 0;
	while(startA<n && startB<m){
		int sum = (a[startA]+ b[startB]+carry)%10;
		carry = (a[startA]+ b[startB]+carry)/10;
		answer.push_back(sum);
		startA++;
		startB++;
	}
	while(startA<n){
		int sum = (a[startA]+carry)%10;
		carry = (a[startA]+carry)/10;
		answer.push_back(sum);
		startA++;
	}
	while(startB<m){
		int sum = (b[startB]+carry)%10;
		carry = (b[startB]+carry)/10;
		answer.push_back(sum);
		startB++;
	}
	if(carry==1){
		answer.push_back(1);
	}
	int s = answer.size();
	for(int i=s-1;i>=0;i--){
		if(answer[i]==0){
			answer.pop_back();
		}
		else{
			break;
		}
	}

	reverse(answer.begin(),answer.end());
	return answer;
}
