## 表达式求值

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPR_LEN 100
#define MAX_STACK_SIZE 100

// 栈结构
typedef struct {
    int top;
    double items[MAX_STACK_SIZE];
} NumberStack;

typedef struct {
    int top;
    char items[MAX_STACK_SIZE];
} OperatorStack;

// 栈操作
void initNumberStack(NumberStack *s) { s->top = -1; }
void pushNumber(NumberStack *s, double val) { s->items[++(s->top)] = val; }
double popNumber(NumberStack *s) { return s->items[(s->top)--]; }

void initOperatorStack(OperatorStack *s) { s->top = -1; }
void pushOperator(OperatorStack *s, char op) { s->items[++(s->top)] = op; }
char popOperator(OperatorStack *s) { return s->items[(s->top)--]; }

// 获取运算符优先级
int precedence(char op) {
    switch(op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}

// 应用运算符
void applyOperator(NumberStack *numbers, char op) {
    double b = popNumber(numbers);
    double a = popNumber(numbers);
    switch(op) {
        case '+': pushNumber(numbers, a + b); break;
        case '-': pushNumber(numbers, a - b); break;
        case '*': pushNumber(numbers, a * b); break;
        case '/': pushNumber(numbers, a / b); break;
    }
}

// 表达式求值
double evaluateExpression(const char *expr) {
    NumberStack numbers;
    OperatorStack operators;
    initNumberStack(&numbers);
    initOperatorStack(&operators);

    int i = 0;
    while (expr[i]) {
        if (isdigit(expr[i]) || expr[i] == '.') {
            // 读取数字
            char *end;
            double num = strtod(expr + i, &end);
            pushNumber(&numbers, num);
            i = end - expr;
        } else if (expr[i] == '(') {
            pushOperator(&operators, expr[i]);
            i++;
        } else if (expr[i] == ')') {
            while (operators.top >= 0 && operators.items[operators.top] != '(') {
                applyOperator(&numbers, popOperator(&operators));
            }
            if (operators.top >= 0 && operators.items[operators.top] == '(') {
                popOperator(&operators); // 弹出左括号
            }
            i++;
        } else if (strchr("+-*/", expr[i])) {
            while (operators.top >= 0 && 
                   precedence(operators.items[operators.top]) >= precedence(expr[i])) {
                applyOperator(&numbers, popOperator(&operators));
            }
            pushOperator(&operators, expr[i]);
            i++;
        } else {
            i++; // 跳过空白字符
        }
    }

    while (operators.top >= 0) {
        applyOperator(&numbers, popOperator(&operators));
    }

    return numbers.items[0];
}

int main() {
    char expr[MAX_EXPR_LEN];
    printf("请输入表达式: ");
    fgets(expr, MAX_EXPR_LEN, stdin);
    expr[strcspn(expr, "\n")] = 0; // 移除换行符

    double result = evaluateExpression(expr);
    printf("结果: %f\n", result);

    return 0;
}
```

### 宏定义与常量

```c
#define MAX_EXPR_LEN 100
#define MAX_STACK_SIZE 100
```

1、‘#define MAX_EXPR_LEN 100’——定义一个‘MAX_EXPR_LEN‘常量为100，在后续将用于’expr‘数组的最大长度。

2、‘#define MAX_STACK_SIZE 100’——定义一个‘MAX_STACK_SIZE‘常量为100，在后续将用于定义栈的最大长度。



### 主函数实现

1、定义一个char类型的数组’expr‘，最大长度为‘MAX_EXPR_LEN’即为100，用来存放从键盘输入的表达式。

2、在控制台上打印‘请输入表达式: ’，提示用户输入表达式。

3、利用‘fgets()’函数将从键盘输入的表达式存放在‘expr’数组中，最大长度是’MAX_EXPR_LEN‘的长度减1，因为最后留需要一个位置给 ‘\0’，在输入达到最大长度的时候，如果不到最大程度则在最后加上‘\n’；’stdin‘ 表示标准输入。

4、利用‘strcspn()’函数去查找’\n‘字符在‘expr’数组中第一个出现的下标位置，将’\n‘的下标位置的数值修改为0；此操作去除了’\n‘，便于后续的运算。

5、将’expr‘作为实参传递给调用的‘evaluateExpression()’函数；再定义一个’double‘类型的‘result’去接收’evaluateExpression()‘函数计算后的返回值，并将该值打印出来。



### 栈结构与操作函数

```c
// 栈结构
typedef struct {
    int top;
    double items[MAX_STACK_SIZE];
} NumberStack;

typedef struct {
    int top;
    char items[MAX_STACK_SIZE];
} OperatorStack;

// 栈操作
void initNumberStack(NumberStack *s) { s->top = -1; }
void pushNumber(NumberStack *s, double val) { s->items[++(s->top)] = val; }
double popNumber(NumberStack *s) { return s->items[(s->top)--]; }

void initOperatorStack(OperatorStack *s) { s->top = -1; }
void pushOperator(OperatorStack *s, char op) { s->items[++(s->top)] = op; }
char popOperator(OperatorStack *s) { return s->items[(s->top)--]; }
```

1、定义了两个结构体，一个为’NumberStack‘是数字栈；一个为’OperatorStack‘是操作符栈。

2、两个栈结构体内都同样定义了‘int top'和’char items‘来表示栈顶和栈元素；其中栈最大长度’MAX_STACK_SIZE‘即为100。

3、分别为栈定义三个函数来对栈进行：初始化、进栈、出栈操作；

数字栈的操作函数分别为：’initNumberStack()‘、’pushNumber()‘、’popNumber()‘

操作符栈的操作函数分别为：’initOperatorStack()‘、’pushOperator()‘、’popOperator()‘



### 运算符优先级判断

```c
int precedence(char op) {
    switch(op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        default: return 0;
    }
}
```

1、定义一个‘precedence()’函数；其形参是‘char op’，为操作符；返回1后者2代表操作符运算优先级的高低。

2、利用switch 语句判断操作符 ’op‘的值的优先级；若 ’op‘为’+'、‘-’则返回1，若 ’op‘为’*'、‘/’则返回2;表示乘除的运算优先级高于加减。

3、若为其他值，则返回0。



### 运算符应用

```c
void applyOperator(NumberStack *numbers, char op) {
    double b = popNumber(numbers);
    double a = popNumber(numbers);
    switch(op) {
        case '+': pushNumber(numbers, a + b); break;
        case '-': pushNumber(numbers, a - b); break;
        case '*': pushNumber(numbers, a * b); break;
        case '/': pushNumber(numbers, a / b); break;
    }
}
```

1、定义一个‘applyOperator()’函数；其形参是一个指向 ’NumberStack‘结构（数字栈）的指针和操作符‘op’。

2、定义一个‘double b’接收数字栈出栈的栈顶元素；再定义一个‘double a’接收数字栈再次出栈的次栈顶元素；作为后续计算所需要的数值。

注意：先弹出 ‘b’，再弹出 ‘a’，因为栈是后进先出的结构，所以 ’a‘ 是先入栈的操作数，’b‘ 是后入栈的操作数。

3、利用switch 语句分支选择操作符 ’op‘的操作；其操作分别对应加减乘除，最后再将计算结果得到的数压入数字栈。



### 表达式解析与求值	

```c
double evaluateExpression(const char *expr) {
    NumberStack numbers;
    OperatorStack operators;
    initNumberStack(&numbers);
    initOperatorStack(&operators);

    int i = 0;
    while (expr[i]) {
        if (isdigit(expr[i]) || expr[i] == '.') {
            // 读取数字
            char *end;
            double num = strtod(expr + i, &end);
            pushNumber(&numbers, num);
            i = end - expr;
        } else if (expr[i] == '(') {
            pushOperator(&operators, expr[i]);
            i++;
        } else if (expr[i] == ')') {
            while (operators.top >= 0 && operators.items[operators.top] != '(') {
                applyOperator(&numbers, popOperator(&operators));
            }
            if (operators.top >= 0 && operators.items[operators.top] == '(') {
                popOperator(&operators); // 弹出左括号
            }
            i++;
        } else if (strchr("+-*/", expr[i])) {
            while (operators.top >= 0 && 
                   precedence(operators.items[operators.top]) >= precedence(expr[i])) {
                applyOperator(&numbers, popOperator(&operators));
            }
            pushOperator(&operators, expr[i]);
            i++;
        } else {
            i++; // 跳过空白字符
        }
    }

    while (operators.top >= 0) {
        applyOperator(&numbers, popOperator(&operators));
    }

    return numbers.items[0];
}
```

1、先定义一个‘evaluateExpression()’函数；形参是‘const char *expr’，其中的‘const’可以防止函数内部意外地修改传入的字符串内容；最后放回计算结果。

2、在函数体中，首先定义两个结构体变量：‘NumberStack numbers’和‘OperatorStack operators’，一个数字栈和一个操作符栈；并初始化数字栈和操作符栈。

3、定义一个‘int’类型的变量‘i’；作为下标去访问遍历表达式字符串中的每个字符。

4、利用while循环，循环遍历表达式字符串中的每个字符，直到遇到字符串的结束符‘\0’。

5、通过if-else选择分支结构去处理不同类型的字符。

6、假如是数字字符或是点号，利用if判断获取，判断条件是‘isdigit(expr[i]) || expr[i] == '.'’；若为数字字符或是点号，利用‘strtod()’函数不断读取，读取到非数字字符或是点号的字符时时结束，由定义的‘char *end’指针变量接收读取数字后的结束位置；从下标‘i'到读取数字后的结束位置这些字符将被转化成为’double‘类型的数据，存放在定义的’double num‘中；再将‘num’中的数压入数字栈中；最后移动下标’i‘，将索引 ‘i’更新为 ‘end’指针的位置，这样做的目的是跳过已经读取的数字部分，直接将’i‘移动到下一个需要处理的字符位置。

7、若是左括号’(‘，先利用if判断获取，随后将左括号压入操作符栈，最后’i++‘移动下标。

8、若是右括号’)‘，先利用if判断获取；再通过while循环，循环条件是操作符栈不为空，且操作符栈的栈顶元素不为左括号时：先将操作符栈的栈顶元素出栈，作为操作符‘op’实参传入调用的‘applyOperator()’函数；若操作符栈不为空，且操作符栈的栈顶元素为左括号时：直接弹出左括号；最后’i++‘移动下标。

9、若是加减乘除操作符’+-*/‘，先利用if判断获取；再通过while循环，循环条件是操作符栈不为空，且利用判断运算符优先级‘precedence()’函数判断操作符栈顶元素的算术优先级是否大于或等于当前表达式字符串中的操作符的算术优先级；若循环条件为真，则先将操作符栈的栈顶元素出栈，作为操作符‘op’实参传入调用的‘applyOperator()’函数，直到循环条件为假；若操作符栈顶元素的算术优先级小于当前表达式字符串中的操作符的算术优先级，则将该当前表达式字符串中的操作符压入操作符栈；最后’i++‘移动下标。

10、若当前表达式字符串中的字符不是数字、点号、括号、操作符等，直接’i++‘移动下标跳过。

11、遍历完表达式字符串中的字符后，若操作符栈不为空，利用while循环将操作符栈中的操作符依次出栈，作为操作符‘op’实参传入调用的‘applyOperator()’函数进行运算；直到操作符栈空。

12、最后放回数字栈栈底的数据，既是计算的结果。















