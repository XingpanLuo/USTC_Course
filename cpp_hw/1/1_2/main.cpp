#include <iostream>

using namespace std;

int week_of_thirteen(const int week_of_one)
{
	int temp=(week_of_one+12)%7;
	return temp?temp:7;
}
int week_of_next_one(const int day_num_of_month,const int week_of_one)
{
	int temp=(week_of_one+day_num_of_month)%7;
	return temp?temp:7;	
}
int unlucky(const int month,const int week_of_one)
{
	return week_of_thirteen(week_of_one)==5?month:0;
}
int main()
{
	const int num[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int week_of_one;
	cin>>week_of_one;
	for(int month=1;month<=12;month++){
		int temp=unlucky(month,week_of_one);
		if(temp) cout<<temp<<endl;
		week_of_one=week_of_next_one(num[month-1],week_of_one);
	}
	return 0;
}
