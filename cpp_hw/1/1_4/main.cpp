#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
//#define DEBUG
using namespace std;
const int MAX=80;
int get_list(char *str,vector<int>&list)
{
	int len=strlen(str);
	if(len<2) return -1;
	for(int i=2;i<len;i++){
		int temp=str[i]-'0';
		list.push_back(temp);		
	}
	return 0;
}
long double dec(const vector<int>&list){
	int mol=0;
	int den=0;
	int len=list.size();
	int num_of_zero=0;
	int i=0;
	for(;i<len;i++){
		if(num_of_zero>4) break;
		num_of_zero=list[i]==0?num_of_zero+1:0;
	}
	i-=num_of_zero;
	den=pow(8,i);
	for(int j=0;j<i;j++){
		mol+=list[j]*pow(8,i-1-j);
	}
	long double result=(double)mol/(double)den;
	return result;
}
int main()
{
	double num;
	cin>>num;
	char str[MAX];
	sprintf(str,"%f",num);
#ifdef DEBUG
	cout<<str;
#endif
	vector<int> list;
	get_list(str,list);
#ifdef DEBUG
	for(auto i:list) cout<<i<<' ';	
#endif
	cout<<setprecision(30)<<dec(list)<<endl;
	return 0;
}
