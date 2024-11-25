#include<stdio.h>
#include<string.h>

#define MaxLen 100
typedef struct
{
    char str[MaxLen];
    int curlen;
}SString;

// 赋值
void StrAssign(SString *S, char chars[])
{
    for (int i = 0; i < strlen(chars); i++)
    {
        S->str[i] = chars[i];
    }
    S->curlen = strlen(chars);
    S->str[S->curlen] = '\0';
}

// 复制
void StrCopy(SString *S, SString *T)
{
    for (int i = 0; i < T->curlen; i++)
    {
        S->str[i] = T->str[i];
    }
    S->curlen = T->curlen;
    S->str[S->curlen] = '\0';
}

// 比较
int StrEqual(SString *S, SString *T) {
    if(S->curlen != T->curlen) return 0;

    for (int i = 0; i < S->curlen; i++) {
        if(S->str[i] != T->str[i]) return 0;
    }
    return 1;
}

// 长度
int Length(SString *S)
{
    return S->curlen;
}

// 链接
void StrCat(SString *CH, SString *S, SString *T)
{
    int i;
    CH->curlen = S->curlen + T->curlen;
    for (i = 0; i < S->curlen; i++)
    {
        CH->str[i] = S->str[i];
    }

    for (i = 0; i < T->curlen; i++)
    {
        CH->str[S->curlen + i] = T->str[i];
    }
    CH->str[CH->curlen] = '\0';
}

// 求子串
void SubString(SString *Sub, SString *S, int pos, int len)
{
    int i, j = 0;
    if((pos >= 1 && pos <= S->curlen) && (len > 0 && len <= S->curlen - pos + 1))
    {
        for (i = pos - 1; i < len + pos - 1; i++)
        {
            Sub->str[j++] = S->str[i];
        }
        Sub->curlen = len;
        Sub->str[Sub->curlen] = '\0';
    }
    else
    {
        printf("\nerror!\n");
    }
}

// 判断串空
int Empty(SString *S)
{
    return (S->curlen == 0);
}

// 插入
int StrInsert(SString *S, int pos, SString *T)
{
    int i, k;
    if(pos < 1 || pos > S->curlen + 1)
    {
        return 0;
    }
    if(S->curlen + T->curlen <= MaxLen)
    {
        for (i = S->curlen - 1; i >= pos - 1; i--)
        {
            S->str[i + T->curlen] = S->str[i];
        }
        for (i = pos - 1, k = 0; i < pos + T->curlen - 1; i++, k++)
        {
            S->str[i] = T->str[k];
        }
        S->curlen = S->curlen + T->curlen;
        S->str[S->curlen] = '\0';
        return 1;
    }
    else
    {
        for(i = MaxLen - 1; i >= pos; i--)
        {
            S->str[i] = S->str[i - T->curlen];
        }
        for(i = pos - 1; i < pos - 1 + T->curlen; i++)
        {
            S->str[i] = T->str[i - pos + 1];
        }
        S->curlen = MaxLen;
        S->str[S->curlen] = '\0';
        return 0;
    }
}

// 删除
int Delete(SString *S, int pos, int len)
{
    int i;
    if(pos < 1 || pos > S->curlen - len + 1 || len < 0)
    {
        return 0;
    }
    for (i = pos + len - 1; i < S->curlen; i++)
    {
        S->str[i - len] = S->str[i];
    }
    S->curlen = S->curlen - len;
    S->str[S->curlen] = '\0';
    return 1;
}

// 替换
void Replace(SString *S, int pos, int len, SString *T)
{
    int k, l, n, m, p;
    l = pos + len;
    if(len == T->curlen)
    {
        for(k = 0; k < T->curlen; k++)
        {
            S->str[pos - 1] = T->str[k];
            pos++;
        }
        S->curlen = S->curlen + T->curlen - len;
        S->str[S->curlen] = '\0';
    }
    else
    {
        if(len > T->curlen)
        {
            while(S->str[l - 1] != '\0')
            {
                m = len - T->curlen;
                S->str[l - m - 1] = S->str[l - 1];
                l++;
            }
            for (k = 0; k < T->curlen; k++)
            {
                S->str[pos - 1] = T->str[k];
                pos++;
            }
            S->curlen = S->curlen + T->curlen - len;
            S->str[S->curlen] = '\0';
        }
        else
        {
            if(len < T->curlen){
                p = n = S->curlen;
                while(n >= pos + len)
                {
                    m = T->curlen - len;
                    S->str[n + m - 1] = S->str[n - 1];
                    n--;
                }
                for(k = 0; k < T->curlen; k++)
                {
                    S->str[pos - 1] = T->str[k];
                    pos++;
                }
            }
            S->curlen = S->curlen + T->curlen - len;
            S->str[S->curlen] = '\0';
        }
    }
}

// 定位
int StrIndex(SString *S, SString *T)
{
    int i = 0;
    int j = 0;
    while(i < S->curlen && j < T->curlen)
    {
        if(S->str[i] == T->str[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == T->curlen)
    {
        return i - T->curlen + 1;
    }
    else
    {
        return 0;
    }
}

// 输出
void StrPrint(SString *S)
{
    int i;
    for (i = 0; i < S->curlen; i++) {
        printf("%c", S->str[i]);
    }
    printf("\n");
}

int main()
{
    SString s1, s2, s3, s4;

    printf("-------------基本操作测试-------------\n");
    // 测试赋值和打印
    StrAssign(&s1, "Hello");
    StrAssign(&s2, "World");
    printf("s1: ");
    StrPrint(&s1);
    printf("s2: ");
    StrPrint(&s2);

    // 测试长度
    printf("\n长度测试:\n");
    printf("s1的长度: %d\n", Length(&s1));
    printf("s2的长度: %d\n", Length(&s2));

    // 测试复制
    printf("\n复制测试:\n");
    StrCopy(&s3, &s1);
    printf("复制s1到s3后，s3: ");
    StrPrint(&s3);

    // 测试比较
    printf("\n比较测试:\n");
    printf("s1和s3比较结果: %d\n", StrEqual(&s1, &s3));  // 应该输出1
    printf("s1和s2比较结果: %d\n", StrEqual(&s1, &s2));  // 应该输出0

    printf("\n-------------高级操作测试-------------\n");
    // 测试连接
    printf("\n连接测试:\n");
    StrCat(&s4, &s1, &s2);
    printf("s1和s2连接结果: ");
    StrPrint(&s4);

    // 测试子串
    printf("\n求子串测试:\n");
    SString sub;
    SubString(&sub, &s4, 2, 4);  // 从第2个位置开始取4个字符
    printf("s4从位置2开始长度为4的子串: ");
    StrPrint(&sub);

    // 测试插入
    printf("\n插入测试:\n");
    StrAssign(&s3, "---");
    printf("原字符串s1: ");
    StrPrint(&s1);
    printf("插入字符串s3: ");
    StrPrint(&s3);
    StrInsert(&s1, 3, &s3);  // 在位置3插入s3
    printf("插入后结果: ");
    StrPrint(&s1);

    // 测试删除
    printf("\n删除测试:\n");
    printf("删除前: ");
    StrPrint(&s1);
    Delete(&s1, 3, 3);  // 从位置3开始删除3个字符
    printf("从位置3删除3个字符后: ");
    StrPrint(&s1);

    // 测试替换
    printf("\n替换测试:\n");
    StrAssign(&s1, "Hello World");
    StrAssign(&s2, "XXX");
    printf("原字符串: ");
    StrPrint(&s1);
    Replace(&s1, 2, 3, &s2);  // 从位置2开始替换3个字符为s2
    printf("将位置2开始的3个字符替换为'XXX'后: ");
    StrPrint(&s1);

    // 测试定位
    printf("\n定位测试:\n");
    StrAssign(&s1, "Hello World");
    StrAssign(&s2, "World");
    printf("在字符串: ");
    StrPrint(&s1);
    printf("中查找: ");
    StrPrint(&s2);
    int pos = StrIndex(&s1, &s2);
    printf("查找结果位置: %d\n", pos);

    // 测试空串
    printf("\n空串测试:\n");
    StrAssign(&s1, "");
    printf("空串判断结果: %d\n", Empty(&s1));

    // 测试边界情况
    printf("\n-------------边界情况测试-------------\n");
    // 测试过长字符串的插入
    StrAssign(&s1, "Short string");
    char longStr[150] = "This is a very long string that exceeds the maximum length limit of our string implementation";
    StrAssign(&s2, longStr);
    printf("插入过长字符串结果: %d\n", StrInsert(&s1, 1, &s2));

    return 0;
}