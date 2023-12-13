#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Time Complexity : O(m+n)
//Space Complexity : O(m+n)

float median(int nums1[], int nums2[], int m, int n)
{
    int finalArray[n + m];

    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (nums1[i] < nums2[j])
        {
            finalArray[k++] = nums1[i++];
        }
        else
        {
            finalArray[k++] = nums2[j++];
        }
    }
    if (i < m)
    {
        while (i < m)
            finalArray[k++] = nums1[i++];
    }
    if (j < n)
    {
        while (j < n)
            finalArray[k++] = nums2[j++];
    }
    n = n + m;
    if (n % 2 == 1)
        return finalArray[((n + 1) / 2) - 1];
    else
        return ((float)finalArray[(n / 2) - 1] + (float)finalArray[(n / 2)]) / 2;
}


int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    cout << "The Median of two sorted arrays is:" << fixed << setprecision(5) << median(arr1, arr2, n1, n2);

    return 0;
}