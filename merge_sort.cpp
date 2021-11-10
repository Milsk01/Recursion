#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int> &list, int left, int right, int mid)
{
    vector<int> temp;
    temp.resize(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        if (list[i] > list[j])
        {
            temp[k++] = list[j++];
        }
        else
        {
            temp[k++] = list[i++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = list[i++];
    }
    while (j <= right)
    {
        temp[k++] = list[j++];
    }

    i = left;

    for (auto &x : temp)
    {
        list[i++] = x;
    }
}
void mergeSort(vector<int> &list, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, right, mid);
    }
}

int main()
{
    vector<int> list({4, 1, 3, 2, 0, -1, 7, 10, 9, 20});
    mergeSort(list, 0, list.size() - 1);
    for (auto &x : list)
        cout << x << endl;
}