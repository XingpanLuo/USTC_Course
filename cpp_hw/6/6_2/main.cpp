#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n = 0, k = 0, sum = 0, count = 0;
int len[10005] = {0};

int cou(int c)
{
    int count = 0;
    for(int j = n - 1; j >= 0; --j)
    {
        count += len[j] / c;
    }
    return count;
}


int main(int argc,const char *argv[])
{
    scanf("%d%d", &n, &k);
    for(int i = 0 ; i < n ; ++i)
    {
        scanf("%d", &len[i]);
        sum += len[i];
    }
    sort(len, len + n);
    if(k > sum) printf("0\n");
    else
    {
        int left = 1, right = sum / k, mid = (left + right) / 2;
        while (true)
        {
            if(left == right) break;
            if(right - left == 1)
            {
                //if(cou(right) != cou(mid)) 
                //cout<<left<<" "<<mid<<" "<<right<<endl;
                if(cou(right)<k)
                    right = left;
                // if(cou(left)>=k)
                //     right=left;
                break;
            }
            if(cou(mid) < k)
            {
                right = mid;
                mid = (left + right) / 2;
            }
            else
            {
                left = mid;
                mid = (left + right) / 2;
            }
        }
        printf("%d\n", right);
    }
    return 0;
}