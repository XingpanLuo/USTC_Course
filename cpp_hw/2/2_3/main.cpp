#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
const int MAX=100;
using namespace std;
void dic(string &str,const vector<int> &key){
    const string con_str=str;
    int len=key.size();
    for(int i=0;i<len;i++){
        str[key[i]-1]=con_str[i];
    }
}
int main()
{
    int num_key=0;
    cin>>num_key;
    //cout<<num_key;
    vector<int> key;
    getchar();
    for(int i=0;i<num_key;i++){
        int temp;
        cin>>temp;
        key.push_back(temp);
        //cout<<"temp:"<<temp<<endl;
    }
    getchar();
    int dic_num=0;
    cin>>dic_num;
    getchar();
    char c_str[MAX];
    cin.getline(c_str,MAX);
    string str=string(c_str);
    for(int i=strlen(c_str);i<num_key;i++){
        str.push_back(' ');
    }
    //cout<<str.length()<<endl;
    //cout<<c_str;
    for(int i=0;i<dic_num;i++){
        dic(str,key);
    }
    cout<<str<<endl;
    return 0;
}