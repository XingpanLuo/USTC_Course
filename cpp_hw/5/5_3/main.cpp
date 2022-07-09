#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
广度优先搜索
可以走的节点加入队尾，队头逐渐出列，判断是否符合要求
需要维护一个保存是否访问过的数组visit，避免重复访问
*/
struct point
{
    int x;
    int y;
};
typedef struct point Point;
bool eq(Point p1,Point p2){
    if(p1.x==p2.x){
        if(p1.y==p2.y)
            return true;
    }
    return false;
}
bool fea(vector<vector<int>> &a,vector<vector<int>> &v,Point &p){
    if(a[p.x][p.y]==1&&v[p.x][p.y]==0){
        return true;
    }
    else 
        return false;
}
bool wdf(vector<vector<int>>&a,Point &s,Point &e){
    vector<vector<int> > visit=a;
    int size=a.size();
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            visit[i][j]=0;
        }
    }
    if(a[s.x][s.y]==0||a[e.x][e.y]==0)
        return false;
    queue<Point> qlist;
    qlist.push(s);
    while(!qlist.empty()){
        Point pn=qlist.front();
        qlist.pop();
        visit[pn.x][pn.y]=1;
        if(eq(pn,e))
            return true;
        Point pu={pn.x-1,pn.y};
        Point pd={pn.x+1,pn.y};
        Point pr={pn.x,pn.y+1};
        Point pl={pn.x,pn.y-1};
        if(fea(a,visit,pu)){
            qlist.push(pu);
        }
        if(fea(a,visit,pd)){
            qlist.push(pd);
        }
        if(fea(a,visit,pr)){
            qlist.push(pr);
        }
        if(fea(a,visit,pl)){
            qlist.push(pl);
        }
    }
    return false;
}
int main(){
    int case_num;
    cin>>case_num;
    for(int k=0;k<case_num;k++){
    int n;
    cin>>n;
    vector<vector<int> > a;
    a.resize(n+2);
    for(int i=0;i<n+2;i++){
        a[i].resize(n+2);
    }
    getchar();
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            char c=getchar();
            a[i][j]=(c=='#')?0:1;
        }
        getchar();
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    Point start={x1+1,y1+1};
    Point end={x2+1,y2+1};
    if(wdf(a,start,end))
        cout<<"YES\n";
    else
        cout<<"NO\n";
    }//end case_num
    return 0;
}