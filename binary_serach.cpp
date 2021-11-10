#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> &nums, int left, int right, int target)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;

    if (nums[mid] == target)
    {
        return mid;
    }

    if (nums[mid] > target)
    {
        binarySearch(nums, left, mid - 1, target);
    }
    else
    {
        binarySearch(nums, mid + 1, right, target);
    }
}
int main()
{
    vector<int> numList({1, 2, 3, 4, 5});
    cout << binarySearch(numList, 0, numList.size() - 1, 10);
}