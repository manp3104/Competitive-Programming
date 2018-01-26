#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefixTable(string P)
{
    int m = P.size();
    vector<int> F(m);
    F[0] = 0;
    int j = 0, i = 1;
    while(i<m)
    {
        if(P[i]==P[j])
        {
            F[i] = j+1;
            j++;
            i++;
        }
        else if(j)
            j = F[j-1];
        else
        {
            F[i] = j;
            i++;
        }
    }

    cout << "Prefix Table:\n";
    for(int i=0;i<m;i++)
        cout << F[i] << " ";
    cout << endl;
    return F;
}

int stringMatching(string T, string P)
{
    vector<int> F = prefixTable(P);
    int n = T.size();
    int m = P.size();
    int i = 0, j = 0;
    while(i<n && j<m)
    {
        if(T[i]==P[j])
        {
            i++;
            j++;
        }
        else if(j)
            j = F[j-1];
        else
            i++;
    }
    return (j==m)?1:0;
}

int main()
{
    string T, P;
    cin >> T >> P;
    if(stringMatching(T, P))
        cout << "Found";
    else
        cout << "Not found";
    return 0;
}
