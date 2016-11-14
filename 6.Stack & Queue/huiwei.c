#include <stdio.h>
#include <string.h>  
#include <stdlib.h>  
  
int main()  
{  
    char str[100], s[100];  
    int i, len, mid, top;  
  
    gets(str);  
    len = strlen(str);  
    mid = len/2 - 1;     /// 字符串的中点  
  
    top = -1;            /// 栈初始化  
    for (i = 0; i <= mid; ++i)  
    {  
        s[++top] = str[i];  
    }  
  
    if(len % 2)          /// 判断字符串长度是偶数还是奇数  
    {  
        mid += 2;  
    }  
    else  
    {  
        mid++;  
    }  
  
    for (i = mid; i < len; ++i)  
    {  
        if (str[i] != s[top])  
        {  
            break;  
        }  
        top--;  
    }  
  
    printf("%s\n", top == -1? "Yes": "No");  
    return 0;  
}