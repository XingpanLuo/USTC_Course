#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void print_vec(vector<int>&a,vector<int>&b){
    int len_a=a.size();
    int len_b=b.size();
    for(int i=len_a-1;i>=0;i--){
        cout<<a[i];
    }
    int stop=0;
    for(int i=0;i<len_b;i++){
        stop=i;
        if(b[i]!=0){
            break;
        }
    }
    // for(int i=0;i<len_b;i++){
    //     cout<<b[i];
    // }
    // cout<<"stop:"<<stop<<endl;
    if(stop==len_b-1&&b[stop]==0) stop=len_b; 
    else{
        cout<<".";
    }
    for(int i=len_b-1;i>=stop;i--){
        cout<<b[i];
    }
    cout<<endl;
}
vector<int> sum1(vector<int>&a,vector<int>&b){
    vector<int> sum;
    int temp=0;
    int add=0;
    int i=a.size()-1;
    int j=b.size()-1;
    for(;i>=0||j>=0;i--,j--){
        int temp_a=(i>=0)?a[i]:0;
        int temp_b=(j>=0)?b[j]:0;
        add=temp_a+temp_b+temp;
        temp=0;
        if((i>0||j>0)&&add>=10){
            sum.push_back(add%10);
            temp=add/10;
        }
        else{
            sum.push_back(add);
        }
    }
    return sum;
}
vector<int> sum2(vector<int>&a,vector<int>&b){
    vector<int> sum;
    int temp=0;
    int add=0;
    int len=a.size()>b.size()?a.size():b.size();
    for(int i=len;i>=0;i--){
        int temp_a=i<a.size()?a[i]:0;
        int temp_b=i<b.size()?b[i]:0;
        add=temp_a+temp_b+temp;
        temp=0;
        if(i!=0&&add>=10){
            sum.push_back(add%10);
            temp=add/10;
        }
        else{
            sum.push_back(add);
        }
    }
    return sum;
}
void str2vec(string a,vector<int> &num_a,vector<int> &num_b){
    bool flag=true;
    for(int i=0;i<a.length();i++){
        char temp=a[i];
        if(temp!='.') {
            if(flag){
                num_a.push_back(a[i]-'0');
            }
            else{
                num_b.push_back(a[i]-'0');
            }
        }
        else{
            flag=false;
        }
    }
}
int main()
{
    string a;
    string b;
    cin>>a;
    cin>>b;
    vector<int> num_af;
    vector<int> num_ar;
    vector<int> num_bf;
    vector<int> num_br;
    str2vec(a,num_af,num_ar);
    str2vec(b,num_bf,num_br);
    auto sum_r=sum2(num_ar,num_br);
    if(sum_r[sum_r.size()-1]>=10){
        num_af[num_af.size()-1]+=sum_r[sum_r.size()-1]/10;
        sum_r[sum_r.size()-1]%=10;
    }
    auto sum_f=sum1(num_af,num_bf);
    if(sum_f[sum_f.size()-1]>=10){
        int temp=sum_f[sum_f.size()-1]/10;
        sum_f[sum_f.size()-1]%=10;
        sum_f.push_back(temp);
    }
    print_vec(sum_f,sum_r);
    return 0;
}