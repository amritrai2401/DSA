int maxSum(int arr[], int n, int k){
    int res = 0;
    for (int i=0; i<k; i++)res += arr[i];
    int curr_sum = res;    
    for (int i=k; i<n; i++){
       curr_sum += arr[i] - arr[i-k];
       res = max(res, curr_sum);
    } 
    return res;
}

//First negative in every window        Anagram 
