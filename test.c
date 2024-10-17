#include<stdio.h>

void fun1(int* nums, int length, int target, int* result);

int main()
{
    int length;
    printf("请输入数组的长度: ");
    scanf("%d", &length);

    int nums[length];
    printf("请输入数组的元素: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &nums[i]);
    }

    int target;
    printf("请输入目标值: ");
    scanf("%d", &target);
    int result[2] = {0, 0};

    fun1(nums, length, target, result);

    for (int i = 0; i < 2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

void fun1(int* nums, int length, int target, int* result)
{
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                result[0] = i;
                result[1] = j;
                return;
            }
        }
    }
}