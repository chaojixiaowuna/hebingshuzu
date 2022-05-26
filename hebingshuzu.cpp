//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。



//思路一 先合并 再冒泡排序
#include<stdio.h>
#define M 3
#define N 3

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i,j;
	int tmp=0;
	for(i=0;i<n;i++)
	{
		nums1[m]=nums2[i];
		m++;
	}
	
	for(i=0;i< nums1Size;i++)
	{
		for(j=0;j< nums1Size-i-1;j++)
		{
			if(nums1[j]>nums1[j+1])
			{
					tmp=nums1[j];
			        nums1[j]=nums1[j+1];
			        nums1[j+1]=tmp;
			}
		}
	}
}
int main()
{
	int i,m=3,n=3;
	int nums1[M+N]={4,5,6,0,0,0};
	int nums2[N]={1,2,3};
	int nums1Size=sizeof(nums1)/sizeof(nums1[0]);
	int nums2Size=sizeof(nums2)/sizeof(nums1[0]);
	merge(nums1,nums1Size,m,nums2,nums2Size,n);
	for(i=0;i<M+N;i++)
	{
		printf("%d ",nums1[i]);
	}
	return 0;
}
//时间复杂度 0（N^2）



//先插入 后qsort排序
#include<stdio.h>
#include<stdlib.h>
#define M 3
#define N 3

int compare(const void* ele1,const void* ele2)
{
	return *((int*)ele1)-*((int*)ele2);
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		nums1[m]=nums2[i];
		m++;
	}
	qsort(nums1,nums1Size,sizeof(int),compare);
}
int main()
{
	int i,m=3,n=3;
	int nums1[M+N]={1,2,3};
	int nums2[N]={2,3,4};
	int nums1Size=sizeof(nums1)/sizeof(nums1[0]);
	int nums2Size=sizeof(nums2)/sizeof(nums1[0]);
	merge(nums1,nums1Size,m,nums2,nums2Size,n);
	for(i=0;i<M+N;i++)
	{
		printf("%d ",nums1[i]);
	}
	return 0;
}


//思路二 归并数组 两个数组比较将大的放在右边
#include<stdio.h>
#define M 3
#define N 3

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int n1=m-1,n2=n-1;
	int dst=nums1Size-1;
	while(n1>=0&&n2>=0)
	{
	if(nums2[n2]>nums1[n1])
	{
		nums1[dst]=nums2[n2];
		dst--;
		n2--;
	}
	else
	{
		nums1[dst]=nums1[n1];
		dst--;
		n1--;
	}
	}
	while(n2>=0)
	{
	nums1[dst]=nums2[n2];
	dst--;
	n2--;
}
	
}
int main()
{
	int i,m=3,n=3;
	int nums1[M+N]={1,2,3};
	int nums2[N]={2,3,4};
	int nums1Size=sizeof(nums1)/sizeof(nums1[0]);
	int nums2Size=sizeof(nums2)/sizeof(nums1[0]);
	merge(nums1,nums1Size,m,nums2,nums2Size,n);
	for(i=0;i<M+N;i++)
	{
		printf("%d ",nums1[i]);
}
	return 0;
}