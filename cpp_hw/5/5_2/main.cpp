#include <iostream>
#include <fstream>
#include <cmath>
#include <bits/stdc++.h>
#include <vector>
#define IFZERO(A,B) (abs((A)-(B))<(1e-15))
using namespace std;
double f[4][4];
double n[4];
bool dfs(double a[],int num){
    if(num==1){
        if(IFZERO(a[0],24))
            return true;
        else 
            return false;
    }
    // else if(num==2){
    //     if(IFZERO(a[0]+a[1],24)){
    //         return true;
    //     }
    //     else if(IFZERO(a[0]-a[1],24)){
    //         return true;
    //     }
    //     else if(IFZERO(a[1]-a[0],24)){
    //         return true;
    //     }
    //     else if(IFZERO(a[0]*a[1],24)){
    //         return true;
    //     }
    //     else if(IFZERO(a[0]/a[1],24)){
    //         return true;
    //     }
    //     else if(IFZERO(a[1]/a[0],24)){
    //         return true;
    //     }
    // }
    else {
        for(int i=0;i<num-1;i++){
            for(int j=i+1;j<num;j++){
                double b[num-1];
                int m=0;
                for(int k=0;k<num;k++){
                    if(k!=i&&k!=j)
                        b[m++]=a[k];
                }
                b[m]=a[i]+a[j];
                if(dfs(b,m+1))
                    return true;
                b[m]=a[i]-a[j];
                if(dfs(b,m+1))
                    return true;
                b[m]=a[j]-a[i];
                if(dfs(b,m+1))
                    return true;
                b[m]=a[i]*a[j];
                if(dfs(b,m+1))
                    return true;
                b[m]=a[i]/a[j];
                if(dfs(b,m+1))
                    return true;               
                b[m]=a[j]/a[i];
                if(dfs(b,m+1))
                    return true;
            }
        }
        return false;
    }
}
int main()
{
    bool stop=false;

    while(!stop){
        for(int i=0;i<4;i++){
            cin>>n[i];
        }
        if(n[0]+n[1]+n[2]+n[3]==0){
            stop=true;
            break;
        }
        if(dfs(n,4))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
