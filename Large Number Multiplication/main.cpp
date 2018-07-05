#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

vector<int> multiplyNum(vector<int> num1, vector<int> num2)
{

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());


    // multiplying the numbers

    vector<int> tempVec;
    vector<int> carryVec;

    for(int i=0;i<num1.size();i++)
    {
        int local_temp, local_carry = 0;
        for(int j=0;j<num2.size();j++)
        {
            local_temp = num1[i]*num2[j] + local_carry;
            tempVec.push_back(local_temp%10);

            local_carry = local_temp/10;
        }
        if(local_carry)
            tempVec.push_back(local_carry);


        if(!carryVec.empty())
        {
            if(tempVec.size() >= carryVec.size())
            {
                int temp, carry = 0, l = 0;
                while(l<carryVec.size())
                {
                    temp = carry + tempVec[l] + carryVec[l];
                    tempVec[l] = temp%10;
                    carry = temp/10;
                    l++;
                }
                if(l<tempVec.size())
                {
                    while(l<tempVec.size() && carry!=0)
                    {
                        int tmp = carry + tempVec[l];
                        tempVec[l] = tmp%10;
                        carry = tmp/10;
                        l++;
                    }
                    if(carry)
                        tempVec.push_back(carry);
                }

                else if(carry)
                    tempVec.push_back(carry);

                //reverse(tempVec.begin(), tempVec.end());


            }
            else
            {
                int temp, carry = 0, l = 0;
                while(l<tempVec.size())
                {
                    temp = carry + carryVec[l] + tempVec[l];
                    carryVec[l] = temp%10;
                    carry = temp/10;
                    l++;
                }
                if(l<carryVec.size())
                {
                    while(l<carryVec.size() && carry!=0)
                    {
                        int tmp = carry + carryVec[l];
                        carryVec[l] = tmp%10;
                        carry = tmp/10;
                        l++;
                    }
                    if(carry)
                        carryVec.push_back(carry);
                }
                else
                    carryVec.push_back(carry);

                //reverse(carryVec.begin(), carryVec.end());


                tempVec.swap(carryVec);
            }
        }
        num1[i] = tempVec.front();
        tempVec.erase(tempVec.begin(), tempVec.begin()+1);
        carryVec.clear();

        for(int k=0;k<tempVec.size();k++)
            carryVec.push_back(tempVec[k]);
        tempVec.clear();
    }


    for(int i=0;i<carryVec.size();i++)
        num1.push_back(carryVec[i]);
    carryVec.clear();


    reverse(num1.begin(), num1.end());

    return num1;
}

int main()
{
    int m;

    // 1st number input

    string str1;
    getline(cin, str1);

    vector<int> num1;
    stringstream ss(str1);
    while(ss >> m)
        num1.push_back(m);


    // 2nd number input

    string str2;
    getline(cin, str2);
    vector<int> num2;
    stringstream sst(str2);
    while(sst >> m)
        num2.push_back(m);

    vector<int> result(multiplyNum(num1, num2));

    for(int i=0;i<result.size();i++)
        cout << result[i];

    return 0;
}
