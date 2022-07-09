#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m=0;
    cin>>m;
    int max=0;
    int a1=0,a2=0,a3=0;
    int ans[3]={0};
    for(a1=m;a1>=0;a1--){
        if(a1+2*m<max) break;
        a2=2*m-a1;
        while(a2>m) a2-=2;
        for(;a2>=0;a2=a2-2){
            if(a1+a2+m<max) break;
            a3=(2*m)/3*3-a2;
            while(a3>m) a3-=3;
            for(;a3>=0;a3=a3-3){
                if((a1+a2+a3)%5==0){
                    if(a1+a2+a3>max){
                        max=a1+a2+a3;
                        ans[0]=a1;
                        ans[1]=a2;
                        ans[2]=a3;
                    }
                    else
                        break;
                }
            }
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    return 0;
}