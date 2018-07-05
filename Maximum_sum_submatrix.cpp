#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int kadane(vector<int> A, int &cUp, int &cDown) {

    int current_sum = A[0];
    int max_sum = A[0];

    int a = 0;
    cUp = 0;
    cDown = 0;

    for(int i=1;i<A.size();i++) {
        current_sum = max(current_sum+A[i], A[i]);
        if(current_sum > max_sum) {
            a++;
            if(a==1)
                cUp = i;
            max_sum = current_sum;
            cDown = i;
        }

    }

    return max_sum;
}

void maxSubmatrixSum(vector<vector<int> > data) {

    int n = data.size();
    int m = data[0].size();

    int curr_sum = 0;
    int max_sum = 0;

    int maxLeft = 0;
    int maxRight = 0;
    int maxUp = 0;
    int maxDown = 0;

    for(int l=0;l<m;l++) {

        vector<int> sum(n, 0);
        for(int r=l;r<m;r++) {

            for(int j=0;j<n;j++) {
                sum[j] += data[j][r];
            }
            int cUp, cDown;
            curr_sum = kadane(sum, cUp, cDown);
            if(curr_sum > max_sum) {
                max_sum = curr_sum;
                maxRight = r;
                maxLeft = l;
                maxDown = cDown;
                maxUp = cUp;
            }

        }
    }

    cout << max_sum << "\t" << maxLeft << " " << maxRight << " " << maxUp << " " << maxDown << endl;

}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > data;

    for(int i=0;i<n;i++) {
        vector<int> row(m);
        for(int j=0;j<m;j++)
            cin >> row[j];
        data.push_back(row);
    }

    maxSubmatrixSum(data);

    return 0;
}

