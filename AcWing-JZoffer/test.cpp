/*开根号*/
// 4 - 2
// 3 - 1.73
// 1e-05

#define ERR 0.00001

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	float t1 = 4.0;
	cout << sqrt(t1) << endl;
	
	return 0;
}

float sqrt(float num){

	if (num >= 1.0){
		float mid = num / 2.0, left = 0.0, right = num;
	}else{
		float mid = num * 2.0, left = num, right = 1.0;
	}
	while (abs(num - mid * mid) > ERR){
		if (mid * mid > num){
			right = mid;
			mid = (left + mid) / 2.0;
		}
		else {
			left = mid;
			mid = (mid + right) / 2.0;
		}
	}
	return mid;
}


