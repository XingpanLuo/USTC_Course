#include <iostream>
#include <vector>
#define cir(ii) for(;ii<2;ii++)
#define sub(SUB) SUB=1-SUB
using namespace std;
void change(vector<vector<int> > &b,int i,int j,int n){
    if(i>0&&i<n){
        if(j>0&&j<n){
            sub(b[i][j]);
            sub(b[i-1][j]);
            sub(b[i+1][j]);
            sub(b[i][j-1]);
            sub(b[i][j+1]);
        }
        else if(j==0){
            sub(b[i][j]);
            sub(b[i-1][j]);
            sub(b[i+1][j]);
            sub(b[i][j+1]);
        }
        else if(j==n-1){
            sub(b[i][j]);
            sub(b[i-1][j]);
            sub(b[i+1][j]);
            sub(b[i][j-1]);
        }
    }
    else if(i==0){
        if(j>0&&j<n){
            sub(b[i][j]);
            sub(b[i+1][j]);
            sub(b[i][j-1]);
            sub(b[i][j+1]);
        }
        else if(j==0){
            sub(b[i][j]);
            sub(b[i+1][j]);
            sub(b[i][j+1]);
        }
        else if(j==n-1){
            sub(b[i][j]);
            sub(b[i+1][j]);
            sub(b[i][j-1]);
        }
    }
    else if(i==n-1){
        if(j>0&&j<n){
            sub(b[i][j]);
            sub(b[i-1][j]);
            sub(b[i][j-1]);
            sub(b[i][j+1]);
        }
        else if(j==0){
            sub(b[i][j]);
            sub(b[i-1][j]);
            sub(b[i][j+1]);
        }
        else if(j==n-1){
            sub(b[i][j]);
            sub(b[i-1][j]);
            sub(b[i][j-1]);
        }
    }
    return;
}
void circle(int i,int n,vector<vector<int> > &b,vector<vector<int> > &index,int &min){
    if(i!=n){
        for(int j=0;j<2;j++){
            index[0][i]=j;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<b[i][j]<<" ";
                }
                cout<<endl;
            }
            if(j) 
                change(b,0,i,n);
            
            circle(i+1,n,b,index,min);
        }  
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            index[i][j]=b[i-1][j];
            if(index[i][j])
                change(b,i,j,n);
        }
    }
    int sum=0;
    int result=0;
    for(int i=0;i<n;i++){
        sum+=b[n-1][i];
        for(int j=0;j<n;j++){
            result+=index[i][j];
        }
    }
    if(sum==0&&result<min){
        min=result;
    }
    cout<<min;
    int temp=0;
    for(int i=0;i<n;i++) temp+=index[0][i];
    if(temp=n)
        return;
}

int main()
{
    int n=5;
    cin>>n;
    auto b=vector< vector<int> >(n);
    for(int i=0;i<n;i++){
        b[i].resize(n);
    }
    auto index=vector< vector<int> >(n);
    for(int i=0;i<n;i++){
        index[i].resize(n);
    }
    getchar();
    for(int i=0;i<n;i++){
        char c=getchar();
        int j=0;
        while(c!='\n'){
            int color=(c=='w')?1:0;
            b[i][j++]=color;
            c=getchar();
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            index[i][j]=0;
            cout<<b[i][j];
        }
        cout<<endl;
    }
    int min=1e5;
    circle(0,n,b,index,min);
    if(min==1e5)
        cout<<"Inf";
    else    
        cout<<min<<endl;
    return 0;
}
/*
w:white 白 白色的砖用 1表示
y:yellow 黄 黄色的砖用 0表示
// */
// #include<iostream>
// #include<cstring>
// using namespace std;
// int oribricks[16][17];//读入的墙的初始状态 1表示白色砖，0表示黄色砖
// int draw[16][17];//涂画的结果，1表示涂，0表示不涂
// int n;//墙的大小 (1≤n≤15)

// int guess()//判断涂画好第一行砖块的颜色后，推算出最后一行的砖块是否都能被涂画成黄色  
// {
// 	int r,c;
// 	for(r=1; r<n; r++)
// 		for(c=1; c<n+1; c++)
// 		{
// 			draw[r+1][c]=(draw[r][c]+draw[r][c-1]+draw[r][c+1]+draw[r-1][c]+oribricks[r][c])%2;
// 		}
// 	for(c=1; c<n+1; c++)
// 	{
// 		if(oribricks[n][c]!=(draw[n][c]+draw[n][c-1]+draw[n][c+1]+draw[n-1][c])%2)
// 			return 250;//最后一行的砖块若不能都被涂成黄色则返回250 
// 	}
// 	int count=0;
// 	for(r=1; r<n+1; r++)
// 	{
// 		for(c=1; c<n+1; c++)
// 		{
// 			if(draw[r][c]==1)
// 				count++;
// 		}
// 	}
// 	return count;//若最后一行的所有砖都能被涂成黄色，则函数返回需要涂画的砖块数，也就是draw数组中 1的数量（1代表涂）
// }

// int enumerate()//枚举第一行进行涂画的状态数，将draw数组第一行看成一个二进制数，左边高位，右边低位
// {
// 	int c;
// 	int count=0,mincount=250;
// 	while(draw[1][0]<1)
// 	{
// 		count=guess();
// 		if(count<mincount)
// 			mincount=count;//通过比较，取最少需要涂画的砖数
// 		draw[1][n]++;
// 		c=n;
// 		while(draw[1][c]>1)
// 		{
// 			draw[1][c]=0;
// 			c--;
// 			draw[1][c]++;
// 		}
// 	}
// 	return mincount;
// }

// int main()
// {
// 	int r,c,mincount=0;
// 	cin >> n;
// 	memset(oribricks,0,sizeof(oribricks));
// 	memset(draw,0,sizeof(draw));
// 	for(r=1; r<n+1; r++)//读入墙的每块砖初始的颜色并将它转换为数字 1或 0
// 	{
// 		for(c=1; c<n+1; c++)
// 		{
// 			char color;
// 			cin >> color;
// 			oribricks[r][c]=(color=='w')? 1 : 0;//1表示白色砖，0表示黄色砖
// 		}
// 	}
// 	mincount=enumerate();
// 	if(mincount==250)
// 		cout << "inf";
// 	else
// 		cout << mincount;
// 	return 0;
// } 
