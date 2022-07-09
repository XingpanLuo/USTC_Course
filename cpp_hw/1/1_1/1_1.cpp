#include <iostream>
#include <cmath>
using namespace std;
int type(int m){
	if(m%4!=0||(m%100==0&&m%400!=0))
		return 0;
	else 
		return 1;
}
void calen(){
	int hour,minute;
	int second,day,month,year;
	scanf("%d:%d:%d %d.%d.%d",&hour,&minute,&second,&day,&month,&year);
	const int ch_mon[2][12]={31,28,31,30,31,30,31,31,30,31,30,31,
							31,29,31,30,31,30,31,31,30,31,30,31};
	const int ch_y[2]={365,366};
	year=year-2000;
	month-=1;
	long s_day=day;
	long s_month=0;
	long s_year=0;
	for (int i=0;i<month;i++){
		s_month+=ch_mon[type(year+2000)][i];
	}
	s_day+=s_month%100;
	s_month/=100;
	for(int i=2000;i<2000+year;i++){
		s_year+=ch_y[type(i)];
	}
	s_day+=s_year%1000;
	s_year/=1000;
	int mday=s_day%100;
	int mmonth=s_day/100+s_month;
	int myear=mmonth/10+s_year;
	mmonth%=10;
	mmonth+=1;
	long s_second=second;
	s_second+=minute*60;
	s_second+=hour*3600;
	long double temp_second=s_second*(1000/(36.0*24.0));
	long msecond=(int)temp_second;
	long mminute=msecond/100;
	long mhour=mminute/100;
	mminute%=100;
	msecond%=100;
	int t=0;
	// t=mhour/10;
	mhour%=10;
	// mday+=t;
	t=mday/100;
	mday%=100;
	mmonth+=t;
	t=mmonth/10;
	mmonth%=10;
	myear+=t;
	if(mday==0){
		if(mmonth==0){
			myear-=1;
			mmonth+=9;
			mday=100;
		}
		else if(mmonth==1){
			myear-=1;
			mmonth=10;
			mday+=100;
		}
		else{
			mmonth-=1;
			mday+=100;
		}
	}
	printf("%ld:%ld:%ld %d.%d.%d\n",mhour,mminute,msecond,mday,mmonth,myear);
}

int main(){
		calen();
		return 0;

}
