#include "Student.h"
#include <iostream>
using namespace std;

//查找某个学生是否已经登记在了考勤表里面
bool isInclude(const int num)
{
    return (num >= 1 && num < studentNum && stu.student[num].number != -1
            && stu.student[num].name != "");
}

//查询学号是否已经存在在系统中
bool isIncludeID(long long ID, int num)
{
    for(int i = 1; i < studentNum; i++)
    {
        if(stu.student[i].id == ID && i != num)
            return true;
    }
    if(ID < 0)
        return true;
    return false;
}

//输入序号并且检查该序号是否存在
int check()
{
    if(stu.stuN == 0)
    {
        cout << "考勤系统还没有添加信息呢" << endl;
        return -1;
    }

    cout << "请输入学生的班级序号" << endl;
    int num = CheckInputNum();

    if(!isInclude(num))
    {
        cout << "考勤系统中查无此人" << endl;
        return -1;
    }

    return num;
}

//检查输入的选项是否规范
int CheckInputpermission()
{
    int permission;
    cin >> permission;
    while(!(permission >= 0 && permission <= 2) )
    {
        cout << "输入错误，请重新输入" << endl;
        cin >> permission;
    }
    return permission;
}

//检查输入的选项是否规范
int CheckInputUpdate()
{
    int select;
    cin >> select;
    while(!(select == 1 || select == 2) )
    {
        cout << "输入错误，请重新输入" << endl;
        cin >> select;
    }
    return select;
}

//检查输入的选项是否规范
int CheckInputSelect()
{
    int select;
    cin >> select;
    while(!(select >= 1 && select <= 3) )
    {
        cout << "输入错误，请重新输入" << endl;
        cin >> select;
    }
    return select;
}

//检查输入的班级序号是否规范
int CheckInputNum()
{
    int num;
    cin >> num;
    while(!(num >= 1 && num < studentNum))
    {
        cout << "输入错误，请重新输入" << endl;
        cin >> num;
    }
    return num;
}

//检查输入的天数是否规范
int CheckInputDay()
{
    int day;
    cin >> day;
    while(!(day >= 1  && day <= 5))
    {
        cout << "天数输入错误，请重新输入" << endl;
        cin >> day;
    }
    return day;
}

//检查输入的课时是否规范
int CheckInputLession()
{
    int lession;
    cin >> lession;
    while(!(lession >= 1 && lession <= 6))
    {
        cout << "输入错误，请重新输入" << endl;
        cin >> lession;
    }
    return lession;
}

//检查输入的周数是否规范
int CheckInputWeek()
{
    int week;
    cin >> week;
    while(!(week >= 1 && week <= 20))
    {
        cout << "输入错误，请重新输入" << endl;
        cin >> week;
    }
    return week;
}
