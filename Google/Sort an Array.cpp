class Solution {
public:
    void merge(vector<int>& a, int low, int mid, int high) {
        vector<int> sorted(high - low + 1);
        int i = low;     
        int j = mid + 1;  
        int k = 0;      
        while (i <= mid && j <= high)
        {
          if (a[i] < a[j])
            sorted[k++] = a[i++];
          else
            sorted[k++] = a[j++];
        }

        while (i <= mid)
          sorted[k++] = a[i++];

        while (j <= high)
          sorted[k++] = a[j++];

        copy(begin(sorted), end(sorted), begin(a) + low);
    }
      
    void mergeSort(vector<int> &a,int low,int high)    
    {
        if(low >= high)
            return;
            
        int mid = low + (high - low)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
        
    }  
    
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums;
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};
