#include<bits/stdc++.h>

int signum(int x,int y){
	if(x==y)
		return 0;
	else if(x<y)
		return -1;
	return 1;
}

void callMedian(int &median,priority_queue<int,vector<int>,greater<int> > &minHeap,
				priority_queue<int> &maxHeap,int element){
	switch(signum(maxHeap.size(),minHeap.size())){
		case 0: if(element>median){
					minHeap.push(element);
					median = minHeap.top();
				}
				else{
					maxHeap.push(element);
					median = maxHeap.top();
				}
				break;

		case 1: if(element>median){
					minHeap.push(element);
				}
				else{
					minHeap.push(maxHeap.top());
					maxHeap.pop();
					maxHeap.push(element);
				}
				median = (minHeap.top() + maxHeap.top())/2;
				break;

		case -1:if(element>median){
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(element);
		}
		else{
			maxHeap.push(element);
		}
		median = (minHeap.top() + maxHeap.top())/2;
		break;
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int,vector<int>,greater<int>> minHeap;
	priority_queue<int> maxHeap;
	int median = 0;
	vector<int> answer;
	for(int i=0;i<n;i++){
		callMedian(median,minHeap,maxHeap,arr[i]);
		answer.push_back(median);
	}
	return answer;
}
