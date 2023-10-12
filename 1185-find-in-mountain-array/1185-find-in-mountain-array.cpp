/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
private:
    int ref = -1; // Initialize ref to -1

    void rec(MountainArray &mountainArr, int start, int end, int target) {
        if (start > end) {
            return;
        }

        int mid = (start + end) / 2;
        int midval = mountainArr.get(mid);

        if (midval == target) {
            ref = mid;
            return;
        }

        if (midval > target) {
            rec(mountainArr, start, mid - 1, target);
            if (ref < 0) {
                rec(mountainArr, mid + 1, end, target);
            }
        } else {
            rec(mountainArr, mid + 1, end, target);
            if (ref == -1) {
                rec(mountainArr, start, mid - 1, target);
            }
        }
    }

public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 0;
        int end = mountainArr.length() - 1;

        int s = start, e = end;
        while (s < e) {
            int mid = (s + e) / 2;
            if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        int peak = s;
        if (target > mountainArr.get(peak)) {
            return -1;
        }

        rec(mountainArr, start, peak, target);
        if (ref < 0) {
            rec(mountainArr, peak + 1, end, target);
        }
        return ref;
    }
};
