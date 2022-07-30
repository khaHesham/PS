
#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> tree, int index)
{
    if (index == tree.size())
        return 0;

    int sum_left = 0;
    if (2 * index + 1 < tree.size())
        sum_left = sum(tree, 2 * index + 1);

    int sum_right = 0;
    if (2 * index + 2 < tree.size())
        sum(tree, 2 * index + 2);

    return tree[index] + sum_left + sum_right;
}

int mostBalancedPartition(vector<int> parent, vector<int> files_size)
{
    int min = INT_MAX;
    int left = 0;
    int right = 0;

    for (int i = 0; i < parent.size(); i++)
    {
        int j = 2 * i + 1;
        left = sum(files_size, j);
        int k = 2 * i + 2;
        right = sum(files_size, k);

        if (abs(left - right) < min)
            min = abs(left - right);
    }

    return min;
}


int main()
{

    return 0;

}