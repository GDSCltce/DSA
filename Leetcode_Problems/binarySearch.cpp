#include <bits/stdc++.h>
using namespace std;

int nearlySortedArray(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, mid;
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (nums[mid] == target)
        {
            return mid;
        }
        if (mid > low && nums[mid - 1] == target)
        {
            return mid - 1;
        }
        if (mid < high && nums[mid + 1] == target)
        {
            return mid + 1;
        }
        if (nums[mid] > target)
        {
            high = mid - 2;
        }
        else
        {
            low = mid + 2;
        }
    }
    return -1;
}

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0, high = nums.size() - 2, mid;
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (nums[mid] == nums[mid ^ 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return nums[low];
}

int floor(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, mid, ans;
    if (nums[low] > target)
    {
        return -1;
    }
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (nums[mid] == target)
        {
            return nums[mid];
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            ans = nums[mid];
            low = mid + 1;
        }
    }
    return ans;
}

int minDiffernce(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, mid, ans;
    if (nums[low] > target)
    {
        return -1;
    }
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (nums[mid] == target)
        {
            ans = mid;
            return mid;
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return (abs(target - nums[ans]) < abs(target - nums[ans + 1])) ? (ans) : (ans + 1);
}

int ceil(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1, mid, ans;
    if (target > nums[high])
    {
        return -1;
    }
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (nums[mid] == target)
        {
            return nums[mid];
        }
        else if (nums[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return nums[low];
}

int searchFOrFirstAndlast(vector<int> &arr, int key, bool forStart)
{
    int low = 0, high = arr.size() - 1;
    int ans = -1;
    bool check = arr[low] < arr[high];
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (arr[mid] == key)
        {
            // return mid;
            ans = mid;
            if (forStart)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else if (check)
        {
            (arr[mid] > key) ? (high = mid - 1) : (low = mid + 1);
        }
        else
        {
            (arr[mid] < key) ? (high = mid - 1) : (low = mid + 1);
        }
    }
    return ans;
}

vector<int> findFirstAndLast(vector<int> &arr, int key)
{
    vector<int> ans(2, -1);
    ans[0] = searchFOrFirstAndlast(arr, key, 1);
    if (ans[0] != -1)
    {
        ans[1] = searchFOrFirstAndlast(arr, key, 0);
    }
    return ans;
}

int sqrt(long long int n)
{
    int low = 1, high = n, ans = -1;
    while (low <= high)
    {
        long long int mid = low + ((high - low) >> 1);
        long long int mSq = mid * mid * 1ll;
        if (mSq == n)
        {
            return mid;
        }
        else if (mSq > n)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

int numberRotation(vector<int> &arr)
{

    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (arr[mid] > arr[mid + 1])
        {
            return mid + 1;
        }
        else if (arr[mid] < arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid] < arr[high])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int search(vector<int> &arr, int low, int high)
{
    int mid;
    while (low <= high)
    {
        mid = low + ((high - low) >> 1);
        if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0))
        {
            return mid;
        }
        else if (arr[mid] == 1)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int infinite0_1(vector<int> &nums)
{
    if (nums[0] == 1)
    {
        return 0;
    }
    int low = 0, high = 1;
    while (0 == nums[high])
    {
        low = high;
        high = high << 1;
    }
    return search(nums, low, high);
}

int infiniteSorted(vector<int> &nums, int target)
{
    int low = 0, high = 1;
    if (nums[0] == target)
    {
        return 0;
    }
    while (low <= high)
    {
        if (nums[high] < target)
        {
            low = high;
            high = high << 1;
        }
        else
        {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

pair<int, int> binarySearch2D(vector<vector<int>> &nums, int target)
{
    int n = nums.size();
    int m = nums[0].size();
    pair<int, int> ans = {-1, -1};

    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (target == nums[i][j])
        {
            ans.first = i + 1, ans.second = j + 1;
            return ans;
        }
        else if (target < nums[i][j])
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return ans;
}

bool binarySearch2Da(vector<vector<int>> &nums, int target)
{
    int n = nums.size();
    int m = nums[0].size();
    int l = 0, h = (n * m) - 1, mid;
    while (l <= h)
    {
        mid = l + ((h - l) >> 1);
        if (target == nums[mid / m][mid % m])
        {
            return true;
        }
        else if (target > nums[mid / m][mid % m])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return 0;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    int low = 0, high = n;
    while (low <= high)
    {
        int i1, i2, min1, min2, max1, max2;
        i1 = low + ((high - low) >> 1);
        i2 = ((low + high + 1) >> 1 * 1LL) - i1;
        min1 = (i1 == n) ? INT_MAX : nums1[i1];
        min2 = (i2 == n) ? INT_MAX : nums2[i2];
        max1 = (i1 == 0) ? INT_MIN : nums1[i1];
        max1 = (i2 == 0) ? INT_MIN : nums2[i2];

        if ((max1 <= min2) & (max2 <= min1))
        {
            if ((n + m) & 1)
                return max(max1, max2);
            else
                return ((max(max1, max2) + min(min1, min2)) >> 1);
        }
        else if (max1 > min2)
        {
            high = i1 - 1;
        }
        else
        {
            low = i1 + 1;
        }
    }
    return 0.0;
}

inline void solve()
{
}

int main()
{
    solve();

    return 0;
}
