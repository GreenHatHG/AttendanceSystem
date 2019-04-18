#include "Student.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <unistd.h>
using namespace std;

Stu stu;
int studentNum = 70; //考勤表存储最多学生人数
string AdministratorPassword = "123"; //管理员登陆密码
string CommitteePassword = "12"; //班委登陆密码

//判断是权限
int selectShow()
{
    system("cls");
    cout << "欢迎使用考勤管理系统" << endl;
    cout << "请输入你的班级序号" <<endl;
    int num = CheckInputNum();      //检查合法性
    if(stu.student[num].permission == 1 && stu.student[num].name != "")    //班委
        return 1;
    else if(stu.student[num].permission == 2 && stu.student[num].name != "")   //管理员
        return 2;
    else
        return 0;    //班级成员
}

//判断密码是否正确
bool verify(int num)
{
    cout << "请输入你的密码" << endl;
    string password;
    while(cin >> password)
    {
        if(num == 1 && password == CommitteePassword)
            return true;
        else if(num == 2 && password == AdministratorPassword)
            return true;
        else
            cout << "输入错误，请重新输入" << endl;
    }
    return false;
}

int main()
{
    //线性表当前长度
    stu.stuN = 0;
    //从项目AttendanceInformation文件夹中导入学生考勤信息到系统中
    loadStudentInformation();
    //从项目根目录中导入学生信息到系统中
    loadAttendanceInformation();
    //刷新每个学生每一周的出勤率
    RateAllWeek();
    cout << endl;
    sleep(3);
    //登陆页面
    while(true)
    {
        system("cls");
        int num = selectShow();
        if(num == 1)
        {
            if(verify(1))
                Committee();
        }
        else if(num == 2)
        {
            if(verify(2))
                Administrator();
        }
        else
            Student();
    }
    return 0;
}