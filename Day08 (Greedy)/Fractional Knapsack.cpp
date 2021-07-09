// Given weights and values of N items, we need to put these items 
//in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item. 

// Example 1:

// Input:
// N = 3, W = 50
// values[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.00
// Explanation:Total maximum value of item
// we can have is 240.00 from the given
// capacity of sack. 
// Example 2:

// Input:
// N = 2, W = 50
// values[] = {60,100}
// weight[] = {10,20}
// Output:
// 160.00
// Explanation:
// Total maximum value of item
// we can have is 160.00 from the given
// capacity of sack.

class Solution
{
    public:
   static bool compare(Item a, Item b){
        double a1 = (double)a.value / (double)a.weight;
        double b1 = (double)b.value / (double)b.weight;
        
        return a1 > b1;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n)
    {
        sort(arr, arr+n, compare);
        
        int curr  = 0;
        double res_value = 0;
        
        for(int i=0; i<n; i++){
            if(curr + arr[i].weight <= w){
                curr += arr[i].weight;
                res_value += arr[i].value;
            }
            else{
                int temp = w - curr;
                res_value += arr[i].value * ((double)temp / arr[i].weight);
                break;
            }
        }
        return res_value;
    }
        
};
