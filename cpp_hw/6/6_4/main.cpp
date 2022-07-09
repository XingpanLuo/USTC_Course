
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m,ans=10000000;
struct node{
    int x,y;
};
node a[510];
struct node2{
    int l,r,u,d;
    bool f;
};
node2 p[5];

bool zai(node2 a,int x,int y)
{
    if (x<=a.r&&x>=a.l&&y<=a.u&&y>=a.d)
      return 1;
    return 0;
}

bool pd(node2 a,node2 b)  //判断是否包含 
{
    if (zai(a,b.l,b.u)) return 1;  //左上角   任何一个顶点在已知矩阵内就不合法 
    if (zai(a,b.l,b.d)) return 1;  //左下角 
    if (zai(a,b.r,b.u)) return 1;  //右上角 
    if (zai(a,b.r,b.d)) return 1;  //右下角 
    return 0;
}

int ss(int t)
{
    int i,j,v=0;
    for (i=1;i<=m;i++)  //在进行选点之前，先把当前状态判断一下 
    {
        if (p[i].f)  //征用了这块地 
        {
            for (j=1;j<=m;j++)  
            {
                if (i!=j&&p[j].f&&pd(p[i],p[j]))  //j也被征用，同时j在i内 
                   return 0;  //这种方案不合法，直接回溯 
            }
        }
        v+=(p[i].r-p[i].l)*(p[i].u-p[i].d);  //合法时加入面积 
    }
    if (v>=ans)  //当前的面积已经比ans大了，不合法，回溯 
       return 0;
    if (t>n)  //所有点都加入了，而且通过了上面的考验 
    {
        ans=v;
        return 0;
    }
    for (i=1;i<=m;i++)  //真正的搜索开始啦，循环我们要把这个点加入哪块矩阵 
    {
        node2 tmp=p[i];
        if (p[i].f==0)  //崭新的矩阵 
        {
            p[i].f=1;
            p[i].l=p[i].r=a[t].x;
            p[i].u=p[i].d=a[t].y;
            ss(t+1);
            p[i]=tmp;  //回溯要彻底 
        } 
        else
        {
            p[i].l=min(p[i].l,a[t].x);  //维护边界值 
            p[i].r=max(p[i].r,a[t].x);
            p[i].u=max(p[i].u,a[t].y);
            p[i].d=min(p[i].d,a[t].y);
            ss(t+1);
            p[i]=tmp;
        }
    }
}

int main()
{
    int i=1;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
      scanf("%d%d",&a[i].x,&a[i].y);
    ss(1);
    printf("%d",ans);
    return 0;
}