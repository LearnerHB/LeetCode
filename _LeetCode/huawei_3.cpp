// 发广播 40%

// 110,110,001
// 2

#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;

	vector<string> str;
	
	int n, dim;
	for (char c : s){
		if (c == ',')
			n++;
	}
	dim = sqrt(s.size()-n);

	int arr[dim][dim];
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			arr[i][j] = s[i*(dim+1) + j] - '0';
		}
	}

	int group[dim];
	for (int i = 0; i < dim; i++){
		group[i] = i + 1;
	}

	
	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			if (arr[i][j] == 1){
				group[j] = group[i];
			}
		}
	}
	
	


	unordered_set<int> set;
	int ans = 0;
	for (int i = 0; i < dim; i++){
		if (set.find(group[i]) == set.end()){
			set.insert(group[i]);
			ans++;
		}
	}

	cout << ans;

	
	return 0;
}