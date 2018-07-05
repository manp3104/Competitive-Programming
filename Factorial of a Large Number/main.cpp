#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void multiplyNum(int n, vector<int>& result)
{
    int carry = 0, temp;
    for(int i=0;i<result.size();i++)
    {
        temp = n*result[i] + carry;
        result[i] = temp%10;
        carry = temp/10;
    }
    while(carry > 0)
    {
        result.push_back(carry%10);
        carry = carry/10;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> result;
    result.push_back(1);

    if(n<2)
        cout << 1 << endl;
    else
    {
        for(int i=2;i<=n;i++)
            multiplyNum(i, result);
        reverse(result.begin(), result.end());

        for(int i=0;i<result.size();i++)
            cout << result[i];
    }
    return 0;
}
