#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    using namespace std;
    int n=0;
    cin>>n;
    vector<int> number={2};
    for(int i=0;i<n-1;i++){
        int len=number.size();
        int temp=0;
        for(int j=len-1;j>=0;j--){
            number[j]*=2;
            number[j]+=temp;
            temp=0;
            if(number[j]>=10){
                temp=number[j]/10;
                number[j]-=10;
            }
        }
        if(temp!=0){
            number.insert(number.begin(),temp);
        }
    }
    for(int i=0;i<number.size();i++){
        cout<<number[i];
    }
    cout<<endl;
}