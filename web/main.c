#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*横向方法*/
//char* longestCommonPrefix(char** strs, int strsSize)
//{
//	if (1 == strsSize)
//	{
//		return *strs;
//	}
//	else
//	{
//		int len = strlen(strs[0]);
//		int len_max = strlen(strs[0]);
//		char* com = (char*)malloc(sizeof(char)*(len + 1));
//		
//		strcpy(com, strs[0]);
//
//		int n = 1;
//		
//
//		for (int i = 0; i < strsSize; i++)
//		{
//			if (strlen(strs[i]) < len)
//			{
//				len = strlen(strs[i]);   //min
//			}
//			if (strlen(strs[i]) > len_max)
//			{
//				len_max = strlen(strs[i]);  //max
//			}
//		}
//		com[len] = '\0';
//		char* next = (char*)malloc(sizeof(char) * (len_max + 1));
//		while (n < strsSize)
//		{
//			strcpy(next, strs[n]);
//			for (int t = 0; t < len; t++)
//			{
//				if (com[t] != next[t])
//				{
//					com[t] = '\0';
//					len = t;
//					break;
//				}
//			}
//			n++;
//		}
//		return com;
//	}
//
//}

/*横向方法*/
char* longestCommonPrefix(char** strs, int strsSize) {
	int t, i, j, num = 0;
	char string;
	t = strlen(strs[0]);
	for (i = 1; i < strsSize; i++)
		if (t > strlen(strs[i]))   t = strlen(strs[i]);
	for (j = 0; j < t; j++)
	{
		string = strs[0][j];
		for (i = 1; i < strsSize; i++)
			if (strs[i][j] != string) { j = -1; break; }
		if (j == -1)   break;
		num++;
	}
	char* st = (char*)malloc(sizeof(char) * (num + 1));
	if (st != NULL)
	{
		for (i = 0; i < num; i++)
			st[i] = strs[0][i];
		st[i] = '\0';
		return st;
	}
}

int main()
{
	//char * string[3] = { "lizhi", "lijun", "lidu" };
	char* string[3] = { "flower","flow","flight" };
	char *ret = longestCommonPrefix(string, 3);
	return 0;
}

#endif


/*
*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
*有效字符串需满足：
*左括号必须用相同类型的右括号闭合。
*左括号必须以正确的顺序闭合。
注：栈*/
#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//bool isValid(char* s)
//{
//	int len = strlen(s);
//	typedef struct stack
//	{
//		int top;    /*栈顶元素的index*/
//		char *character;
//	}Stack;
//
//	int rets = false;
//	Stack kuohao ;
//	kuohao.top = -1;
//	kuohao.character = (char*)malloc(sizeof(char) * (len + 1));
//	
//	if (0 == len)
//	{
//		return rets = true;
//	}
//	else
//	{
//
//		for (int i = 0; i < len; i++)
//		{
//			if (*(s + i) == '(' || *(s + i) == '{' || *(s + i) == '[')
//			{
//				kuohao.top++;
//				kuohao.character[kuohao.top] = *(s + i);
//			}
//			else if(kuohao.top >= 0)
//			{
//				switch (*(s + i))
//				{
//				case ')':
//					if (kuohao.character[kuohao.top] == '(')
//					{
//						kuohao.top--;
//						break;
//					}
//					else
//					{
//						return rets = false;
//					}
//
//				case '}':
//					if (kuohao.character[kuohao.top] == '{')
//					{
//						kuohao.top--;
//						break;
//					}
//					else
//					{
//						return rets = false;
//					}
//
//				case ']':
//					if (kuohao.character[kuohao.top] == '[')
//					{
//						kuohao.top--;
//						break;
//					}
//					else
//					{
//						return rets = false;
//					}
//
//				default:
//					break;
//				}
//
//
//
//			}
//			else
//			{
//				return rets = false;
//			}
//		}
//	}
//	if (kuohao.top == -1)
//	{
//		return rets = true;
//	}
//	else
//	{
//		return rets = false;
//	}
//	
//
//
//
//}

char pairs(char a) {
	if (a == '}') return '{';
	if (a == ']') return '[';
	if (a == ')') return '(';
	return 0;
}

bool isValid(char* s) {
	int n = strlen(s);
	if (n % 2 == 1) {
		return false;
	}
	int* stk = (int*)malloc(sizeof(int) * (n + 1));
	int top = 0;
	for (int i = 0; i < n; i++) {
		char ch = pairs(s[i]);
		if (ch) 
		{
			if (top == 0 || stk[top - 1] != ch) 
			{
				return false;
			}
			top--;
		}
		else 
		{
			stk[top++] = s[i];
		}
	}
	return top == 0;
}


int main()
{
	char* str = "(()]";
		//"[({])}";
		//;
	
	bool ret = isValid(str);
	printf("%d\n", ret);
	return 0;

}
#endif

/*将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。*/
#if 0

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

 /* Definition for singly-linked list.*/
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 


//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) 
//{
//	struct ListNode* ret = (struct ListNode*)malloc(sizeof(struct ListNode));
//	struct ListNode* node = ret;
//	int flag = 0;
//	struct ListNode* ls1 = list1;
//	struct ListNode* ls2 = list2;
//	if (ls1 == NULL && list2 == NULL)
//		return NULL;
//	else if(ls1 == NULL)
//		return ls2;
//	else if (ls2 == NULL)
//		return ls1;
//	else
//	{
//		while (ls1 != NULL && ls2 != NULL)
//		{
//			if (0 == flag)
//			{
//				flag = 1;
//				if (ls1->val < ls2->val)
//				{
//					ret->val = ls1 ->val;
//					ret->next = NULL;
//					ls1 = ls1->next;
//				}
//				else
//				{
//					ret->val = ls2->val;
//					ret->next = NULL;
//					ls2 = ls2->next;
//				}
//
//			}
//			else
//			{
//				if (ls1->val < ls2->val)
//				{
//					node->next = ls1;
//					node = ls1;
//					ls1 = ls1->next;
//				}
//				else
//				{
//					node->next = ls2;
//					node = ls2;
//					ls2 = ls2->next;
//				}
//
//			}
//		
//		}
//		if (ls1 != NULL)
//		{
//			node->next = ls1;
//		}
//		else
//		{
//			node->next = ls2;
//		}
//
//		return ret;
//	}
//
//}


 struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
 {
	 struct ListNode* first = (struct ListNode*)malloc(sizeof(struct ListNode));  /*首元结点*/
	 struct ListNode* tempt = first;
	 struct ListNode* tempt1 = list1;
	 struct ListNode* tempt2 = list2;
	 if (tempt1 == NULL && tempt2 == NULL)
		return NULL;
	 else if(tempt1 == NULL)
		return tempt2;
	else if (tempt2 == NULL)
		return tempt1;
	else
	 {
		 while (tempt1 != NULL && tempt2 != NULL)
		 {
			 if (tempt1->val < tempt2->val)
			 {
				 tempt->next = tempt1;
				 tempt = tempt1;
				 tempt1 = tempt1->next;
			 }
			 else
			 {
				 tempt->next = tempt2;
				 tempt = tempt2;
				 tempt2 = tempt2->next;
			 }
		 }
		 if (tempt1 == NULL)
		 {
			 tempt->next = tempt2;
		 }
		 else
		 {
			 tempt->next = tempt1;
		 }
		 return first->next;
	 }
 }
struct ListNode* init_link1()
{
	
	struct ListNode* first = (struct ListNode*)malloc(sizeof(struct ListNode));  /*首元结点*/
	if (first != NULL)
	{
		first->val = 1;
		first->next = NULL;
		struct ListNode* node = first;   /*头指针，作为一个中间变量*/
		for (int i = 4; i < 7; i++)
		{
			struct ListNode* ua = (struct ListNode*)malloc(sizeof(struct ListNode));
			ua->val = i;
			ua->next = NULL;
			node->next = ua;
			node = ua;

		}
	}
	return first;
}

struct ListNode* init_link2()
{

	struct ListNode* first = (struct ListNode*)malloc(sizeof(struct ListNode));  /*首元结点*/
	if (first != NULL)
	{
		first->val = 2;
		first->next = NULL;
		struct ListNode* node = first;   /*头指针，作为一个中间变量*/
		for (int i = 6; i < 9; i++)
		{
			struct ListNode* ua = (struct ListNode*)malloc(sizeof(struct ListNode));
			ua->val = i;
			ua->next = NULL;
			node->next = ua;
			node = ua;

		}
	}
	return first;
}

int main()
{
	struct ListNode* link1 = init_link1();  /*1，4，5，6*/
	struct ListNode* link2 = init_link2();  /*2，6，7，8*/

	struct ListNode* link = mergeTwoLists(link1, link2);  /*1, 2, 4, 5，6, 6，7，8*/
	return 0;
}

#endif


/*给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，
返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。
更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。

不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
#if 0
#include<stdio.h>
#include<stdlib.h>

//int swap_arr(int* num1, int numsSize)
//{
//	int tempt = num1[0];
//	static int size = 0;
//	int flag = 0;
//
//	for (int t = 0; t < numsSize - 1 - size; t++)
//	{
//		if (num1[t + 1] == num1[t])
//		{
//			flag++;
//		}
//		else
//		{
//			break;
//		}
//	
//	}
//
//
//	for (int i = 0; i < numsSize - 1 - size -flag; i++)
//	{
//
//		num1[i] = num1[i + 1+ flag];
//	}
//
//	size = size + 1 +flag;
//
//	return flag;
//}
//
//int removeDuplicates(int* nums, int numsSize) 
//{
//	int val ;
//	int n = 0;
//	int size = numsSize;
//	int num_size = 0;
//	while (n < size)
//	{
//		val = nums[n];
//		for (int i = n + 1; i < size; i++)
//		{
//			if (nums[i] == val)
//			{
//				num_size = swap_arr(&nums[i], numsSize - i);
//				size = size - 1 - num_size;
//			}
//		}
//		n++;
//	}
//	for (int n = size; n < numsSize; n++)
//	{
//		nums[n] = 0;
//	}
//	
//	return size;
//}

int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize <= 1)
	{
		return numsSize;
	}
	else
	{
		int i = 1, j = 0;
		for (i; i < numsSize; i++)  /*i是一个快指针，表示遍历数组中的所有元素，和前一个比较找到不同的一个*/
		{
			if (nums[i] != nums[i - 1])
			{
				nums[++j] = nums[i];	/*j是一个慢指针，只存放不同元素*/
			}
		}
		return j + 1;
	}

}

int main()
{
	//int num[] = { 1,2,8,1,6,5,4,2,5,6,9,1 };   /*输出：1，2，8，6，5，4，9*/
	int num[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };   /*0,1,2,3,4*/
	int n = removeDuplicates(num,10);
	return 0;
}


#endif


/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/

#if 0
#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) 
{
	int i = 0, j = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			nums[j++] = nums[i];  
		}
	}
	return j ;
}

int main()
{
	int num[] = { 0, 3, 1, 1, 9, 2, 7, 3, 3, 4 };   /*0,1,1,9,2,7,4*/
	int ret = removeElement(num, 10, 3);
	for (int i = 0; i < ret; i++)
	{
		printf("%d\t", num[i]);
	}
	return 0;
}


#endif


/*实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置
（下标从 0 开始）。如果不存在，则返回  -1 。

*/

#if 0

#include<stdio.h>
#include<string.h>

int strStr(char* haystack, char* needle) 
{
	int len1 = strlen(haystack);
	int len2 = strlen(needle);
	if (len1 < len2)
	{
		return -1;
	}
	else if (len1 == 0 || len2 == 0)
	{
		return 0;
	}
	else
	{
		int j;
		for (int i = 0; i < len1; i++)
		{
//			if (haystack[i] == needle[0])
//			{
				for (j = 0; j < len2; j++)
				{
					if (haystack[i + j] != needle[j])
					{
						break;
					}

				}
				if (j == len2 )
				{
					return i;
				}
				
//			}
		}
		return -1;
		
	}

}


int main()
{
	char haystack[] = "mississippi";
	char needle[] = "issip";
	int index = strStr(haystack, needle);
	return 0;
}


#endif

/*给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，
返回它将会被按顺序插入的位置。
nums 为无重复元素的升序排列数组
请必须使用时间复杂度为 O(log n) 的算法。

分析：
由于要求使用O(logn)的算法
故考虑使用二分查找
*/

#if 0

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//int searchInsert(int* nums, int numsSize, int target) 
//{
//	int low = 0, high = numsSize - 1, midle = 0;
//	if (nums[high] < target)
//	{
//		return numsSize;
//	}
//	else
//	{
//		while (high >= low)
//		{
//			midle = low + (high - low) / 2;
//			if (nums[midle] > target)
//			{
//				high = midle - 1;
//			}
//			else if (nums[midle] < target)
//			{
//				low = midle + 1;
//			}
//			else
//			{
//				return midle;
//			}
//		}
//		if (nums[midle] < target)
//		{
//			return midle + 1;
//		}
//		else 
//		{
//			return midle ;
//		}
//	}
//	
//}


int searchInsert(int* nums, int numsSize, int target) 
{
	int n = numsSize;
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] < target)
			l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int main()
{
	int nums[] = { 1, 3, 4, 6 };
	int target = 0;
	int ret = searchInsert(nums, 4, target); 
	unsigned long long aa = 12345678912345678912U;
	printf("%llu\n", aa);
	printf("int:%d\n", sizeof(int));
	printf("short int:%d\n", sizeof(short));
	printf("long int:%d\n", sizeof(long));
	printf("long long int:%d\n", sizeof(unsigned long long));

	return 0;
}

#endif

/*给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
返回其最大和。

子数组 是数组中的一个连续部分。*/
/*解题思路：动态规划问题（无后效性）——状态转移
把一个问题分成n个子问题，联系子问题间的联系。
array[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
子问题1：以-2为结尾的连续子数组的最大和是多少；
子问题2：以1为结尾的连续子数组的最大和是多少；
子问题3：以-3为结尾的连续子数组的最大和是多少；
子问题4：以4为结尾的连续子数组的最大和是多少；
子问题5：以-1为结尾的连续子数组的最大和是多少；
子问题6：以2为结尾的连续子数组的最大和是多少；
子问题7：以1为结尾的连续子数组的最大和是多少；
子问题8：以-5为结尾的连续子数组的最大和是多少；
子问题9：以4为结尾的连续子数组的最大和是多少；
结果一：以问题4为例：以4为结尾的连续子数组的最大和是max(以-3为结尾的连续子数组的最大和加上4，,4)；
结果二：如果index为i-1的数最大和为负数，那么index为i的数最大和为他本身（即将前面数抛弃），
	    如果index为i-1的数最大和为正数，那么index为i的数最大和为他本身 + index为i-1的数最大和
然后对比9个问题中最大和。
*/

#if 0
#include<stdio.h>
#include<stdlib.h>

//int max(int a, int b)
//{
//	if (a > b)
//	{
//		return a;
//	}
//	else
//	{
//		return b;
//	}
//}
#define MAX(a,b)     (((a) > (b)) ? (a) : (b))

int maxSubArray(int* nums, int numsSize)
{
	int* max_i = (int*)malloc(sizeof(int) * numsSize);
	int ret = nums[0];
	max_i[0] = nums[0];
	for (int i = 1; i < numsSize; i++)
	{
		/*max_i[i] = MAX(max_i[i - 1] + nums[i], nums[i]);*/
		if (max_i[i - 1] < 0)
		{
			max_i[i] = nums[i];
		}
		else
		{
			max_i[i] = max_i[i - 1] + nums[i];
		}
		
	}
	for (int i = 1; i < numsSize; i++)
	{
		if (ret < max_i[i])
		{
			ret = max_i[i];
		}
	}
	return ret;
}

int main()
{
	int array[] = {-2,1,-3,4,-1,2,1,-5,4};
	int ret = maxSubArray(array, 9);
	return 0;

}

#endif


/*给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 
最后一个 单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

*/

#if 0
#include<stdio.h>
#include<string.h>


int lengthOfLastWord(char* s) 
{
	int ret = 0, i = 0 , n = 0;
	int space = 0;
	if (s != NULL)
	{
		for (i = 0; *(s + i) != '\0'; i++)
		{
			if (*(s + i) == ' ')
			{
				space++;
			}
		}

		if (space != 0)
		{
			for (n = i - 1; n > 0 && *(s + n) == ' '; n--)
			{
				;
			}

			for (n; n >= 0 && *(s + n) != ' '; n--)
			{
				ret++;
			}
			return ret;
		}
		else
		{
			return ret = i;

		}
	}
	else
	{
		return ret = 0;
	}
}

int main()
{
	char arr[] = "a ";
	int n = lengthOfLastWord(arr);
	return 0;
}

#endif

/*给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
*/


#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX    4
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) 
{	
	for (int i = digitsSize - 1; i >= 0; i--)
	{
		if (digits[i] != 9)
		{
			digits[i] = digits[i] + 1;
			for (int j = digitsSize - 1; j > i; j--)
			{
				digits[j] = 0;
			}
			*returnSize = digitsSize;
			return digits;
		}
	}

	*returnSize = digitsSize + 1;
	int* nums = (int*)malloc(sizeof(int) * (digitsSize + 1 ));
	if (nums != NULL)
	{
		memset(nums, 0, sizeof(int) * (digitsSize + 1));
		nums[0] = 1 ;
		return nums;
	}
	
}


int main()
{
	int digits[MAX] = {6, 9, 9, 9};
	int returnSize ;

	int* digit1 = plusOne(digits, MAX, &returnSize);
	for (int i = 0; i < returnSize; i++)
	{
		printf("%d\n", digit1[i]);
	}
	return 0;
}


#endif

/*给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。*/
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char result(char m, char n,char *k)
{
	char ret;
	if (m == '1' && n == '1'&& *k == '1')
	{
		ret = '1';
		*k = '1';
	}
	else if ((m == '1' && n == '1') || (n == '1' && *k == '1') || (m == '1' && *k == '1'))
	{
		ret = '0';
		*k = '1';
	}
	else if(m == '1' || n == '1' || *k == '1')
	{
		ret = '1';
		*k = '0';
	}
	else
	{
		ret = '0';
		*k = '0';
	}
	return ret;
}

char* addBinary(char* a, char* b) 
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	int len_max = 0;
	int len_min = 0;
	int flag = -1;    /*3:进位；0：相等不进位；1:len1大；2:len2大*/
	if (len1 == len2)
	{
		if (a[0] == '1' && b[0] == '1')
		{
			len_max = len1 + 1;
			flag = 3;
		}
		else
		{
			len_max = len1;
			flag = 0;
		}
		len_min = len1;
	}
	else
	{
		if (len1 > len2)
		{
			flag = 1;
			if ((len1 == len2 + 1) && a[1] == '1' && b[0] == '1')
			{
				len_max = len1 + 1;
				
			}
			else 
			{
				len_max = len1;
				len_min = len2;
				
			}
			
		}
		else
		{
			flag = 2;
			if ((len2 == len1 + 1) && a[0] == '1' && b[1] == '1')
			{
				len_max = len2 + 1;
			
			}
			else
			{
				len_max = len2;
				len_min = len1;
				
			}
			
		}
	}
	char* arr = (char*)malloc(sizeof(char)*(len_max + 1));
	char num = '0';
	int i = 0;
	if (arr != NULL)
	{
		arr[len_max] = '\0';
		for (i = len_max - 1; i >= 0 && len1 > 0 && len2 > 0; i--)
		{
			arr[i] = result(a[--len1], b[--len2], &num);
		}
	
	}

	if (flag == 1)
	{
		for (int j = i; j >= 0 && len1 > 0; j--)
		{
			arr[j] = result(a[--len1], '0', &num);
		}
	
	}
	else if(flag == 2)
	{
		for (int j = i; j >= 0&&len2 > 0; j--)
		{
			arr[j] = result('0', b[--len2], &num);
		}

	}
	else
	{
		;
	}
	if (num == '1')
	{
		arr[0] = '1';
	}

	
	return arr;

}

int main()
{
	char a[] = "1";

	char b[] = "111";   //out:10101
	char* c = addBinary(a, b);
	printf("%s\n", c);
	return 0;
}


#endif


/*给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
*/
#if 0
#include<stdio.h>
#include<string.h>
#include<math.h>

/*二分查找法*/
int mySqrt(int x) 
{
	unsigned int low = 0;
	unsigned int high = x;
	int tempt = log2(x);
	unsigned int ret = 1;
	//for (int i = 0; i < tempt / 2 + 1; i++)
	//{
	//	ret *= 2;
	//}

	// high = ret;

	unsigned int mid = 0;
	long long mux = 0;

	while (high >= low)
	{
		mid = (low + high) / 2;
		mux = mid * mid;
		if (x == mux)
		{
			return mid;
		}
		else if (x > mux)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return high;
	
}

int main()
{
	int num = 320865;

	/*printf("please input a int number:\n");
	scanf(" %d", &num);*/

	int sqrt_n = mySqrt(num);

	printf("the sqrt of %d is %d\n", num, sqrt_n);

	return 0;
}


#endif


/*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

找规律可知n 阶的方法等于n-1 阶 + n-2 阶方法
*/
#if 0
#include<stdio.h>

/*递归*/
#if 0
int climbStairs(int n) 
{
	int way = 0;
	if (n == 1)
	{
		way = 1;
		return way;
	}
	else if(n == 2)
	{
		way = 2;
		return way;
	}
	else
	{
		int last1 = climbStairs(n - 1);
		int last2 = climbStairs(n - 2);

		return last1 + last2;
	
	}


}
#endif

/*滚动数组*/
int climbStairs(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{

		return 2;
	}
	else
	{
		int last1 = 2;   //前一个
		int last2 = 1;   //前2个
		int num = 0;
		int way = 0;

		while (num < n - 2)
		{
			way = last1 + last2;
			last2 = last1;
			last1 = way;
			
			num++;
		}
		return way;
			
	}

}
int climbStairs1(int n)
{
	int last1 = 2;   //前一个
	int last2 = 1;   //前2个
	int way = 0;
	for (int i = 3; i < n + 1; i++)
	{
		way = last1 + last2;
		last2 = last1;
		last1 = way;
	}
	return way;
}

int main()
{
	int n = 6;
	int num = climbStairs1(n);
	printf("%d\n", num);

	return 0;
}

#endif


/*给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。*/
#if 0
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct ListNode {
	int data;
	struct ListNode* next;
};

struct ListNode* Init_link(int * arr,int size)
{
	struct ListNode* first = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* tempt = NULL;
	if (first != NULL)
	{
		first->data = arr[0];
		first->next = NULL;
		tempt = first;
	}

	
	for (int i = 1; i < size; i++)
	{
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		if (node != NULL)
		{
			node->data = arr[i];
			node->next = NULL;
			tempt->next = node;
			tempt = node;
		}
		
	
	}
	return first;


}

/*无序*/
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
	struct ListNode* tempt = head;
	while (tempt != NULL)
	{
		struct ListNode* node = tempt;

		for (node; node->next != NULL; node = node->next)
		{
			
			if (tempt->data == node->next->data)
			{
				struct ListNode* t1 = node->next->next;
				for (t1; t1 != NULL; t1 = t1->next)
				{
					if (tempt->data != t1->data)
					{
						break;
					}
				}
				node->next = t1;
				if (node->next == NULL)
				{
					break;
				}
			
			}
		
		}
	
		tempt = tempt->next;
	}

	return head;
}

/*有序*/
struct ListNode* deleteDuplicates1(struct ListNode* head)
{
	struct ListNode* node = head;
	while (node->next != NULL)
	{
		if (node->data == node->next->data)
		{
			node->next = node->next->next;
		}
		else
		{
			node= node->next;
		}

	}

}
int main()
{
	struct ListNode* node = NULL;
	struct ListNode* ret = NULL;
	int num[7] = { 1,1,1,1,2,3,3};
	node = Init_link(num, 8);
	ret = deleteDuplicates1(node);
	return 0;
}

#endif

/*给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n,
其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

*/
#if 0
#include<stdio.h>
#include<stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) 
{
	int i = 0;
	int pointer1 = 0;
	int pointer2 = 0;
	if (nums2 == NULL)
	{
		return;
	}
	else if (m == 0)
	{
		for (i = 0; i < nums1Size; i++)
		{
			nums1[i] = nums2[i];
		}
	}
	else
	{
		int* num = (int*)malloc(sizeof(int) * nums1Size);
		if (num != NULL)
		{
			for (i = 0; pointer1 < m && pointer2 < n; i++)
			{
				if (nums1[pointer1] > nums2[pointer2])
				{
					num[i] = nums2[pointer2];
					pointer2++;
				}
				else
				{
					num[i] = nums1[pointer1];
					pointer1++;
				}
			}
			if (pointer1 >= m)
			{
				for (int j = i; j < nums1Size; j++)
				{
					num[j] = nums2[pointer2++];
				}
			}
			else
			{
				for (int j = i; j < nums1Size; j++)
				{
					num[j] = nums1[pointer1++];
				}
			}

		}
		for (int i = 0; i < nums1Size; i++)
		{
			nums1[i] = num[i];

		}


	}

}


int main()
{
	int m = 1;
	int n = 0;
	int nums1[2] = { 1,0 };
	int *nums2 = NULL;

	merge(nums1, 6, m, nums2, 3, n);
	
	return 0;
}

#endif

/*给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。*/
#if 0
#include<stdio.h>
#include<stdlib.h>

  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };


void Traversal_bef(struct TreeNode* root) 
{
	if (root != NULL)
	{
		printf("%d\n", root->val);
		Traversal_bef(root->left);
		Traversal_bef(root->right);
	}

}

void Traversal_mid(struct TreeNode* root)
{
	if (root != NULL)
	{
		Traversal_mid(root->left);
		printf("%d\n", root->val);
		Traversal_mid(root->right);
	}

}

void Traversal_aft(struct TreeNode* root)
{
	if (root != NULL)
	{
		Traversal_aft(root->left);
		Traversal_aft(root->right);
		printf("%d\n", root->val);
	}

}

void inorderT(struct TreeNode* root,int * arr)
{
	static int tempt = 0;
	if (root != NULL)
	{
		inorderT(root->left, arr);
		arr[tempt++] = root->val;
		inorderT(root->right, arr);
	}
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	int size = 0;
	size = *returnSize;
	int* ret = (int*)malloc(sizeof(int) * (size));
	inorderT(root, ret);

	return ret;

}

struct TreeNode* creat_tree()
{
	struct TreeNode* tree;
	int data = 0;
	printf("请输入数据:\n");
	scanf("%d", &data);

	if (data == 0)     
	{
		tree = NULL;
	}
	else
	{
		tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		tree->val = data;
		tree->left = creat_tree();
		tree->right = creat_tree();
	}
	return tree;
}


int main()
{
	 struct TreeNode* root = creat_tree();

	printf("中序遍历：\n");
	Traversal_mid(root);
	int size = 3;
	int*ret = inorderTraversal(root, &size);
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", ret[i]);
	}
	return 0;
}


#endif

/*给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。*/
#if 0

#include <stdio.h>
#include <stdlib.h>

int ** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
	*returnSize = numRows;    //二维数组的行
	int** arr = (int**)malloc(sizeof(int*) * numRows);   //行
	*returnColumnSizes = (int*)malloc(sizeof(int) * numRows);

	if (numRows == 0)
	{
		;
	}
	else if (numRows == 1)
	{
		arr[0] = (int*)malloc(sizeof(int));
		arr[0][0] = 1;
	}
	else
	{
		arr[0] = (int*)malloc(sizeof(int));
		arr[1] = (int*)malloc(sizeof(int) * 2);
		arr[0][0] = 1;
		arr[1][0] = 1;
		arr[1][1] = 1;

		for (int i = 2; i < numRows; i++)
		{
			arr[i] = (int*)malloc(sizeof(int) * i);
			arr[i][0] = 1;
			arr[i][i] = 1;
			for (int j = 1; j < i; j++)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	
	return arr;

}

int main()
{
	int n = 5,b,c;
	int **a = generate(n,&b,&c);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			printf("%d\t", a[i][j]);
	
	}

	return 0;
}


#endif