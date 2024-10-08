//折半查找算法
#include "seqlist.cpp"

int BinSearch(RecType R[],int n,KeyType k) //折半查找算法
{	int low=0,high=n-1,mid;
	while (low<=high)			//当前区间存在元素时循环
	{	mid=(low+high)/2;
		if (k==R[mid].key)		//查找成功返回其逻辑序号mid+1
			return mid+1;
		if (k<R[mid].key)		//继续在R[low..mid-1]中查找
			high=mid-1;
		else					//k>R[mid].key
			low=mid+1;			//继续在R[mid+1..high]中查找
	}
	return 0;					//未找到时返回0（查找失败）
}

int BinSearch2(RecType R[],int n,KeyType k)
{	int low=0,high=n-1,mid;
	while (low<=high)			//查找区间有一个或者更多元素时
	{	mid=(low+high)/2;
		if (k<=R[mid].key)
			high=mid-1;		//继续在左区间查找
		else
			low=mid+1;		//继续在右区间查找
	}
	return high+1;
}
int main()
{
	RecType R[MAXL];
	KeyType a[]={1,2,4,4,4,5,6};
	int n=sizeof(a)/sizeof(a[0]);	
	CreateList(R,a,n);
	printf("查找表："); DispList(R,n);
	int k=4;
	printf("第一个大于等于%d的位置=%d\n",k,BinSearch(R,n,k));
	return 1;
}

/* 
int main()
{
	int n=11;
	RecType R[MAXL];
	KeyType a[]={2,3,10,15,20,25,28,29,30,35,40},k=20;
	CreateList(R,a,n);
	printf("查找表："); DispList(R,n);
	printf("R[%d]=%d\n",BinSearch(R,n,k),k);
	return 1;
}
*/
