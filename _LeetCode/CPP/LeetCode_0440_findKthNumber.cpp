/** 字典序的第k小数字
遍历十叉树

给定整数 n 和 k，找到 1 到 n 中字典序第 k 小的数字。
示例
--输入:
n: 13   k: 2
--输出:
10
--解释:
字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
*/

#include <iostream>

using namespace std;

// 方法1
//参考 https://www.cnblogs.com/grandyang/p/6031787.html
//https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/
int findKthNumber1(int n, int k) {
	
	int cur = 1;
	--k;
	while (k > 0){
		long long step  = 0, first = cur, last = cur + 1;
		while (first <= n){
			step += min((long long)n + 1, last) - first;
			first *= 10;
			last *= 10;
		}
		if (step <= k){
			cur++;
			k -= step;
		}
		else{
			k--;
			cur *= 10;
		}
	}
	return cur;
}

//方法2
//首先，通过简单的方式计算[n, n+1]之间多少数字，计算每扩大10倍有多少数字，相加即可
int getNodeNums(int n, int max){
	int ans = 1;	//一开始先把1算上
	long left = (long)n * 10 + 0; //扩大10倍的左边界
	long right = (long)n * 10 + 9; //扩大10倍的右边界
	while (max >= left){
		if (max <= right){
			ans += (max - left + 1);	//max 在[left, right]之间
		}else{
			ans += (right - left + 1);	//max 在下一层
		}
		left = left * 10 + 0;	// 计算下一层的左右边界
		right = right * 10 + 9;
	}
	return ans;
}

int findKthNumber2(int n, int k){	//n为总的数字个数，k为字典序序号，即要找第k小的数字
	int l = 1;
	int r = 9;
	while(k){
		for (int i = l; i <= r; i++){
			int f = getNodeNums(i, n);
			if (k > f){	//第k个数不在[i,i+1]中，还需要找k-=f(i)个数
				k -= f;
			}else{		//第k个数在[i,i+1]中，还需找k-1个数，接下来查找区间为[i*10,i*10+9]
				k--;
				if(k == 0)
					return i;
				l = i * 10 + 0;
				r = i * 10 + 9;
				break;
			}
		}
	}
	return 0;
}


int main(int argc, char const *argv[]){
	
	int n = 13, k = 2;

	int ans = findKthNumber2(n, k);

	cout << ans << endl;

	return 0;
}


