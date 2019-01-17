#include "Student.h"
#include <iostream>
using namespace std;

Stu stu;
int studentNum = 70; //考勤表存储最多学生人数
string AdministratorPassword = "123"; //管理员登陆密码
string CommitteePassword = "12"; //班委登陆密码

//判断是权限
int selectShow()
{
    cout << "请输入你的班级序号" <<endl;
    int num = CheckInputNum();      //检查合法性
    if(stu.student[num].permission == 0)    //班级成员
        return 0;
    else if(stu.student[num].permission == 1)   //班委
        return 1;
    else
        return 2;    //管理员
}

//判断密码是否正确
bool verify(int num)
{
    cout << "请输入你的密码" << endl;
    string password;
    cin >> password;
    if(num == 1 && password == CommitteePassword)
        return true;
    else if(num == 2 && password == AdministratorPassword)
        return true;
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

    //登陆页面
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
    return 0;
}