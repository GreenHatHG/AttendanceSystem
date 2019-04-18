#include <iostream>
#include <string>
#include "Student.h"

//显示某个成员的班级序号，姓名，学号
void showPersion(const int num)
{
    cout << "班级序号:" << stu.student[num].number  << "  ";
    cout << "学号:" << stu.student[num].id << "  ";
    cout << "姓名:" << stu.student[num].name << "  ";
    cout << "权限:";
    if(stu.student[num].permission == 1)
        cout << "班委";
    else if(stu.student[num].permission == 2)
        cout << "管理员";
    else
        cout << "班级成员";
    cout << endl;
}

// 输入数字显示考勤情况;
string selectAttendance(const int n)
{
    //1－出勤，2－迟到，3－旷课，4－请假
    switch(n)
    {
        case 2:
            return "迟到";
        case 3:
            return "旷课";
        case 4:
            return "请假";
    }
    return "";
}

//显示一个成员的所有考勤信息
void showPersionAttendance(const int num)
{
    bool flag = true, flag2 = false;
    for(int i = 1; i <= 20; i++)
    {
        if(stu.student[num].week[i].effectiveness)
        {
            for(int j = 1; j <= 5; j++)
            {
                if(stu.student[num].week[i].day[j].effectiveness)
                {
                    for(int k = 1; k <= 8; k++)
                    {
                        if(stu.student[num].week[i].day[j].lession[k].effectiveness)
                        {
                            flag = false;
                            if(stu.student[num].week[i].day[j].lession[k].attendance != 1)
                            {
                                cout << "第" << i << "周 ";
                                cout << "星期" << j << " ";
                                cout << "第" << k << "节课 ";
                                cout << selectAttendance(
                                        stu.student[num].week[i].day[j].lession[k].attendance) << endl;
                                flag2 = true;
                            }

                        }
                    }
                }
            }
        }
    }
    if(flag)
    {
        cout << "查无记录" << endl;
        return;
    }
    if(!flag && !flag2)
    {
        cout << "全勤" << endl;
    }
    else if(flag2)
        cout << "其他全勤" << endl;
}

//显示一个成员的所有考勤信息
void showOneALL()
{
    int num = check();
    if(num == -1)
        return;
    cout << "查询成功，你查询的是" << endl;
    showPersion(num);
//    cout << "考勤情况:" << endl;
    showPersionAttendance(num);
}

//显示一个成员特定周的考勤信息
void showOneWeek()
{
    int num = check();
    if(num == -1)
        return;
    cout << "查询成功，你查询的是" << endl;
    showPersion(num);
    cout << "请输入你要查询的周数" << endl;
    int week = CheckInputWeek();
    cout << "第" << week << "周考勤情况:" << endl;
    bool flag = false;
    if(!stu.student[num].week[week].effectiveness)
    {
        cout << "该周没有考勤记录" << endl;
        return;
    }
    for(int j = 1; j <= 5; j++)
    {
        if(stu.student[num].week[week].day[j].effectiveness)
        {
            for(int k = 1; k <= 8; k++)
            {
                if(stu.student[num].week[week].day[j].lession[k].effectiveness)
                {
                    if(stu.student[num].week[week].day[j].lession[k].attendance != 1)
                    {
                        cout << "第" << num << "周 ";
                        cout << "星期" << j << " ";
                        cout << "第" << k << "节课 ";
                        cout << selectAttendance(
                                stu.student[num].week[week].day[j].lession[k].attendance) << endl;
                        flag = true;
                    }

                }
            }
        }
    }
    if(!flag)
        cout << "该周全勤" << endl;
    else
        cout << "其他全勤" << endl;
}

//显示一个成员特定天的考勤信息
void showOneDay()
{
    int num = check();
    if(num == -1)
        return;
    cout << "查询成功，你查询的是" << endl;
    showPersion(num);
    cout << "请输入你要查询的特定天数" << endl;
    int day = CheckInputDay();
    bool flag = true, flag2 = false;
    for(int i = 1; i <= 20; i++)
    {
        if(stu.student[num].week[i].effectiveness)
        {
            if(stu.student[num].week[i].day[day].effectiveness)
            {
                for(int k = 1; k <= 8; k++)
                {
                    if(stu.student[num].week[i].day[day].lession[k].effectiveness)
                    {
                        flag = false;
                        if(stu.student[num].week[i].day[day].lession[k].attendance != 1)
                        {
                            cout << "第" << i << "周 ";
                            cout << "星期" << day << " ";
                            cout << "第" << k << "节课 ";
                            cout << selectAttendance(
                                    stu.student[num].week[i].day[day].lession[k].attendance) << endl;
                            flag2 = true;
                        }

                    }
                }
            }
        }
    }
    if(flag)
    {
        cout << "查无记录" << endl;
        return;
    }
    if(!flag && !flag2)
    {
        cout << "全勤" << endl;
    }
    else if(flag2)
        cout << "其他全勤" << endl;
}

//显示一个成员特定某一节课的考勤信息
void showOneLession()
{
    int num = check();
    if(num == -1)
        return;
    cout << "查询成功，你查询的是" << endl;
    showPersion(num);
    cout << "请输入你要查询的特定某一节课" << endl;
    int lession = CheckInputLession();
    bool flag = true, flag2 = false;
    for(int i = 1; i <= 20; i++)
    {
        if(stu.student[num].week[i].effectiveness)
        {
            for(int j = 1; j <= 5; j++)
            {
                if(stu.student[num].week[i].day[j].effectiveness)
                {
                    if(stu.student[num].week[i].day[j].lession[lession].effectiveness)
                    {
                        flag = false;
                        if(stu.student[num].week[i].day[j].lession[lession].attendance != 1)
                        {
                            cout << "第" << i << "周 ";
                            cout << "星期" << j << " ";
                            cout << "第" << lession << "节课 ";
                            cout << selectAttendance(
                                    stu.student[num].week[i].day[j].lession[lession].attendance) << endl;
                            flag2 = true;
                        }

                    }
                }
            }
        }
    }
    if(flag)
    {
        cout << "查无记录" << endl;
        return;
    }
    if(!flag && !flag2)
    {
        cout << "全勤" << endl;
    }
    else if(flag2)
        cout << "其他全勤" << endl;
}

//显示系统里面所有成员的信息
void showAllMember()
{
    cout << "系统里面所有成员的信息:" << endl;
    for(int i = 1; i < studentNum; i++)
    {
        if(isInclude(i))
            showPersion(i);
    }
    cout << "共" << stu.stuN << "人" << endl;
}

