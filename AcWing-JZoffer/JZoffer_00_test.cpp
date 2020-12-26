#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using namespace std;

//  主要是一些需要自己处理I/O的情况，可以参考如下的处理


/**	 数值IO	**/

//n组测试用例，每行两数相加
int main(){
    int n;
    cin >> n;

    for(int i =0 ; i<n; i++){
        int a,b;
        cin >> a >> b;
        cout <<a+b << endl;
    }
    return 0;
}

//多组测试用例，每行两数相加，遇到0, 0结束输入
int main()
{
    int M=0;
    int a,b;
    while(cin>>a>>b)
    {
        if(a==0 &&b==0)
               break;
        cout<<a+b<<endl;
    }
 
}

//多组测试用例，每行首数为该组数量，首数遇到0结束输入
int main(){
    int n;
    while(cin>>n && n!=0){
        int sum=0;
        int item;
        for(int i=0;i<n;i++){
            cin>>item;
            sum+=item;
        }
        cout<<sum<<endl;
    }
    return 0;
}


//n组测试用例，每行首数为该组数量
int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
         int n;
         cin>>n;
       
        int sum=0;
         
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            sum+=x;
        }
        cout<<sum<<endl;
    }
     
    return 0;
}


//多组测试用例，每行首数为该组数量
int main ()
{
    int num,input;
    while(cin>>num && num)
    {
        int sum=0;
       for(int i=0;i<num;i++)
       {
           cin>>input;
           sum+=input;
       }
      cout<<sum<<endl;       
    }
 
     
    return 0;
}


//多组测试用例
int main()
{
    int n;
    int sum = 0;
    while(cin >> n){
        sum += n;
        if(cin.get() == '\n'){
            cout << sum << endl;
            sum = 0;
        }
    }
}


/**	 字符串IO		**/

//n个测试用例，个间空格
int main(){
	//最好不要用 int a, b, 因为测试数据会越界，为了效果，题目故意不在题面说数据范围
	typedef long long LL;
    LL num;
    vector<string> str;
    string s;
    cin >> num;
    for (LL i = 0; i < num; i++){
        cin >> s;
        str.push_back(s);
    }
    sort(str.begin(), str.end());
    for (string i:str)
        cout << i << " ";
    return 0;
}

//多个测试用例，个间空格
int main(int argc, char const *argv[])
{
	string s;
    vector<string> str;
    while(cin >> s){
        str.push_back(s);
        if (cin.get() == '\n'){
        	sort(str.begin(), str.end());
        	for (string i:str){
        		cout << i << " ";
        	}
        	cout << endl;
        	str.clear();
        }
    }
	return 0;
}

//多个测试用例，个间逗号
int main(){
 
    string str;
    int num = 0;
    while(getline(cin,str)){
        istringstream stream(str);
        vector<string> list;
        while(getline(stream,str,',')){
            list.push_back(str);
        }
        sort(list.begin(),list.end());
        for(num = 0; num <list.size() - 1 ; num++){
            cout << list[num] <<",";
        }
        cout << list[num] << endl;
    }
    return 0;
}















