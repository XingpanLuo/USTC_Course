#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
double sum[9][9]={0};
double f[9][9][9][9][16];
int n;
double X;
double cal(int x1,int y1,int x2,int y2){
    double temp=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
    return (temp-X)*(temp-X)/(1.0*n);
}
double dfs(int x1,int y1,int x2,int y2,int k){
    double &v=f[x1][y1][x2][y2][k];
    if(v>=0) return v;//已经计算过了
    if(k==1) return v=cal(x1,y1,x2,y2);//分割次数为0 ，不分割
    double res=0x3f3f3f3f;
    for(int i=x1;i<x2;i++){//横向分割,分为上下两部分
        res=min(res,dfs(x1,y1,i,y2,k-1)+cal(i+1,y1,x2,y2));//取上部分继续分割
        res=min(res,cal(x1,y1,i,y2)+dfs(i+1,y1,x2,y2,k-1));//取下部分继续分割
    }
    for(int i=y1;i<y2;i++){
        res=min(res,dfs(x1,y1,x2,i,k-1)+cal(x1,i+1,x2,y2));
        res=min(res,cal(x1,y1,x2,i)+dfs(x1,i+1,x2,y2,k-1));
    }
    v=res;
    return res;
}
int main()
{
    memset(f,-1,sizeof(f));
    cin>>n;
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cin>>sum[i][j];
            //cout<<sum[i][j];
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    X=sum[8][8]/(1.0*n);
    double result=sqrt(dfs(1,1,8,8,n));
    printf("%.3lf",result);
    //cout<<result;
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// const int N=9;
// int n;
// double sum[N][N],f[N][N][N][N][20],X;
// double calc(int x1,int y1,int x2,int y2){
//     double tmp=sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1];
//     return (tmp-X)*(tmp-X)/(1.0*n);
// }
// double dfs(int x1,int y1,int x2,int y2,int k){
//     if(f[x1][y1][x2][y2][k]>=0) return f[x1][y1][x2][y2][k];
// 	if(k==1) return f[x1][y1][x2][y2][k]=calc(x1,y1,x2,y2);
//     double res=0x3f3f3f3f;
//     for(int i=x1;i<x2;++i){
//         res=min(res,dfs(x1,y1,i,y2,k-1)+calc(i+1,y1,x2,y2));
//         res=min(res,calc(x1,y1,i,y2)+dfs(i+1,y1,x2,y2,k-1));
//     }
//     for(int i=y1;i<y2;++i){
//         res=min(res,dfs(x1,y1,x2,i,k-1)+calc(x1,i+1,x2,y2));
//         res=min(res,calc(x1,y1,x2,i)+dfs(x1,i+1,x2,y2,k-1));
//     }
//     f[x1][y1][x2][y2][k]=res;
//     return res;
// }
// int main(){
//     memset(f,0xfe,sizeof f);
//     cin>>n;
//     for(int i=1;i<=8;++i){
//         for(int j=1;j<=8;++j){
//             cin>>sum[i][j];
//             sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
//         }
//     }
//     X=sum[8][8]/(1.0*n);
//     printf("%.3lf",sqrt(dfs(1,1,8,8,n)) );
//     return 0;
// }