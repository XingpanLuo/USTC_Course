#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// vector<int> decompose(int a,int min){
//     vector<int> result={0,a};
//     for(int i=min;i<a;i++){
//         if(a%i==0){
//             int a1=i;
//             int a2=a/i;
//             if(a1>a2){
//                 int temp=a2;
//                 a2=a1;
//                 a1=temp;
//             }
//             result[0]=a1;
//             result[1]=a2;
//             return result;
//         }
//     }
//     return result;
// }
// int main(){
//     int a;
//     cin>>a;
//     vector<int> list;
//     list.push_back(1);
//     auto dec=decompose(a,2);
//     while(dec[0]!=0){
//         list.push_back(dec[0]);
//         dec=decompose(dec[1],dec[0]);
//     }
//     list.push_back(dec[1]);
//     for(auto i:list)
//         cout<<i;
//     return 0;
// }
int count=0;
void js(int b,int aa){
    if(aa==1){
        count++;
        return;
    }
    else{
        for(int i=b;i<=aa;i++){
            if(aa%i==0){
                js(i,aa/i);
            }
        }
    }
}
int main(){
    int a;
    count=0;
    cin>>a;
    js(2,a);
    cout<<count;
    return 0;
}