#include "Student.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <unistd.h>
using namespace std;

Stu stu;
int studentNum = 70; //���ڱ�洢���ѧ������
string AdministratorPassword = "123"; //����Ա��½����
string CommitteePassword = "12"; //��ί��½����

//�ж���Ȩ��
int selectShow()
{
    system("cls");
    cout << "��ӭʹ�ÿ��ڹ���ϵͳ" << endl;
    cout << "��������İ༶���" <<endl;
    int num = CheckInputNum();      //���Ϸ���
    if(stu.student[num].permission == 1 && stu.student[num].name != "")    //��ί
        return 1;
    else if(stu.student[num].permission == 2 && stu.student[num].name != "")   //����Ա
        return 2;
    else
        return 0;    //�༶��Ա
}

//�ж������Ƿ���ȷ
bool verify(int num)
{
    cout << "�������������" << endl;
    string password;
    while(cin >> password)
    {
        if(num == 1 && password == CommitteePassword)
            return true;
        else if(num == 2 && password == AdministratorPassword)
            return true;
        else
            cout << "�����������������" << endl;
    }
    return false;
}

int main()
{
    //���Ա�ǰ����
    stu.stuN = 0;
    //����ĿAttendanceInformation�ļ����е���ѧ��������Ϣ��ϵͳ��
    loadStudentInformation();
    //����Ŀ��Ŀ¼�е���ѧ����Ϣ��ϵͳ��
    loadAttendanceInformation();
    //ˢ��ÿ��ѧ��ÿһ�ܵĳ�����
    RateAllWeek();
    cout << endl;
    sleep(3);
    //��½ҳ��
    while(true)
    {
        system("cls");
        int num = selectShow();
        if(num == 1)
        {
            if(verify(1))
                Committee();
        }
        else if(num == 2)
        {
            if(verify(2))
                Administrator();
        }
        else
            Student();
    }
    return 0;
}