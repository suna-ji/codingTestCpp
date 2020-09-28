// 이진 탐색 -> 절반씩 줄여가며
// 시간복잡도 O(log n)
int search(int *arr, int length, int target){
    int start = 0;
    int end = length - 1;
    int mid = 0;
    while(start <= end){
        mid = (start + end) / 2;
        if(arr[mid] == target)
            return mid;
        else{
            if(arr[mid] < target){
                start = mid + 1;
            }else{
                end = mid -1;
            }
        }
    }
    return -1;
}