#include <iostream>
#include <cstdio>
#include "Student.h"
using namespace std;

//刷新每个学生每一周的出勤率
void RateAllWeek()
{
    for(int num = 1; num < studentNum; num++) //查询系统最大容量，若有记录，则该点已有信息
    {
        if(isInclude(num)) //查询学号是否存在
        {
            for(int i = 1; i <= 20; i++) //查询20周信息
            {
                if(stu.student[num].week[i].effectiveness) //查询这周考勤信息是否有效
                {
                    double all = 0, participation = 0;
                    for(int j = 1; j <= 5; j++) //查询星期一到星期五
                    {
                        if(stu.student[num].week[i].day[j].effectiveness)   //查询这天考勤信息是否有效
                        {
                            for(int k = 1; k <= 8; k++) //查询第一节课到第八节课
                            {
                                if(stu.student[num].week[i].day[j].lession[k].effectiveness) //查询这节课考勤信息是否有效
                                {
                                    int tmp = stu.student[num].week[i].day[j].lession[k].attendance;
                                    if(tmp != -1) //不是-1，代表该记录有效
                                    {
                                        all++; //统计所有的考勤信息
                                        if(tmp == 1)
                                            participation++; //统计缺勤的考勤信息
                                    }
                                }
                            }
                        }
                    }
                    stu.student[num].week[i].rate = participation / all; //该周出勤率
                }
            }
        }
    }
    cout << "出勤率刷新成功" << endl;
}

//查询某一个同学所有周的考勤率
void showOneRate()
{
    int num = check();
    if(num == -1)
        return;
    cout << "查询成功，你查询的是" << endl;
    showPersion(num);
    cout << "请输入你查看的模式" << endl;
    cout << "1.按照周数正序输出" << endl;
    cout << "2.按照出勤率从大到小输出" << endl;
    cout << "3.按照出勤率从小到大输出" << endl;
    int select = CheckInputSelect();
    cout << "考勤情况:" << endl;
    if(select == 1)
    {
        for(int i = 1; i <= 20; i++)
        {
            if (stu.student[num].week[i].effectiveness)
            {
                double ans = stu.student[num].week[i].rate * 100;
                printf("第%d周: %0.2lf%%\n", i, ans);
            }
        }
    }
    else
    {
        const int MAXN = 20;
        Rate arr[MAXN]; //排序结构体，里面星期数对应着出勤率
        int cnt = 0;
        for(int i = 1; i <= 20; i++)
        {
            if (stu.student[num].week[i].effectiveness)
            {
                arr[i].rate = stu.student[num].week[i].rate;
                arr[i].week = i;
                cnt++;
            }
        }
        SelectSort(arr, cnt); //排序
        if(select == 2)
        {
            for(int i = MAXN - 1; i >= 1; i--) //从大到小输出
            {
                if(arr[i].week != -1)
                {
                    double ans = stu.student[num].week[i].rate * 100;
                    printf("第%d周: %0.2lf%%\n", i, ans);
                }
            }
        }
        else
        {
            for(int i = 1; i < MAXN; i++) //从小到大输出
            {
                if(arr[i].week != -1)
                {
                    double ans = stu.student[num].week[i].rate * 100;
                    printf("第%d周: %0.2lf%%\n", i, ans);
                }
            }
        }
    }
}

//查询全班学生某周出勤率
void showWeekRateAll()
{
    cout << "请输入你要查询的周数" << endl;
    int week;
    cin >> week;
    cout << "请输入你查看的模式" << endl;
    cout << "1.按照班级序号正序输出" << endl;
    cout << "2.按照出勤率从大到小输出" << endl;
    cout << "3.按照出勤率从小到大输出" << endl;
    cout << "考勤情况:" << endl;
    int select = CheckInputSelect();
    if(select == 1)
    {
        for(int num = 1; num < studentNum; num++)
        {
            if (isInclude(num))
            {
                if(stu.student[num].week[week].effectiveness)
                {
                    cout << stu.student[num].name << ":   ";
                    double ans = stu.student[num].week[week].rate * 100;
                    printf("第%d周: %0.2lf%%\n", week, ans);
                }
                else
                    cout << stu.student[num].name << ":   "
                         << "暂无记录" << endl;
            }
        }
    }
    else
    {
        stuRate arr[studentNum]; //排序结构体，里面名字对应着某一周出勤率
        int cnt = 0;
        for(int i = 1; i <= studentNum; i++)
        {
            if (stu.student[i].week[week].effectiveness)
            {
                arr[i].rate = stu.student[i].week[week].rate;
                arr[i].name = stu.student[i].name;
                cnt++;
            }
        }
        selectSort(arr, cnt);
        if(select == 2)
        {
            for(int i = studentNum - 1; i >= 1; i--) //从大到小输出
            {
                if(arr[i].name != "")
                {
                    cout << arr[i].name << ":   ";
                    double ans = arr[i].rate * 100;
                    printf("第%d周: %0.2lf%%\n", week, ans);
                }
            }
        }
        else
        {
            for(int i = 1; i < studentNum; i++)  //从小到大输出
            {
                if(arr[i].name != "")
                {
                    cout << arr[i].name << ":   ";
                    double ans = arr[i].rate * 100;
                    printf("第%d周: %0.2lf%%\n", week, ans);
                }
            }
        }
    }
}