#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

//输入姓名查询班级序号
void selectNoFromName()
{
    string name;
    cout << "请输入你要查询的名字" << endl;
    cin >> name;
    for(int i = 1; i < studentNum; i++)
    {
        if(stu.student[i].name == name)
        {
            showPersion(i);
            return;
        }
    }
    cout << "查无此人" << endl;
}

//输入学号查询班级序号
void selectNoFromID()
{
    long long id;
    cout << "请输入你要查询的学号" << endl;
    cin >> id;
    for(int i = 1; i < studentNum; i++)
    {
        if(stu.student[i].id == id)
        {
            showPersion(i);
            return;
        }
    }
    cout << "查无此人" << endl;
}

//一级菜单
void Level1Menu()
{
    cout << "请选择你要的功能" << endl;
    cout << "1.班级成员信息管理" << endl;
    cout << "2.修改考勤信息" << endl;
    cout << "3.查询考勤信息" << endl;
    cout << "4.查询班级序号" << endl;
    cout << "5.刷新每个学生每一周的出勤率" << endl;
    cout << "0.退出" << endl;
}

//二级菜单第一个选项
void Level2Menu1()
{
    cout << "请选择你要的功能" << endl;
    cout << "1.更改班级成员权限" << endl;
    cout << "2.删除某个班级成员" << endl;
    cout << "3.修改某个班级成员信息" << endl;
    cout << "4.添加某个班级成员信息" << endl;
    cout << "5.查看所有成员信息" << endl;
    cout << "0.返回上一层" << endl;
}

//二级菜单第二个选项
void Level2Menu2()
{
    cout << "请选择你要的功能" << endl;
    cout << "1.添加考勤信息" << endl;
    cout << "2.修改考勤信息" << endl;
    cout << "3.删除某个学生所有的考勤信息" << endl;
    cout << "4.删除某个学生某一周的考勤信息" << endl;
    cout << "5.删除某个学生某一周的某一天考勤信息" << endl;
    cout << "6.删除某个学生某一周的某一天的某一节课考勤信息" << endl;
    cout << "0.返回上一层" << endl;
}

//二级菜单第三个选项
void Level2Menu3()
{
    cout << "请选择你要的功能" << endl;
    cout << "1.显示一个成员的所有考勤信息" << endl;
    cout << "2.显示一个成员特定周的考勤信息" << endl;
    cout << "3.显示一个成员特定天的考勤信息" << endl;
    cout << "4.显示一个成员特定课时的考勤信息" << endl;
    cout << "5.查询某一个同学所有周的考勤率" << endl;
    cout << "6.查询全班学生某周出勤率" << endl;
    cout << "0.返回上一层" << endl;
}

//二级菜单第四个选项
void Level2Menu4()
{
    cout << "请选择你要的功能" << endl;
    cout << "1.输入姓名查询班级序号" << endl;
    cout << "2.输入学号查询班级序号" << endl;
    cout << "0.返回上一层" << endl;
}

void Level3Menu1()
{
    cout << "请选择你要的功能" << endl;
    cout << "1.查询考勤信息" << endl;
    cout << "2.查询班级序号" << endl;
    cout << "0.退出" << endl;
}
void Administrator()
{
    int select1 = 0, select2 = 0;
    system("cls");
    cout << "本系统均使用学生班级序号来查询，若不知道班级序号，请用第四点查询" << endl;
    cout << endl;
    Level1Menu();
    while(true)
    {
        cin >> select1;
        while( 0 < select1 && select1 > 5)
        {
            cout << "输入错误，请重新输入" << endl;
            cin >> select1;
        }
        switch(select1)
        {
            case 0:
                return;
            case 1:
                while(true)
                {
                    cout << endl;
                    Level2Menu1();
                    cin >> select2;
                    while( 0 < select2 && select2 > 5)
                    {
                        cout << "输入错误，请重新输入" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        system("cls");
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            system("cls");
                            modifyAuthority();
                            break;
                        case 2:
                            system("cls");
                            deleteMember();
                            break;
                        case 3:
                            system("cls");
                            modifyInformation();
                            break;
                        case 4:
                            system("cls");
                            addInformation();
                            break;
                        case 5:
                            system("cls");
                            showAllMember();
                            break;
                    }
                }
                break;
            case 2:
                while(true)
                {
                    RateAllWeek();
                    cout << endl;
                    Level2Menu2();
                    cin >> select2;
                    while( 0 < select2 && select2 > 6)
                    {
                        cout << "输入错误，请重新输入" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        system("cls");
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            system("cls");
                            addAttendance();
                            break;
                        case 2:
                            system("cls");
                            modifyAttendance();
                            break;
                        case 3:
                            system("cls");
                            deleteAttendanceID();
                            break;
                        case 4:
                            system("cls");
                            deleteAttendanceWeek();
                            break;
                        case 5:
                            system("cls");
                            deleteAttendanceDay();
                            break;
                        case 6:
                            system("cls");
                            deleteAttendanceLession();
                            break;
                    }
                }
                break;
            case 3:
                while(true)
                {
                    cout << endl;
                    Level2Menu3();
                    cin >> select2;
                    while( 0 < select2 && select2 > 6)
                    {
                        cout << "输入错误，请重新输入" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        system("cls");
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            system("cls");
                            showOneALL();
                            break;
                        case 2:
                            system("cls");
                            showOneWeek();
                            break;
                        case 3:
                            system("cls");
                            showOneDay();
                            break;
                        case 4:
                            system("cls");
                            showOneLession();
                            break;
                        case 5:
                            system("cls");
                            showOneRate();
                            break;
                        case 6:
                            system("cls");
                            showWeekRateAll();
                            break;
                    }
                }
                break;
            case 4:
                while(true)
                {
                    cout << endl;
                    Level2Menu4();
                    cin >> select2;
                    while( 0 < select2 && select2 > 2)
                    {
                        cout << "输入错误，请重新输入" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        system("cls");
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            system("cls");
                            selectNoFromName();
                            break;
                        case 2:
                            system("cls");
                            selectNoFromID();
                            break;
                    }
                }
                break;
            case 5:
                system("cls");
                RateAllWeek();
                cout << endl;
                Level1Menu();
                break;
        }
    }
}


//一级菜单
void CLevel1Menu()
{
    cout << "请选择你要的功能" << endl;
    cout << "1.查看所有成员信息" << endl;
    cout << "2.修改考勤信息" << endl;
    cout << "3.查询考勤信息" << endl;
    cout << "4.查询班级序号" << endl;
    cout << "5.刷新每个学生每一周的出勤率" << endl;
    cout << "0.退出" << endl;
}

void Committee()
{
    int select1 = 0, select2 = 0;
    system("cls");
    cout << "本系统均使用学生班级序号来查询，若不知道班级序号，请用第四点查询" << endl;
    cout << endl;
    CLevel1Menu();
    while(true)
    {
        cin >> select1;
        while( 0 < select1 && select1 > 5)
        {
            cout << "输入错误，请重新输入" << endl;
            cin >> select1;
        }
        switch(select1)
        {
            case 0:
                return;
            case 1:
                showAllMember();
                CLevel1Menu();
                break;
            case 2:
                while(true)
                {
                //    RateAllWeek();
                    cout << endl;
                    Level2Menu2();
                    cin >> select2;
                    while( 0 < select2 && select2 > 6)
                    {
                        cout << "输入错误，请重新输入" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        system("cls");
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            system("cls");
                            addAttendance();
                            break;
                        case 2:
                            system("cls");
                            modifyAttendance();
                            break;
                        case 3:
                            system("cls");
                            deleteAttendanceID();
                            break;
                        case 4:
                            system("cls");
                            deleteAttendanceWeek();
                            break;
                        case 5:
                            system("cls");
                            deleteAttendanceDay();
                            break;
                        case 6:
                            system("cls");
                            deleteAttendanceLession();
                            break;
                    }
                }
                break;
            case 3:
                cout << endl;
                while(true)
                {
                    Level2Menu3();
                    cin >> select2;
                    while( 0 < select2 && select2 > 6)
                    {
                        cout << "输入错误，请重新输入" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        system("cls");
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            system("cls");
                            showOneALL();
                            break;
                        case 2:
                            system("cls");
                            showOneWeek();
                            break;
                        case 3:
                            system("cls");
                            showOneDay();
                            break;
                        case 4:
                            system("cls");
                            showOneLession();
                            break;
                        case 5:
                            system("cls");
                            showOneRate();
                            break;
                        case 6:
                            system("cls");
                            showWeekRateAll();
                            break;
                    }
                }
                break;
            case 4:
                while(true)
                {
                    cout << endl;
                    Level2Menu4();
                    cin >> select2;
                    while( 0 < select2 && select2 > 2)
                    {
                        cout << "输入错误，请重新输入" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        system("cls");
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            system("cls");
                            selectNoFromName();
                            break;
                        case 2:
                            system("cls");
                            selectNoFromID();
                            break;
                    }
                }
                break;
            case 5:
                system("cls");
                RateAllWeek();
                cout << endl;
                CLevel1Menu();
                break;
        }
    }
}

void Student()
{
    int select1 = 0, select2 = 0;
    system("cls");
    cout << "本系统均使用学生班级序号来查询，若不知道班级序号，请用第二点查询" << endl;
    cout << "请选择你要的功能" << endl;
    cout << "1.查询考勤信息" << endl;
    cout << "2.查询班级序号" << endl;
    cout << "0.退出" << endl;
    while(true)
    {
        cin >> select1;
        while( 0 < select1 && select1 > 2)
        {
            cout << "输入错误，请重新输入" << endl;
            cin >> select1;
        }
        if(select1 == 0)
            return;
        switch(select1)
        {
            case 1:
            while(true)
            {
                cout << endl;
                Level2Menu3();
                cin >> select2;
                while( 0 < select2 && select2 > 6)
                {
                    cout << "输入错误，请重新输入" << endl;
                    cin >> select2;
                }
                if(select2 == 0)
                {
                    system("cls");
                    Level3Menu1();
                    break;
                }
                switch(select2)
                {
                    case 1:
                        system("cls");
                        showOneALL();
                        break;
                    case 2:
                        system("cls");
                        showOneWeek();
                        break;
                    case 3:
                        system("cls");
                        showOneDay();
                        break;
                    case 4:
                        system("cls");
                        showOneLession();
                        break;
                    case 5:
                        system("cls");
                        showOneRate();
                        break;
                    case 6:
                        system("cls");
                        showWeekRateAll();
                        break;
                }
            }
            break;
            case 2:
                while(true)
                {
                    cout << endl;
                    Level2Menu4();
                    cin >> select2;
                    while( 0 < select2 && select2 > 2)
                    {
                        cout << "输入错误，请重新输入" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        system("cls");
                        Level3Menu1();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            system("cls");
                            selectNoFromName();
                            break;
                        case 2:
                            system("cls");
                            selectNoFromID();
                            break;
                    }
                }
                break;
        }
    }
}