#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;
const int MAX = 100;
int main()
{
    char temp[MAX];
    map<string, string> dict_map;
    //ifstream inFile("in.txt", ios::in | ios::binary);
    // if (!inFile)
    //     exit(0);
    cin.getline(temp, MAX);
    while (temp[0] != '\0')
    {
        bool flag = true;
        string word, dict;
        for (unsigned int i = 0; i < strlen(temp); i++)
        {
            if (temp[i] == ' ')
            {
                flag = false;
            }
            else if (flag)
            {
                word.push_back(temp[i]);
            }
            else
            {
                dict.push_back(temp[i]);
            }
        }
        // auto map_temp=make_pair(dict,word);
        dict_map.insert(make_pair(dict, word));
        temp[0]='\0';
        cin.getline(temp, MAX);
    }
    cin.getline(temp, MAX);
    while (temp[0] != '\0')
    {
        auto iter = dict_map.find(temp);
        if (iter == dict_map.end())
        {
            cout << "eh\n";
        }
        else
        {
            cout << iter->second<<endl;
        }
        cin.getline(temp, MAX);
    }
    return 0;
}