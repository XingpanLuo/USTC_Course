#include <iostream>
#include <vector>
#include <algorithm>
//#define DEBUG
using namespace std;
int find(const vector<int> &list,const int dect,int begin)
{
	int end=list.size()-1;
	int middle=0;
	while(end>=begin){
		middle=(begin+end)/2;
		if(list[middle]==dect) return dect;
		else if(list[middle]>dect){
			end=middle-1;	
		}
		else if(list[middle]<dect){
			begin=middle+1;
		}
	}
	return 0;
}
int main()
{

	int num=0;
	vector<int> list;
	while(cin>>num){
		list.push_back(num);
		if('\n'==cin.get()) break;
	}
	sort(list.begin(),list.end());
#ifdef DEBUG
	for(auto i:list) cout<<i<<' ';
	cout<<endl;
	cout<<"****"<<endl;
	//cout<<find(list,6,1);
#endif
	int all=0;
	if(list.size()<2) {
		cout<<all<<endl;
		return 0;
	}
	for(int i=0;i<list.size()-1;i++){
		if(find(list,list[i]*2,i+1)!=0) all++;
	}
	cout<<all<<endl;
	return 0;
}
