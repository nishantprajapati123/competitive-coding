#include<bits/stdc++.h>
using namespace std;
int ops(int n)
{
    int result = 0;
	result += n/5;
	n %= 5;
	result += n/3;
	n %= 3;
	result += n;
	return result;
}
int main()
{
    int T, N;
	cin>>T;
	while(T > 0) {
		cin>>N;
		int input, smallestNum = INT_MAX;
		// Read input, find the smallest #
		vector<int> vec;
		for(int i = 0; i < N; i++) {
			cin>>input;
			vec.push_back(input);
			if(input < smallestNum) {
				smallestNum = input;
			}
		}
		// Iterate over the list and try reducing everyone's candies
		// down to {min, min-1, min-2, min-3, min-4}. Take the minimum
		// answer.
		int answer = INT_MAX;
		for(int i = 0; i < 4; i++) {
			int tmpAnswer = 0;
			for(int j = 0; j < N; j++) {
			//	int minOps = INT_MAX;
				tmpAnswer += ops(vec[j]-smallestNum+i);
			}
			if(tmpAnswer < answer) {
				answer = tmpAnswer;
			}
		}
		cout<<answer<<"\n";
		T--;
	}
    return 0;
}
