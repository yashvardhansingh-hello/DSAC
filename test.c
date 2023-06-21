#include<stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int j = numsSize-1;
    int i = 0;
    while(i != j){
        if(nums[i]==val){
            if(nums[i]==val && nums[j]==val) {
                j--;
                continue;
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            j--;
        }
        i++;
    }
    return i;
}
int main(){
    int arr[4] = {3,2,2,3};
       
    return 0;
}