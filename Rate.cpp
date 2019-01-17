#include <iostream>
#include <cstdio>
#include "Student.h"
using namespace std;

//ˢ��ÿ��ѧ��ÿһ�ܵĳ�����
void RateAllWeek()
{
    for(int num = 1; num < studentNum; num++) //��ѯϵͳ������������м�¼����õ�������Ϣ
    {
        if(isInclude(num)) //��ѯѧ���Ƿ����
        {
            for(int i = 1; i <= 20; i++) //��ѯ20����Ϣ
            {
                if(stu.student[num].week[i].effectiveness) //��ѯ���ܿ�����Ϣ�Ƿ���Ч
                {
                    double all = 0, participation = 0;
                    for(int j = 1; j <= 5; j++) //��ѯ����һ��������
                    {
                        if(stu.student[num].week[i].day[j].effectiveness)   //��ѯ���쿼����Ϣ�Ƿ���Ч
                        {
                            for(int k = 1; k <= 8; k++) //��ѯ��һ�ڿε��ڰ˽ڿ�
                            {
                                if(stu.student[num].week[i].day[j].lession[k].effectiveness) //��ѯ��ڿο�����Ϣ�Ƿ���Ч
                                {
                                    int tmp = stu.student[num].week[i].day[j].lession[k].attendance;
                                    if(tmp != -1) //����-1������ü�¼��Ч
                                    {
                                        all++; //ͳ�����еĿ�����Ϣ
                                        if(tmp == 1)
                                            participation++; //ͳ��ȱ�ڵĿ�����Ϣ
                                    }
                                }
                            }
                        }
                    }
                    stu.student[num].week[i].rate = participation / all; //���ܳ�����
                }
            }
        }
    }
    cout << "������ˢ�³ɹ�" << endl;
}

//��ѯĳһ��ͬѧ�����ܵĿ�����
void showOneRate()
{
    int num = check();
    if(num == -1)
        return;
    cout << "��ѯ�ɹ������ѯ����" << endl;
    showPersion(num);
    cout << "��������鿴��ģʽ" << endl;
    cout << "1.���������������" << endl;
    cout << "2.���ճ����ʴӴ�С���" << endl;
    cout << "3.���ճ����ʴ�С�������" << endl;
    int select = CheckInputSelect();
    cout << "�������:" << endl;
    if(select == 1)
    {
        for(int i = 1; i <= 20; i++)
        {
            if (stu.student[num].week[i].effectiveness)
            {
                double ans = stu.student[num].week[i].rate * 100;
                printf("��%d��: %0.2lf%%\n", i, ans);
            }
        }
    }
    else
    {
        const int MAXN = 20;
        Rate arr[MAXN]; //����ṹ�壬������������Ӧ�ų�����
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
        SelectSort(arr, cnt); //����
        if(select == 2)
        {
            for(int i = MAXN - 1; i >= 1; i--) //�Ӵ�С���
            {
                if(arr[i].week != -1)
                {
                    double ans = stu.student[num].week[i].rate * 100;
                    printf("��%d��: %0.2lf%%\n", i, ans);
                }
            }
        }
        else
        {
            for(int i = 1; i < MAXN; i++) //��С�������
            {
                if(arr[i].week != -1)
                {
                    double ans = stu.student[num].week[i].rate * 100;
                    printf("��%d��: %0.2lf%%\n", i, ans);
                }
            }
        }
    }
}

//��ѯȫ��ѧ��ĳ�ܳ�����
void showWeekRateAll()
{
    cout << "��������Ҫ��ѯ������" << endl;
    int week;
    cin >> week;
    cout << "��������鿴��ģʽ" << endl;
    cout << "1.���հ༶����������" << endl;
    cout << "2.���ճ����ʴӴ�С���" << endl;
    cout << "3.���ճ����ʴ�С�������" << endl;
    cout << "�������:" << endl;
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
                    printf("��%d��: %0.2lf%%\n", week, ans);
                }
                else
                    cout << stu.student[num].name << ":   "
                         << "���޼�¼" << endl;
            }
        }
    }
    else
    {
        stuRate arr[studentNum]; //����ṹ�壬�������ֶ�Ӧ��ĳһ�ܳ�����
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
            for(int i = studentNum - 1; i >= 1; i--) //�Ӵ�С���
            {
                if(arr[i].name != "")
                {
                    cout << arr[i].name << ":   ";
                    double ans = arr[i].rate * 100;
                    printf("��%d��: %0.2lf%%\n", week, ans);
                }
            }
        }
        else
        {
            for(int i = 1; i < studentNum; i++)  //��С�������
            {
                if(arr[i].name != "")
                {
                    cout << arr[i].name << ":   ";
                    double ans = arr[i].rate * 100;
                    printf("��%d��: %0.2lf%%\n", week, ans);
                }
            }
        }
    }
}