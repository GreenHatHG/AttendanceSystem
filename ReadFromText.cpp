#include "Student.h"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

//去掉换行符
void ignoreLF(char* c)
{
    char *find = strchr(c, '\n');       //查找换行符
    if(find)                            //如果find不为空指针
        *find = '\0';
}

//字符串转整型
long long stringConvertLL(char* s)
{
    stringstream stream;
    long long ans;
    stream << s;
    stream >> ans;
    return ans;
}

//整型转字符串
const char* intConvertString(int d)
{
    stringstream stream;
    string s;
    stream << d;
    stream >> s;
    return s.c_str();
}

//从项目根目录中导入学生信息到系统中
void loadStudentInformation()
{
    cout << "温馨提示：" << endl;
    bool first = 1;
    int MAXnum = 0;
    FILE *fp;
    char filename[30] = "StudentInformation.txt";
    if((fp = fopen(filename, "r")) == NULL)
        cout << "未导入学生信息文件，请检查文件是否存在" << endl;
    else
    {
        while(!feof(fp)) //一行行读
        {
            char text[1000];
            fgets(text, sizeof(text) - 1, fp);
            ignoreLF(text);   //去掉换行符
            if(first)  //第一行信息没用，不需要读取第一行
            {
                first = false;
                continue;
            }
            //按照空格将一行分割成4部分
            char* pch1 = strtok(text, " ");
            char* pch2 = strtok(NULL, " ");
            char* pch3 = strtok(NULL, " ");
            char* pch4 = strtok(NULL, " ");
            int num = stringConvertLL(pch1); //从文本中读入班级序号
            if(pch3 != NULL)
            {
                if(num > MAXnum) //统计最大班级序号，即为班级人数
                    MAXnum = num;
                //将信息读入系统中
                stu.student[num].number = num;
                stu.student[num].id = stringConvertLL(pch2);
                stu.student[num].name = string(pch3);
                if(!strcmp(pch4,"班委")) //设置不同的权限
                    stu.student[num].permission = 1;
                else if(!strcmp(pch4,"管理员"))
                    stu.student[num].permission = 2;
            }
        }
        stu.stuN = MAXnum;
        cout << "成功导入" << filename << ",学生信息已加载" << endl;
    }
    fclose(fp);
}

//从项目AttendanceInformation文件夹中导入学生考勤信息到系统中
void loadAttendanceInformation()
{
    const int dayNum = 5;
    for(int i = 1; i <= dayNum; i++)
    {
        char filename[20];
        strcpy(filename, "./AttendanceInformation/");
        strcat(filename, intConvertString(i));
        strcat(filename, ".txt");
        FILE *fp;
        if((fp = fopen(filename, "r")) == NULL)
            cout << "未导入" <<  filename << endl;
        else
        {
            int cnt = 0, week, day;
            while(!feof(fp)) //一行行读
            {
                cnt++;
                char text[1000];
                fgets(text, sizeof(text) - 1, fp);
                ignoreLF(text);
                //有5个星期，故需要不断循环读完5个星期
                if(cnt % (stu.stuN + 2) == 1)  //读取文本中的时间信息
                {
                    char* tmp1 = strtok(text, " ");
                    week = stringConvertLL(strtok(NULL, " "));
                    char* tmp2 = strtok(NULL, " ");
                    day = stringConvertLL(strtok(NULL, " "));
                }
                else if(cnt % (stu.stuN + 2) != 2) //读取文本中的考勤信息
                {
                    const int num = stringConvertLL(strtok(text, " "));
                    stu.student[num].week[week].effectiveness = true;
                    stu.student[num].week[week].day[day].effectiveness = true;
                    for(int i = 1; i <= 7; i++)
                    {
                        char* pch = strtok(NULL, " ");
                        if(i >= 2) //文本中第二列开始才记录信息
                        {
                            if(!strcmp(pch, "1"))
                                stu.student[num].week[week].day[day].lession[i - 1].attendance = 1;
                            else
                            {
                                if(!strcmp(pch, "迟到"))
                                    stu.student[num].week[week].day[day].lession[i - 1].attendance = 2;
                                else if(!strcmp(pch, "旷课"))
                                    stu.student[num].week[week].day[day].lession[i - 1].attendance = 3;
                                else
                                    stu.student[num].week[week].day[day].lession[i - 1].attendance = 4;
                            }
                            stu.student[num].week[week].day[day].lession[i - 1].effectiveness = true;
                        }
                    }
                }
            }
            cout << "第" << i << "周考勤信息已导入" << endl;
        }
    }
}
