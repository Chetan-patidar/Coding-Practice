int findUnique(int *arr, int size)
{
    //Write your code here
    int sum = 0;
    for(int i=0;i<size;i++){
        sum = sum ^ arr[i];
    }
    return sum;
}
