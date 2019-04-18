#include <iostream>
#include <string>
#include "Student.h"

//��ʾĳ����Ա�İ༶��ţ�������ѧ��
void showPersion(const int num)
{
    cout << "�༶���:" << stu.student[num].number  << "  ";
    cout << "ѧ��:" << stu.student[num].id << "  ";
    cout << "����:" << stu.student[num].name << "  ";
    cout << "Ȩ��:";
    if(stu.student[num].permission == 1)
        cout << "��ί";
    else if(stu.student[num].permission == 2)
        cout << "����Ա";
    else
        cout << "�༶��Ա";
    cout << endl;
}

// ����������ʾ�������;
string selectAttendance(const int n)
{
    //1�����ڣ�2���ٵ���3�����Σ�4�����
    switch(n)
    {
        case 2:
            return "�ٵ�";
        case 3:
            return "����";
        case 4:
            return "���";
    }
    return "";
}

//��ʾһ����Ա�����п�����Ϣ
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
                                cout << "��" << i << "�� ";
                                cout << "����" << j << " ";
                                cout << "��" << k << "�ڿ� ";
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
        cout << "���޼�¼" << endl;
        return;
    }
    if(!flag && !flag2)
    {
        cout << "ȫ��" << endl;
    }
    else if(flag2)
        cout << "����ȫ��" << endl;
}

//��ʾһ����Ա�����п�����Ϣ
void showOneALL()
{
    int num = check();
    if(num == -1)
        return;
    cout << "��ѯ�ɹ������ѯ����" << endl;
    showPersion(num);
//    cout << "�������:" << endl;
    showPersionAttendance(num);
}

//��ʾһ����Ա�ض��ܵĿ�����Ϣ
void showOneWeek()
{
    int num = check();
    if(num == -1)
        return;
    cout << "��ѯ�ɹ������ѯ����" << endl;
    showPersion(num);
    cout << "��������Ҫ��ѯ������" << endl;
    int week = CheckInputWeek();
    cout << "��" << week << "�ܿ������:" << endl;
    bool flag = false;
    if(!stu.student[num].week[week].effectiveness)
    {
        cout << "����û�п��ڼ�¼" << endl;
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
                        cout << "��" << num << "�� ";
                        cout << "����" << j << " ";
                        cout << "��" << k << "�ڿ� ";
                        cout << selectAttendance(
                                stu.student[num].week[week].day[j].lession[k].attendance) << endl;
                        flag = true;
                    }

                }
            }
        }
    }
    if(!flag)
        cout << "����ȫ��" << endl;
    else
        cout << "����ȫ��" << endl;
}

//��ʾһ����Ա�ض���Ŀ�����Ϣ
void showOneDay()
{
    int num = check();
    if(num == -1)
        return;
    cout << "��ѯ�ɹ������ѯ����" << endl;
    showPersion(num);
    cout << "��������Ҫ��ѯ���ض�����" << endl;
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
                            cout << "��" << i << "�� ";
                            cout << "����" << day << " ";
                            cout << "��" << k << "�ڿ� ";
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
        cout << "���޼�¼" << endl;
        return;
    }
    if(!flag && !flag2)
    {
        cout << "ȫ��" << endl;
    }
    else if(flag2)
        cout << "����ȫ��" << endl;
}

//��ʾһ����Ա�ض�ĳһ�ڿεĿ�����Ϣ
void showOneLession()
{
    int num = check();
    if(num == -1)
        return;
    cout << "��ѯ�ɹ������ѯ����" << endl;
    showPersion(num);
    cout << "��������Ҫ��ѯ���ض�ĳһ�ڿ�" << endl;
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
                            cout << "��" << i << "�� ";
                            cout << "����" << j << " ";
                            cout << "��" << lession << "�ڿ� ";
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
        cout << "���޼�¼" << endl;
        return;
    }
    if(!flag && !flag2)
    {
        cout << "ȫ��" << endl;
    }
    else if(flag2)
        cout << "����ȫ��" << endl;
}

//��ʾϵͳ�������г�Ա����Ϣ
void showAllMember()
{
    cout << "ϵͳ�������г�Ա����Ϣ:" << endl;
    for(int i = 1; i < studentNum; i++)
    {
        if(isInclude(i))
            showPersion(i);
    }
    cout << "��" << stu.stuN << "��" << endl;
}

