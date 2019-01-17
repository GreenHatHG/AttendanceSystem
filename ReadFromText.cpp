#include "Student.h"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

//ȥ�����з�
void ignoreLF(char* c)
{
    char *find = strchr(c, '\n');       //���һ��з�
    if(find)                            //���find��Ϊ��ָ��
        *find = '\0';
}

//�ַ���ת����
long long stringConvertLL(char* s)
{
    stringstream stream;
    long long ans;
    stream << s;
    stream >> ans;
    return ans;
}

//����ת�ַ���
const char* intConvertString(int d)
{
    stringstream stream;
    string s;
    stream << d;
    stream >> s;
    return s.c_str();
}

//����Ŀ��Ŀ¼�е���ѧ����Ϣ��ϵͳ��
void loadStudentInformation()
{
    cout << "��ܰ��ʾ��" << endl;
    bool first = 1;
    int MAXnum = 0;
    FILE *fp;
    char filename[30] = "StudentInformation.txt";
    if((fp = fopen(filename, "r")) == NULL)
        cout << "δ����ѧ����Ϣ�ļ��������ļ��Ƿ����" << endl;
    else
    {
        while(!feof(fp)) //һ���ж�
        {
            char text[1000];
            fgets(text, sizeof(text) - 1, fp);
            ignoreLF(text);   //ȥ�����з�
            if(first)  //��һ����Ϣû�ã�����Ҫ��ȡ��һ��
            {
                first = false;
                continue;
            }
            //���տո�һ�зָ��4����
            char* pch1 = strtok(text, " ");
            char* pch2 = strtok(NULL, " ");
            char* pch3 = strtok(NULL, " ");
            char* pch4 = strtok(NULL, " ");
            int num = stringConvertLL(pch1); //���ı��ж���༶���
            if(pch3 != NULL)
            {
                if(num > MAXnum) //ͳ�����༶��ţ���Ϊ�༶����
                    MAXnum = num;
                //����Ϣ����ϵͳ��
                stu.student[num].number = num;
                stu.student[num].id = stringConvertLL(pch2);
                stu.student[num].name = string(pch3);
                if(!strcmp(pch4,"��ί")) //���ò�ͬ��Ȩ��
                    stu.student[num].permission = 1;
                else if(!strcmp(pch4,"����Ա"))
                    stu.student[num].permission = 2;
            }
        }
        stu.stuN = MAXnum;
        cout << "�ɹ�����" << filename << ",ѧ����Ϣ�Ѽ���" << endl;
    }
    fclose(fp);
}

//����ĿAttendanceInformation�ļ����е���ѧ��������Ϣ��ϵͳ��
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
            cout << "δ����" <<  filename << endl;
        else
        {
            int cnt = 0, week, day;
            while(!feof(fp)) //һ���ж�
            {
                cnt++;
                char text[1000];
                fgets(text, sizeof(text) - 1, fp);
                ignoreLF(text);
                //��5�����ڣ�����Ҫ����ѭ������5������
                if(cnt % (stu.stuN + 2) == 1)  //��ȡ�ı��е�ʱ����Ϣ
                {
                    char* tmp1 = strtok(text, " ");
                    week = stringConvertLL(strtok(NULL, " "));
                    char* tmp2 = strtok(NULL, " ");
                    day = stringConvertLL(strtok(NULL, " "));
                }
                else if(cnt % (stu.stuN + 2) != 2) //��ȡ�ı��еĿ�����Ϣ
                {
                    const int num = stringConvertLL(strtok(text, " "));
                    stu.student[num].week[week].effectiveness = true;
                    stu.student[num].week[week].day[day].effectiveness = true;
                    for(int i = 1; i <= 7; i++)
                    {
                        char* pch = strtok(NULL, " ");
                        if(i >= 2) //�ı��еڶ��п�ʼ�ż�¼��Ϣ
                        {
                            if(!strcmp(pch, "1"))
                                stu.student[num].week[week].day[day].lession[i - 1].attendance = 1;
                            else
                            {
                                if(!strcmp(pch, "�ٵ�"))
                                    stu.student[num].week[week].day[day].lession[i - 1].attendance = 2;
                                else if(!strcmp(pch, "����"))
                                    stu.student[num].week[week].day[day].lession[i - 1].attendance = 3;
                                else
                                    stu.student[num].week[week].day[day].lession[i - 1].attendance = 4;
                            }
                            stu.student[num].week[week].day[day].lession[i - 1].effectiveness = true;
                        }
                    }
                }
            }
            cout << "��" << i << "�ܿ�����Ϣ�ѵ���" << endl;
        }
    }
}
