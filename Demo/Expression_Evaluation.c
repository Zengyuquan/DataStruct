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
    fgets(expr, MAX_EXPR_LEN, stdin);
    expr[strcspn(expr, "\n")] = 0; // 移除换行符

    double result = evaluateExpression(expr);
    printf("结果: %f\n", result);

    return 0;
}