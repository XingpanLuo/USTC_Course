#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
const int MAX = 100;
int main()
{
    using namespace std;
    vector<string> arr;
    vector<string> ans;
    char temp[MAX];
    int maxLength = 0;
    cin.getline(temp, MAX);
    while (temp[0] != '\0')
    {
        string str = temp;
        arr.push_back(str);
        ans.push_back("");
        if(str.length()>maxLength){
            maxLength=str.length();
        }
        cin.getline(temp, MAX);
    }
    int n=arr.size();
    for (int i = 0; i < maxLength; i++)
    {
        map<string, int> map_list;
        for (int j = 0; j < n; j++) //第j行字符串
        {
            if (ans[j].size() == 0)
            {
                string temp = "";
                for (int k = 0; k <= i; k++)
                {
                    temp += arr[j][k];
                }
                cout<<temp<<endl;
                if (!map_list.count(temp))
                {
                    map_list[temp] = 1;
                }
                else
                {
                    map_list[temp]++;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (ans[j].size() == 0)
            {
                string temp = "";
                for (int k = 0; k <= i; k++)
                {
                    temp += arr[j][k];
                }
                if (map_list[temp] == 1 || temp == arr[j])
                {
                    ans[j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" "<<ans[i] << endl;
    }
    return 0;
}
