#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Num
{
    string left;
    string right;
    int point;
};

int main()
{
    int n;
    cin>>n;
    auto num_s=vector<string>(n);
    vector<int> point;
    for(int i=0;i<n;i++){
        cin>>num_s[i];
        string str=num_s[i];
        for(int j=0;j<str.length();j++){
            if(str[j]=='.') point.push_back(j);
        }
    }
    auto max_p=max_element(point.begin(),point.end());
    int max=*max_p;
    for(int i=0;i<n;i++){
        for(int j=0;j<max-point[i];j++)
            cout<<" ";
        cout.unsetf(ios::showpoint);
        cout<<num_s[i]<<endl;
    }
    return 0;
}