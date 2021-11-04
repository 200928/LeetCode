#include <iostream>
using namespace std;

#define MAX 100

char matrix[MAX][MAX];  // 有穷自动机的矩阵
int status_num = 0;     // 状态数量
int letters_num = 0;    // 字母表数量

void output();
void input();
int find_row(char);
int find_col(char);
bool contain(string);

/**
 * @brief 输入有穷自动机的矩阵形式，从 [1,1] 开始，存转化函数
 * 【0】列存储状态标识符 1表示终结符 0表示非终结符
 * 【0】行表示字母表
 */
void input()
{
    char ch; // 用于接收输入的字符
    // 输入状态数量以及字母表个数
    cout << "请输入 DFA 的【状态数】和【字母表个数】:";
    cin >> status_num >> letters_num;

    // 首先依次输入字母表，保存在 matrix[0][2]-matrix[0][letters_num+1]
    cout << "请依次输入字母表:";
    for (int col = 2; col <= letters_num + 1; col++) {
        cin >> ch;
        matrix[0][col] = ch;
    }
    // 输入自动机的矩阵形式，从 [1 1] 开始
    cout << "请输入 DFA 矩阵【每行一个记录】:" << endl;
    for (int row = 1; row <= status_num; row++) {
        for (int col = 1; col <= letters_num + 1; col++) {
            cin >> ch;
            matrix[row][col] = ch;
        }
    }
    // // 然后对状态符标记是否为终结符
    cout << "依次输入状态的标识符【0表示非终态,1表示终态】:" << endl;
    for (int row = 1; row <= status_num; row++) {
        cin >> ch;
        matrix[row][0] = ch;
    }
}

/**
 * @brief 输出 DFA 矩阵
 * 
 */
void output()
{
    cout << endl
         << "输入的DFA矩阵如下:" << endl;
    cout << "----------------------------------------------" << endl;
    for (int row = 0; row <= status_num; row++) {
        for (int col = 0; col <= letters_num + 1; col++) {
            cout << "\t" << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------------------------" << endl;
}

/**
 * @brief 定位行标
 * 
 * @param ch DFA的一个状态，即矩阵里的一个元素
 * @return int 返回 ch 字符在矩阵对应的行标，未找到返回 -1
 */
int find_row(char ch)
{
    int index = -1;
    for (int i = 1; i <= status_num; i++) {
        if (matrix[i][1] == ch) {
            index = i;
        }
    }
    return index;
}

/**
 * @brief 定位列标
 * 
 * @param ch DFA的一个状态，即矩阵里的一个元素
 * @return int 返回 ch 字符在矩阵对应的列标，未找到返回 -1
 */
int find_col(char ch)
{
    int index = -1;
    for (int i = 2; i <= letters_num + 1; i++) {
        if (matrix[0][i] == ch) {
            index = i;
        }
    }
    return index;
}

/**
 * @brief 判断字符串是否是DFA的一个句子
 * 
 * @param str 需判断的字符串
 * @return true 是一个句子
 * @return false 不是一个句子
 */
bool contain(string str)
{
    int row_index = 1; // 表示起始符号的列，永远都是第 1 列
    int col_index = -1; // 用来记录字符的出现在哪一列

    // 判断逻辑
    for (int i = 0; i < str.length(); i++) {
        // 第一个字符都需要从矩阵的第一行记录找，否则通过 find_row 寻找
        row_index = 0 == i ? 1 : find_row(matrix[row_index][col_index]);
        if (-1 == row_index) {
            return false;
        }
        col_index = find_col(str[i]);
        // 找不到对应的字母表
        if (-1 == col_index) {
            if (0 == i) {
                cout << matrix[1][1] << "--(" << str[i] << ")-->空集(字母表无" << str[i] << "符号)" << endl;
            } else {
                cout << "--(" << str[i] << ")-->空集(字母表无" << str[i] << "符号)" << endl;
            }
            return false;
        }
        // 现在知道了行列，查看矩阵此位置的值，如果找不到(即此位置为’*',表示该位置是空集)
        if ('*' == matrix[row_index][col_index]) {
            if (0 == i) {
                cout << matrix[1][1] << "--(" << str[i] << ")-->空集(指向为空集合)" << endl;
            } else {
                cout << "--(" << str[i] << ")-->空集(指向为空集合)" << endl;
            }
            return false;
        } else if (0 == i) {
            cout << "推导路径为:";
            cout << matrix[1][1] << "--(" << str[i] << ")-->" << matrix[row_index][col_index];
        } else {
            cout << "--(" << str[i] << ")-->" << matrix[row_index][col_index];
        }
    }
    cout << endl;
    // 遍历完str字符串之后，计算最后一个状态的位置，只需要知道状态对应的行标
    row_index = find_row(matrix[row_index][col_index]);
    // 如果该状态的标识符为 1 则表示 str 是 DFA 的一个句子，返回 true，反之
    return matrix[row_index][0] == '1';
}

int main()
{
    input();    // 输入 DFA 自动机数据
    output();   // 输出 DFA 的矩阵图

    // 循环判断
    while (true) {
        string str;
        cout << "请输入你要判断的字符串:";
        cin >> str;
        if (contain(str)) {
            cout << "结果:" << "TRUE" << endl;
        } else {
            cout << "结果:" << "FALSE" << endl;
        }
        cout << endl;
    }
    return 0;
}