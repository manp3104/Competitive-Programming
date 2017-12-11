#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> addNum(vector<int> n, vector<int> m)
{
    for(int i=0;i<n.size();i++)
        cout << n[i];
    cout << endl;

    for(int i=0;i<m.size();i++)
        cout << m[i];
    cout << endl;


    reverse(n.begin(), n.end());
    reverse(m.begin(), m.end());

    if(n.size() >= m.size())
    {
        int temp, carry = 0, i = 0;
        while(i<m.size())
        {
            temp = carry + n[i] + m[i];
            n[i] = temp%10;
            carry = temp/10;
            i++;
        }
        if(i<n.size())
        {
            while(i<n.size() && carry!=0)
            {
                int tmp = carry + n[i];
                n[i] = tmp%10;
                carry = tmp/10;
                i++;
            }
            if(carry)
                n.push_back(carry);
        }

        else if(carry)
            n.push_back(carry);

        reverse(n.begin(), n.end());

        /*
        for(int i=0;i<n.size();i++)
            cout << n[i];
        cout << endl;
        */
        return n;
    }
    else
    {
        int temp, carry = 0, i = 0;
        while(i<n.size())
        {
            temp = carry + m[i] + n[i];
            m[i] = temp%10;
            carry = temp/10;
            i++;
        }
        if(i<m.size())
        {
            while(i<m.size() && carry!=0)
            {
                int tmp = carry + m[i];
                m[i] = tmp%10;
                carry = tmp/10;
                i++;
            }
            if(carry)
                m.push_back(carry);
        }
        else
            m.push_back(carry);

        reverse(m.begin(), m.end());

        /*
        for(int i=0;i<m.size();i++)
            cout << m[i];
        cout << endl;
        */
        return m;
    }

}

int main()
{
    int num;

    vector<int> n{7, 2, 9, 0};
    vector<int> m{1, 9, 6, 8};

    //n.erase(n.begin(), n.begin()+1);

    for(int i=0;i<n.size();i++)
        cout << n[i] << " ";
    cout << endl;


    vector<int> result(addNum(n, m));

    for(int i=0;i<result.size();i++)
        cout << result[i];

    return 0;
}
