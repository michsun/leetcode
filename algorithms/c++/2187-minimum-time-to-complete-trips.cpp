// https://leetcode.com/problems/minimum-time-to-complete-trips/
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long trips(vector<int>& time, int totalTrips, long long t) {
        long long ntrips = 0;
        int i = 0; 
        while(i < time.size() && time[i] <= t) {
            ntrips += t/time[i++];
            if (ntrips > totalTrips) // prevent overflow
                return ntrips;
        }
        return ntrips;
    }
    
    long long binarySearch(vector<int>& time, int totalTrips, long long left, long long right) {
        while(left < right) {
            long long mid = left + (right-left)/2;
            long long nTrips = trips(time, totalTrips, mid);
            if (nTrips >= totalTrips && (mid == time[0] || trips(time, totalTrips, mid-1) < totalTrips))
                return mid;
            else if (nTrips >= totalTrips)
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin(), time.end());
        
        long long shortestTime = time[0];
        long long longestTime = LLONG_MAX-1;
        long long t = binarySearch(time, totalTrips, shortestTime, longestTime);
        
        return t;
    }
};

int main() {

    return 0;
}