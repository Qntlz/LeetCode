void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int mid = m - 1;
    int ctr = n - 1;
    int i = m + n - 1;

    while (ctr >= 0) {
        if (mid >= 0 && nums1[mid] > nums2[ctr]) {
            nums1[i] = nums1[mid];
            mid--;
        } else {
            nums1[i] = nums2[ctr];
            ctr--;
        }
        i--;
    }
}