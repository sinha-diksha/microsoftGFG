long long merge(long long arr[], ll left, ll right){
    ll mid=(left+right)/2;
    ll n=(mid-left)+1;
    ll m=right-mid;
    ll* arr1=new ll[n];
    ll* arr2=new ll[m];
    ll l=0;
    for(ll i=left; i<mid+1; i++){
        arr1[l]=arr[i];
        l++;
    }
    l=0;
    for(ll j=mid+1; j<=right; j++){
        arr2[l]=arr[j];
        l++;
    }

    ll i=0; ll j=0;
    ll* arr3=new ll[n+m];
    ll k=0;
    ll count=0;
    while(i!=n && j!=m){
        if(arr1[i]<=arr2[j]){
            arr3[k]=arr1[i];
            k++;
            i++;
        }
        else{
            arr3[k]=arr2[j];
            j++;
            count+=(n-i);
            k++;
        }
    }
    while(i!=n){
        arr3[k]=arr1[i];
        i++;
        k++;
    }
    while(j!=m){
        arr3[k]=arr2[j];
        j++;
        k++;
    }
    l=0;
    for(ll i=left; i<=right; i++){
        arr[i]=arr3[l];
        l++;
    }

    return count;
}

long long mergeSort(long long arr[], ll left, ll right){
    if(left>=right){
        return 0;
    }
    long long mid=(left+right)/2;
    long long leftInv=mergeSort(arr,left,mid);

    long long rightInv=mergeSort(arr,mid+1, right);

    long long final=merge(arr,left,right);

    return leftInv+rightInv+final;
}
