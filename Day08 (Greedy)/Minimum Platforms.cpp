// Given arrival and departure times of all trains that reach a railway station. 
// Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day. 
// Arrival and departure time can never be the same for a train but we can have arrival time of one train 
// equal to departure time of the other. At any given instance of time, same platform can not be used for 
// both departure of a train and arrival of another train. In such cases, we need different platforms.

// Example 1:

// Input: n = 6 
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3
// Explanation: 
// Minimum 3 platforms are required to 
// safely arrive and depart all trains.
// Example 2:

// Input: n = 3
// arr[] = {0900, 1100, 1235}
// dep[] = {1000, 1200, 1240}
// Output: 1
// Explanation: Only 1 platform is required to 
// safely manage the arrival and departure 
// of all trains. 


class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool compare(pair<int, char>&p1, pair<int, char>&p2){
        if(p1.first == p2.first)
            return p1.second < p2.second; //arrival first
        return p1.first < p2.first;
    }
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	vector<pair<int, char>> t;
    	for(int i=0; i<n; i++){
    	    t.push_back({arr[i], 'a'});
    	    t.push_back({dep[i], 'd'});
    	}
    	
    	sort(t.begin(), t.end(), compare);
    	int res = 0;
    	int curr = 0;
    	for(int i=0; i<t.size(); i++){
    	    if(t[i].second == 'a')
    	        curr++;
    	    else
    	        curr--;
    	        
    	    res = max(res, curr);
    	}
    	return res;
    }
};