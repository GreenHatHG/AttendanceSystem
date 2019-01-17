#include "Student.h"
#include <iostream>
using namespace std;

//显示添加或者修改考勤信息的文字
void showAndAdd(const int num)
{
    int week, day, lession, attendance;
    cout << "请输入周数" << endl;
    cin >> week;
    cout << "请输入星期数" << endl;
    cin >> day;
    cout << "请输入第几节课" << endl;
    cin >> lession;
    cout << "请输入出勤情况" << endl;
    cout << "1－到场，2－迟到，3－旷课，4－请假" << endl;
    cin >> attendance;
    stu.student[num].week[week].day[day].lession[lession].attendance = attendance;
    cout << "添加成功" << endl;
}

//添加学生的考勤信息
void addAttendance()
{
    if(stu.stuN == studentNum)
    {
        cout << "存储人数过多" << endl;
        return;
    }
    cout << "请输入学生的班级序号" << endl;
    int num = CheckInputNum();
    showAndAdd(num);
}

//修改学生的考勤信息
void modifyAttendance()
{
    if(stu.stuN == 0)
    {
        cout << "考勤系统还没有添加信息呢" << endl;
        return;
    }
    int num;
    cout << "请输入学生的班级序号" << endl;
    cin >> num;
    if(!isInclude(num))
    {
        cout << "考勤系统中查无此人" << endl;
        return;
    }
    showAndAdd(num);
    cout << "修改成功" << endl;
}

//删除学号为id的学生的考勤信息
void deleteAttendanceID()
{
    int num;
    cout << "请输入学生的班级序号，以空格分开，以\"-1\"结束" << endl;
    cout << "例如：1 2 3 -1" << endl;
    while(cin >> num && num != -1)
    {
        for(int i = 1; i < 20; i++)
            stu.student[num].week[i].effectiveness = false;
    }
    cout << "删除成功" << endl;
}

//删除某个学生某一周的考勤信息
void deleteAttendanceWeek()
{
    int num, week;
    cout << "请输入学生的班级序号" << endl;
    cin >> num;
    cout << "请输入周数,以空格分开，以\"-1\"结束" << endl;
    while(cin >> week && week != -1)
        stu.student[num].week[week].effectiveness = false;
    cout << "删除成功" << endl;
}

//删除某个学生某一周的某一天考勤信息
void deleteAttendanceDay()
{
    int num, week, day;
    cout << "请输入学生的班级序号" << endl;
    cin >> num;
    cout << "请输入周数" << endl;
    cin >> week;
    cout << "请输入天数,以空格分开，以\"-1\"结束" << endl;
    while(cin >> day && day != -1)
        stu.student[num].week[week].day[day].effectiveness = false;
    cout << "删除成功" << endl;
}

//删除某个学生某一周的某一天的某一节课考勤信息
void deleteAttendanceLession()
{
    int num, week, day, lession;
    cout << "请输入学生的班级序号" << endl;
    cin >> num;
    cout << "请输入周数" << endl;
    cin >> week;
    cout << "请输入天数" << endl;
    cin >> day;
    cout << "请输入要删除第几节课,以空格分开，以\"-1\"结束" << endl;
    while(cin >> lession && lession != -1)
        stu.student[num].week[week].day[day].lession[lession].effectiveness = false;
    cout << "删除成功" << endl;
}



