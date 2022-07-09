#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int  str2vec(string a,vector<int> &num_a){
    bool flag=false;
    int n=a.length()-1;
    for(int i=0;i<a.length();i++){
        char temp=a[i];
        if(temp!='.') {
            if(!flag&&a[i]=='0') continue;
            else {
                flag=true;
                num_a.push_back(a[i]-'0');
            }
        }
        else{
            n=i;
        }
    }
    n=a.length()-1-n;
    return n;
}

vector<int> mul(vector<int>&num_a,vector<int>&num_b)
{
    int len_a=num_a.size();
    int len_b=num_b.size();
    auto result=vector<int>(len_a+len_b-1,0);
    int mul_a=0,mul_b=0,mul=0;
    for(int i=len_b-1;i>=0;i--){
        for(int j=len_a-1;j>=0;j--){
            result[i+j]+=num_a[j]*num_b[i];
        }
    }
    int temp=0;
    for(int i=result.size()-1;i>=0;i--){
        result[i]+=temp;
        temp=result[i]/10;
        result[i]%=10;
    }
    if(temp!=0){
        result.insert(result.begin(),temp);
    }
    return result;
}
int main()
{
    string a;
    int num;
    bool next;
    if(cin>>a>>num) next=true;
    while(next){
    vector<int> num_a;
    int n=str2vec(a,num_a);
    // cout<<"num_a:";
    // for(auto i:num_a) cout<<i;
    // cout<<endl;
    vector<int> one={1};
    auto result=mul(num_a,one);
    for(int i=0;i<num-1;i++){
        result=mul(num_a,result);
    }
    // cout<<"result:";
    // for(auto i:result) cout<<i;
    // cout<<endl;
    int all_num=num*n;
    // cout<<"all_num:"<<all_num<<endl;
    if(all_num>=result.size()){
        int len=result.size();
        for(int j=0;j<all_num-len;j++){
            result.insert(result.begin(),0);
        }
    }
    // cout<<"result:";
    // for(auto i:result) cout<<i;
    // cout<<endl;
    if(all_num!=0){
        int temp_num=result.size()-1-all_num;
        for(int i=result.size()-1;i>temp_num;i--){
            if(result[i]==0){
                 result.pop_back();
                 all_num--;
            }
            else break;
        }
    }

    for(int j=0;j<result.size();j++){
        if(j==result.size()-all_num) cout<<".";
        cout<<result[j];
    }
    if(cin>>a>>num) {
        next=true;
        cout<<endl;
    }
    else next=false;
    }
    return 0;
}