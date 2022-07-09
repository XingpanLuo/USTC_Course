#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
struct castle{
    int x;//房间位于(x,y)
    int y;
    int n;//n=1 表示北方有墙
    int s;
    int w;
    int e;
};
typedef struct castle Castle;

int cw[]={1,3,5,9,7,11,13,15};
int cn[]={2,3,6,10,7,11,14,15};
int cs[]={8,9,10,12,11,13,14,15};
int ce[]={4,5,6,7,12,13,14,15};
int try_visit(vector<vector<Castle>>&cas,vector<vector<int>>&visit,int x,int y){
    queue<Castle> qlist;
    int num=0;
    qlist.push(cas[x][y]);
    while(!qlist.empty()){
        Castle c=qlist.front();
        visit[c.x][c.y]=1;
        qlist.pop();
        //cout<<c.x<<" "<<c.y<<endl;
        num++;
        if(c.n==0&&visit[c.x-1][c.y]==0)
            qlist.push(cas[c.x-1][c.y]);
        if(c.s==0&&visit[c.x+1][c.y]==0)
            qlist.push(cas[c.x+1][c.y]);
        if(c.w==0&&visit[c.x][c.y-1]==0)
            qlist.push(cas[c.x][c.y-1]);
        if(c.e==0&&visit[c.x][c.y+1]==0)
            qlist.push(cas[c.x][c.y+1]);
    }
    return num;
}
int main(){
    int max=0;
    int n,m;
    cin>>n>>m;
    vector<vector<Castle> > cas;
    vector<vector<int> > visit;
    visit.resize(n+2);
    cas.resize(n+2);
    for(int i=0;i<n+2;i++){
        cas[i].resize(m+2);
        visit[i].resize(m+2);
    }
    for(int i=0;i<m;i++){
        visit[0][i]=1;
        visit[n+1][i]=1;
    }
    for(int i=0;i<n;i++){
        visit[i][0]=1;
        visit[i][m+1]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            int temp;
            cin>>temp;
            Castle c={i,j,0,0,0,0};
            for(int k=0;k<8;k++){
                if(temp==cn[k])
                    c.n=1;
                if(temp==cs[k])
                    c.s=1;
                if(temp==cw[k])
                    c.w=1;
                if(temp==ce[k])
                    c.e=1;
            }
            cas[i][j]=c; 
        }
    }
    bool flag=true;
    int x=1,y=1;
    int count=0;
    while(flag){
        int result=try_visit(cas,visit,x,y);
        count++;
        if(result>max)
            max=result;
        flag=false;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(visit[i][j]==0){
                    x=i;
                    y=j;
                    flag=true;
                    break;
                }
            }
        }
    }
    cout<<count<<endl<<max<<endl;
    return 0;
}