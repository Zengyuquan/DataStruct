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
    int i,j;
    for (j = 0; j < strlen(chars); j++)
    {
        for (i = 0; i < strlen(chars); i++)
        {
            S->str[i] = chars[i];
        }
        S->curlen = strlen(chars);
    }
}

// 复制
void StrCopy(SString *S, SString *T)
{
    int i;
    for (i = 0; i < T->curlen; i++)
    {
        S->str[i] = T->str[i];
    }
    S->curlen = T->curlen;
}

// 比较
int StrEqual(SString *S, SString *T)
{
    int i, j;
    if(S->curlen == T->curlen)
    {
        for (i = 0; i < S->curlen; i++)
        {
            if(S->str[i] == T->str[i])
            {
                j = 1;
            }
            else
            {
                j = 0;
                break;
            }
        }
    }
    else
    {
        j = 0;
    }
    return j;
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
    if((pos >= 1 && pos <= S->curlen) && (len >= 0 && len <= S->curlen - pos + 1))
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
    if(S->curlen == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
        for (i = S->curlen; i >= pos - 1; i--)
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
        for(i = MaxLen; i <= pos; i--)
        {
            S->str[i] = S->str[i - T->curlen];
        }
        for(i = pos; i < pos + T->curlen; i++)
        {
            S->str[i] = T->str[i - pos];
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
    if(pos < 1 || pos > S->curlen - len + 1 || len < 0) // 修改了判断条件
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

    return 0;
}