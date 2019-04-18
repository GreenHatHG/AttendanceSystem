#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
using namespace std;

struct Lession
{
    //出勤情况：
    //1－出勤，2－迟到，3－旷课，4－请假
    int attendance = -1;
    //考勤信息是否有效，如果考勤信息被删除，则这节课考勤信息无效
    bool effectiveness = false;
};

struct Day //考勤信息结构体
{
    Lession lession[10];

    //考勤信息是否有效，如果考勤信息被删除，则这天考勤信息无效
    bool effectiveness = false;
};

struct Week //一周有7天
{
    Day day[10];
    double rate = 0.0; //出勤率
    //考勤信息是否有效，如果考勤信息被删除，则这周考勤信息无效
    bool effectiveness = false;
};

struct Student //学生个人信息结构体
{
    int number = -1; //班里序号
    long long id; //学号
    string name = ""; //姓名
    //管理员权限：
    //0：班级成员 1：班委，2：管理员
    int permission = 0;
    Week week[20];
};


//排序结构体
typedef struct
{
    int week = -1;
    double rate = 0.0;
}Rate;

typedef struct
{
    string name = "";
    double rate = 0.0;
}stuRate;

extern int studentNum; //考勤表存储最多学生人数
typedef struct //线性表存储考勤信息
{
    Student student[71];
    int stuN; //线性表当前长度
}Stu;

extern Stu stu; //定义全局变量

/*
 * 导入文本信息到系统中
 */
//从项目AttendanceInformation文件夹中导入学生考勤信息到系统中
void loadAttendanceInformation();

//从项目根目录中导入学生信息到系统中
void loadStudentInformation();

/*
 * 检查规范性
 */
//检查输入的选项是否规范
int CheckInputpermission();

//检查输入的选项是否规范
int CheckInputUpdate();

//检查输入的选项是否规范
int CheckInputSelect();

//检查输入的周数是否规范
int CheckInputWeek();

//检查输入的课时是否规范
int CheckInputLession();

//检查输入的天数是否规范
int CheckInputDay();

//检查输入的班级序号是否规范
int CheckInputNum();

//查询学号是否已经存在在系统中
bool isIncludeID(long long ID, int num);

//输入序号并且检查该序号是否存在
int check();

//查找某个学生是否已经登记在了考勤表里面
bool isInclude(const int num);

/*
 * 排序输出
 */
//选择排序算法
void SelectSort(Rate* arr, int len);
void selectSort(stuRate* arr, int len);

/*
 * 查询考勤信息
 */
//显示一个成员特定周的考勤信息
void showOneWeek();

//显示一个成员特定星期的考勤信息
void showOneDay();

//显示一个成员特定某一节课的考勤信息
void showOneLession();

//显示一个成员的所有考勤信息
void showOneALL();

//查询全班学生某周出勤率
void showWeekRateAll();

//查询某一个同学所有周的考勤率
void showOneRate();

/*
 * 查询并修改班级成员信息
 */
//显示某个成员的班级序号，姓名，学号
void showPersion(const int num);

//显示系统里面所有成员的信息
void showAllMember();

//修改某个班级成员信息
void modifyInformation();

//删除某个班级成员
void deleteMember();

//添加某个班级成员信息
void addInformation();

//更改班级成员权限
void modifyAuthority();

/*
 * 修改考勤信息
 */
//添加学生的考勤信息
void addAttendance();

//修改学生的考勤信息
void modifyAttendance();

//删除某个学生的所有考勤信息
void deleteAttendanceID();

//删除某个学生某一周的考勤信息
void deleteAttendanceWeek();

//删除某个学生某一周的某一天考勤信息
void deleteAttendanceDay();

//删除某个学生某一周的某一天的某一节课考勤信息
void deleteAttendanceLession();

//刷新每个学生每一周的出勤率
void RateAllWeek();

/*
 * 显示页面
 */
//显示管理员操作页面
void Administrator();

//班委
void Committee();

//班级成员
void Student();

#endif
