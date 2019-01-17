#include "Student.h"
#include <iostream>
using namespace std;

//����ĳ��ѧ���Ƿ��Ѿ��Ǽ����˿��ڱ�����
bool isInclude(const int num)
{
    return (num >= 1 && num < studentNum && stu.student[num].number != -1
            && stu.student[num].name != "");
}

//��ѯѧ���Ƿ��Ѿ�������ϵͳ��
bool isIncludeID(long long ID, int num)
{
    for(int i = 1; i < studentNum; i++)
    {
        if(stu.student[i].id == ID && i != num)
            return true;
    }
    if(ID < 0)
        return true;
    return false;
}

//������Ų��Ҽ�������Ƿ����
int check()
{
    if(stu.stuN == 0)
    {
        cout << "����ϵͳ��û�������Ϣ��" << endl;
        return -1;
    }

    cout << "������ѧ���İ༶���" << endl;
    int num = CheckInputNum();

    if(!isInclude(num))
    {
        cout << "����ϵͳ�в��޴���" << endl;
        return -1;
    }

    return num;
}

//��������ѡ���Ƿ�淶
int CheckInputpermission()
{
    int permission;
    cin >> permission;
    while(!(permission >= 0 && permission <= 2) )
    {
        cout << "�����������������" << endl;
        cin >> permission;
    }
    return permission;
}

//��������ѡ���Ƿ�淶
int CheckInputUpdate()
{
    int select;
    cin >> select;
    while(!(select == 1 || select == 2) )
    {
        cout << "�����������������" << endl;
        cin >> select;
    }
    return select;
}

//��������ѡ���Ƿ�淶
int CheckInputSelect()
{
    int select;
    cin >> select;
    while(!(select >= 1 && select <= 3) )
    {
        cout << "�����������������" << endl;
        cin >> select;
    }
    return select;
}

//�������İ༶����Ƿ�淶
int CheckInputNum()
{
    int num;
    cin >> num;
    while(!(num >= 1 && num < studentNum))
    {
        cout << "�����������������" << endl;
        cin >> num;
    }
    return num;
}

//�������������Ƿ�淶
int CheckInputDay()
{
    int day;
    cin >> day;
    while(!(day >= 1  && day <= 5))
    {
        cout << "���������������������" << endl;
        cin >> day;
    }
    return day;
}

//�������Ŀ�ʱ�Ƿ�淶
int CheckInputLession()
{
    int lession;
    cin >> lession;
    while(!(lession >= 1 && lession <= 6))
    {
        cout << "�����������������" << endl;
        cin >> lession;
    }
    return lession;
}

//�������������Ƿ�淶
int CheckInputWeek()
{
    int week;
    cin >> week;
    while(!(week >= 1 && week <= 20))
    {
        cout << "�����������������" << endl;
        cin >> week;
    }
    return week;
}
