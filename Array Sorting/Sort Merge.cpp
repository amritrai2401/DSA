//Part of divide and conquer
//You can also find inversion with merge sort. Inversion means :a[i]>a[j] & i<j
//t.c=0(n*logn)              s.c=o(n) because of left[n/2] + right[n/2].

void Merge2SortedArray(int array[],int begin,int n1,int n2,int left[],int right[],int &inversion){
    int i = 0,j = 0, k=begin; 
    
//     For find pairs/inversion such that arr[i]>2*arr[j] with i<j
//     while(i<n1 && j<n2){    
//         if(left[i]/2,=right[j]) i++;
//         else { inversion+=n1-i; j++;}
//     }
    
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) array[k++] = left[i++];
        else {array[k++] = right[j++]; inversion+=n1-i;}  //Normal Inversion : arr[i]>arr[j] with i<j
    }
    while (i < n1)array[k++] = left[i++];
    while (j < n2)array[k++] = right[j++];
}
  

void sort(int array[], int begin, int end,int left[],int right[],int &inversion){
    if (begin >= end)return;
    int mid = begin + (end - begin) / 2;
    sort(array, begin, mid,left,right,inversion);
    sort(array, mid + 1, end,left,right,inversion);
    int n1=mid-begin+1, n2=end-mid;
    for(int i=0;i<n1;i++)left[i] = array[begin+i];
    for(int i=0;i<n2;i++)right[i]= array[mid+1+i];
    Merge2SortedArray(array,begin,n1,n2,left,right,inversion);
}

void mergeSort(int array[],int size){
    int left[(size+1)/2],right[(size+1)/2],inversion=0;
    sort(array,0,size-1,left,right,inversion);
}
