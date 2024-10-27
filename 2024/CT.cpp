#include <bits/stdc++.h>
using namespace std;

// Function to compute the final k based on the permutation
long long compute_k(const vector<int>& perm) {
    long long k = 0;
    int n = perm.size();
    for(int i = 0; i < n; ++i){
        if((i+1) % 2 == 1){
            k &= perm[i];
        }
        else{
            k |= perm[i];
        }
    }
    return k;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> perm(n, 0);
        if(n % 2 == 1){
            // For odd n
            // Assign p1=2, p2=1
            perm[0] = 2;
            perm[1] = 1;
            // Assign the remaining numbers from 3 to n in ascending order
            int current = 3;
            for(int i=2; i<n; ++i){
                perm[i] = current++;
            }
        }
        else{
            // For even n
            // Assign the floor(n/2) largest numbers to even positions in descending order
            int k = n/2;
            // Create a list of numbers from 1 to n
            vector<int> numbers(n);
            for(int i=0; i<n; ++i){
                numbers[i] = i+1;
            }
            // Sort the numbers in descending order
            sort(numbers.begin(), numbers.end(), greater<int>());
            // Select the first k numbers for even positions
            vector<int> even_nums(numbers.begin(), numbers.begin()+k);
            // Sort the even numbers in descending order
            sort(even_nums.begin(), even_nums.end(), greater<int>());
            // Assign to even positions (1-based indexing)
            int even_idx = 1;
            for(auto num: even_nums){
                perm[even_idx] = num;
                even_idx +=2;
            }
            // Assign the remaining numbers to odd positions in ascending order
            vector<int> odd_nums(numbers.begin()+k, numbers.end());
            sort(odd_nums.begin(), odd_nums.end());
            int odd_idx =0;
            for(int i=0; i<n; ++i){
                if((i+1) %2 ==1){
                    perm[i] = odd_nums[odd_idx++];
                }
            }
        }
        // Now compute k
        long long final_k = compute_k(perm);
        // Output
        cout << final_k << "\n";
        for(auto num: perm){
            cout << num << " ";
        }
        cout << "\n";
    }
}
