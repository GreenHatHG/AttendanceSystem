#include "Student.h"
#include <iostream>
using namespace std;

Stu stu;
int studentNum = 70; //���ڱ�洢���ѧ������
string AdministratorPassword = "123"; //����Ա��½����
string CommitteePassword = "12"; //��ί��½����

//�ж���Ȩ��
int selectShow()
{
    cout << "��������İ༶���" <<endl;
    int num = CheckInputNum();      //���Ϸ���
    if(stu.student[num].permission == 0)    //�༶��Ա
        return 0;
    else if(stu.student[num].permission == 1)   //��ί
        return 1;
    else
        return 2;    //����Ա
}

//�ж������Ƿ���ȷ
bool verify(int num)
{
    cout << "�������������" << endl;
    string password;
    cin >> password;
    if(num == 1 && password == CommitteePassword)
        return true;
    else if(num == 2 && password == AdministratorPassword)
        return true;
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

    //��½ҳ��
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
    return 0;
}