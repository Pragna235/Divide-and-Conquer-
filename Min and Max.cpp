#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Divide and conquer solution to find the minimum and maximum number in an array
void findMinAndMax(vector<int> const &nums, int low, int high, int &min, int &max)
{
    // if the array contains only one element

    if (low == high)                    // common comparison
    {
        if (max < nums[low]) {           // comparison 1
            max = nums[low];
        }

        if (min > nums[high]) {          // comparison 2
            min = nums[high];
        }

        return;
    }

    // if the array contains only two elements

    if (high - low == 1)                // common comparison
    {
        if (nums[low] < nums[high])       // comparison 1
        {
            if (min > nums[low]) {       // comparison 2
                min = nums[low];
            }

            if (max < nums[high]) {      // comparison 3
                max = nums[high];
            }
        }
        else {
            if (min > nums[high]) {      // comparison 2
                min = nums[high];
            }

            if (max < nums[low]) {       // comparison 3
                max = nums[low];
            }
        }
        return;
    }

    // find the middle element
    int mid = (low + high) / 2;

    // recur for the left subarray
    findMinAndMax(nums, low, mid, min, max);

    // recur for the right subarray
    findMinAndMax(nums, mid + 1, high, min, max);
}

int main()
{
    vector<int> nums = { 7, 2, 9, 3, 1, 6, 7, 8, 4 };

    // initialize the minimum element by INFINITY and the
    // maximum element by -INFINITY
    int max = INT_MIN, min = INT_MAX;

    int n = nums.size();
    findMinAndMax(nums, 0, n - 1, min, max);

    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max << endl;

    return 0;
}
