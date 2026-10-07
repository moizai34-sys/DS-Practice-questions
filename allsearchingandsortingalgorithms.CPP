#include<iostream>
using namespace std;


void interpolationsearch(int arr[],int n, int val){

    int low =0;
    int high =n-1;

    while (arr[low]<=arr[high]&& val>=arr[low]&&val<=arr[high])
    {
        if (low==high)
        {
            if(arr[low]==val)
            {
                cout<<"your element found at pos :" <<low<<endl;
                return;
            }
            else{
                cout<<"Your elememnt is not in the array.."<<endl;
         
               return;
            }
        }
            int pos = low + ((val - arr[low]) * (high - low))/ (arr[high] - arr[low]);
            if (arr[pos]==val)
            {
                 cout<<"your element found at pos :" <<pos+1<<endl;
                return;
            }
            else if(arr[pos]<val)
            {
                low =pos+1;

            }
            else{
                high=pos-1;
            }
            
        }
        
    
    cout<<"Your elememnt is not in the array.."<<endl;
                return;
    
}

void binary_search(int arr[],int n,int key)
{
    int low=0;
    int high = n-1;

    

    while (low<=high)
    {
        int mid=low+(n-1)/2;

        if (arr[mid]==key)
        {
            cout<<"Your element is found at pos: "<<mid+1<<endl;
            return;
        }
        else if(arr[mid]<key)
        {
            low=mid+1;
            
        }
        else{
            high=mid-1;
            
        }
        
        
    }
    cout<<"Element is not in the array.."<<endl;

    
}

void inserionsort(int arr[], int n){

    for (int i=1;i<n;i++)
    {
        int key=arr[i];
        int prev=i-1;

        while(prev>=0&&arr[prev]>key){

            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=key;
    }
}

void dispaly_arr(int arr[],int n){

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
void shell_sort(int arr[],int n){
    
    for (int gap=n/2; gap >0; gap/=2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp=arr[i];
            int j=i;
            while (j>=0&& arr[j-gap]>temp)
            {
                arr[j]=arr[j-gap];
                j=j-gap;
            }

            arr[j]=temp;
            
        }
        
    }
    
}
void comb_sort(int arr[],int n){

    int gap=n;
    bool swapped = true;
    while (gap!=1||swapped)
    {
        gap=gap*10/13;
        if (gap<1)
        {
            gap=1;
        }
        swapped =false;
        for (int i = 0; i+gap <n; i++)
        {
            if (arr[i]>arr[i+gap])
            {
                int temp=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
                swapped =true;
            }
            
        }
        

        
    }
    
}
int main()
{
    int n=5;
    int arr[]={1,4,6,8,2};
    
    dispaly_arr(arr,n);

    shell_sort(arr,n);
    cout<<endl;
    dispaly_arr(arr, n);
    binary_search(arr,n,4);
    cout<<endl;
    interpolationsearch(arr,n,6);
    
}