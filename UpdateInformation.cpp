#include <iostream>
#include "Student.h"
using namespace std;

//更改班级成员权限
void modifyAuthority()
{
    int num = check();
    if(num == -1)
        return;
    cout << stu.student[num].name << "的权限为:\t";
    if(stu.student[num].permission == 1)
        cout << "班委";
    else if(stu.student[num].permission == 2)
        cout << "管理员";
    else
        cout << "班级成员";

    cout << endl << "请输入对应的数字，以代表你要更改的权限" << endl;
    cout << "0：班级成员 1：班委，2：管理员" << endl;
    stu.student[num].permission = CheckInputpermission();
    cout << "修改成功" << endl;
}

//删除某个班级成员
void deleteMember()
{
    int num = check();
    if(num == -1)
        return;
    stu.student[num].name = "";
    stu.student[num].number = -1;
    cout << "修改成功" << endl;
    stu.stuN--;
}

//修改某个班级成员信息
void modifyInformation()
{
    int num = check();
    if(num == -1)
        return;
    showPersion(num);
    cout << "请输入你要修改的信息" << endl;
    cout << "1.姓名" << endl;
    cout << "2.学号" << endl;
    int select = CheckInputUpdate();

    if(select == 1)
    {
        cout << "请输入修改后的姓名" << endl;
        cin >> stu.student[num].name;
    }
    else
    {
        cout << "请输入修改后的学号" << endl;
        cin >> stu.student[num].id;
        while(isIncludeID(stu.student[num].id, num))
        {
            cout << "学号已存在，或者不规范，请重新输入" << endl;
            cin >> stu.student[num].id;
        }
    }
    cout << "修改成功" << endl;
    cout << "修改后的信息如下" << endl;
    showPersion(num);
}

//添加某个班级成员信息
void addInformation()
{
    cout << "请输入要添加的学生的班级序号" << endl;
    int num = CheckInputNum();
    if(isInclude(num))
    {
        cout << "考勤系统中已有此人" << endl;
        return;
    }
    if(stu.stuN == studentNum)
    {
        cout << "存储人数过多" << endl;
        return;
    }
    stu.student[num].number = num;
    cout << "请输入你要添加的信息" << endl;
    cout << "1.姓名" << endl;
    cin >> stu.student[num].name;
    cout << "2.学号" << endl;
    cin >> stu.student[num].id;
    while(isIncludeID(stu.student[num].id, num))
    {
        cout << "学号已存在，或者不规范，请重新输入" << endl;
        cin >> stu.student[num].id;
    }
    cout << "3.权限" << endl;
    cout << "0：班级成员 1：班委，2：管理员" << endl;
    stu.student[num].permission = CheckInputpermission();
    cout << "添加后的信息如下" << endl;
    showPersion(num);
    stu.stuN++;
}

