#include "Student.h"
#include <iostream>
using namespace std;

//��ʾ��ӻ����޸Ŀ�����Ϣ������
void showAndAdd(const int num)
{
    int week, day, lession, attendance;
    cout << "����������" << endl;
    cin >> week;
    cout << "������������" << endl;
    cin >> day;
    cout << "������ڼ��ڿ�" << endl;
    cin >> lession;
    cout << "������������" << endl;
    cout << "1��������2���ٵ���3�����Σ�4�����" << endl;
    cin >> attendance;
    stu.student[num].week[week].day[day].lession[lession].attendance = attendance;
    cout << "��ӳɹ�" << endl;
}

//���ѧ���Ŀ�����Ϣ
void addAttendance()
{
    if(stu.stuN == studentNum)
    {
        cout << "�洢��������" << endl;
        return;
    }
    cout << "������ѧ���İ༶���" << endl;
    int num = CheckInputNum();
    showAndAdd(num);
}

//�޸�ѧ���Ŀ�����Ϣ
void modifyAttendance()
{
    if(stu.stuN == 0)
    {
        cout << "����ϵͳ��û�������Ϣ��" << endl;
        return;
    }
    int num;
    cout << "������ѧ���İ༶���" << endl;
    cin >> num;
    if(!isInclude(num))
    {
        cout << "����ϵͳ�в��޴���" << endl;
        return;
    }
    showAndAdd(num);
    cout << "�޸ĳɹ�" << endl;
}

//ɾ��ѧ��Ϊid��ѧ���Ŀ�����Ϣ
void deleteAttendanceID()
{
    int num;
    cout << "������ѧ���İ༶��ţ��Կո�ֿ�����\"-1\"����" << endl;
    cout << "���磺1 2 3 -1" << endl;
    while(cin >> num && num != -1)
    {
        for(int i = 1; i < 20; i++)
            stu.student[num].week[i].effectiveness = false;
    }
    cout << "ɾ���ɹ�" << endl;
}

//ɾ��ĳ��ѧ��ĳһ�ܵĿ�����Ϣ
void deleteAttendanceWeek()
{
    int num, week;
    cout << "������ѧ���İ༶���" << endl;
    cin >> num;
    cout << "����������,�Կո�ֿ�����\"-1\"����" << endl;
    while(cin >> week && week != -1)
        stu.student[num].week[week].effectiveness = false;
    cout << "ɾ���ɹ�" << endl;
}

//ɾ��ĳ��ѧ��ĳһ�ܵ�ĳһ�쿼����Ϣ
void deleteAttendanceDay()
{
    int num, week, day;
    cout << "������ѧ���İ༶���" << endl;
    cin >> num;
    cout << "����������" << endl;
    cin >> week;
    cout << "����������,�Կո�ֿ�����\"-1\"����" << endl;
    while(cin >> day && day != -1)
        stu.student[num].week[week].day[day].effectiveness = false;
    cout << "ɾ���ɹ�" << endl;
}

//ɾ��ĳ��ѧ��ĳһ�ܵ�ĳһ���ĳһ�ڿο�����Ϣ
void deleteAttendanceLession()
{
    int num, week, day, lession;
    cout << "������ѧ���İ༶���" << endl;
    cin >> num;
    cout << "����������" << endl;
    cin >> week;
    cout << "����������" << endl;
    cin >> day;
    cout << "������Ҫɾ���ڼ��ڿ�,�Կո�ֿ�����\"-1\"����" << endl;
    while(cin >> lession && lession != -1)
        stu.student[num].week[week].day[day].lession[lession].effectiveness = false;
    cout << "ɾ���ɹ�" << endl;
}



