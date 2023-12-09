#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> &arr, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = high;

    while (low <= mid && (mid + 1) <= right)
    {
        if (arr[left] <= arr[right])
        {
            temp.emplace_back(arr[left]);
            left++;
        }
        else
        {
            temp.emplace_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.emplace_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.emplace_back(arr[right]);
        right++;
    }
    for (int i = low; i < high; i++)
    {
        arr[i] = temp[i - low];
    }
}