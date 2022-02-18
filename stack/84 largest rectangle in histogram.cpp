#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
typedef long long int lli;

//     class pair{
//         int first;
//         int second;
        
//         pair(int first, int second){
//             this->first = first;
//             this->second = second;
//         }
//     };
    // NSR Index
    vector<int> nsr_index(vector<int>& arr){
        vector<int> ans;
        stack<pair<int,int> > st;
        
        for(int i = arr.size() - 1; i >= 0; i--){
            if(st.empty()){
                ans.push_back(arr.size()+1);
            }
            else if(st.size() > 0 && arr[i] > st.top().first){
                ans.push_back(st.top().second-1);
            }
            else{
                while(st.size() > 0 && arr[i] <= st.top().first){
                    st.pop();
                }
                if(!st.empty()){
                    ans.push_back(st.top().second-1);
                }
                else{
                    ans.push_back(arr.size()+1);
                }
            }
            st.push({arr[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    // NSL Index
    vector<int> nsl_index(vector<int>& arr){
        vector<int> ans;
        stack<pair<int,int> > st;
        
        for(int i = 0; i < arr.size(); i++){
            if(st.empty()){
                ans.push_back(-1);
            }
            else if(st.size() > 0 && arr[i] > st.top().first){
                ans.push_back(st.top().second);
            }
            else{
                while(st.size() > 0 && arr[i] <= st.top().first){
                    st.pop();
                }
                if(!st.empty()){
                    ans.push_back(st.top().second);
                }
                else{
                    ans.push_back(-1);
                }
            }
            st.push({arr[i], i});
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0){
            return 0;
        }
        if(heights.size() == 1){
            return heights[0];
        }
        if(heights.size() == 2){
            if(min(heights[0], heights[1]) != 0){
                return min(heights[0], heights[1]) *2;
            }
            else{
                return max(heights[0], heights[1]);
            }
        }
        vector<int> right = nsr_index(heights);
        vector<int> left = nsl_index(heights);
        // for(auto x: right){
        //     cout << x << ", ";
        // }
        // cout << endl;
        // for(auto x: left){
        //     cout << x << ", ";
        // }
        vector<int> width(heights.size());
        for(int i = 0; i < heights.size(); i++){
            width[i] = right[i] - left[i] - 1;
        }
        
        int ans = INT_MIN;
        for(int i = 0; i < heights.size(); i++){
            ans = max(ans, heights[i] * width[i]);
        }
        return ans;
    }

	void solve()
	{
		int n;
		cin >> n;
	    vector<int>ar(n);
	    
	    for(auto &x: ar){
	    	cin >> x;
	    }
	    cout << largestRectangleArea(ar);
	    cout << '\n';
	}

	int main()
	{
	    fast;
	#ifdef Ankit
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
	    // int t;
	    // cin >> t;
	    // while (t--)
	    // {
	        solve();
	    // }

	    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";

	    return 0;
	}