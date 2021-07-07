//挑选货物 70%

// 6 4
// 1 2 3 4 5 6

// 3

// 4 1
// 1 2 3 4

// 10


#include <iostream>
#include <vector>

using namespace std;

int mySum(vector<int> vec, int st, int ed){
	int sum = 0;
	while (st <= ed){
		sum += vec[st];
		st++;
	}

	return sum;
}

int main(int argc, char const *argv[])
{
	int num_of_goods, target;
	int ans = 0;
	vector<int> weights;
	cin >> num_of_goods >> target;

	for (int i = 0; i< num_of_goods; i++){
		int cur;
		cin >> cur;
		weights.push_back(cur);
	}
	for(int i = 0; i < num_of_goods; i++){
		for (int j = i; j < num_of_goods; j++){
			if (mySum(weights, i, j) % target == 0){
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}









