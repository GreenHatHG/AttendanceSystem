#include <iostream>
#include "Student.h"
using namespace std;

//���İ༶��ԱȨ��
void modifyAuthority()
{
    int num = check();
    if(num == -1)
        return;
    cout << stu.student[num].name << "��Ȩ��Ϊ:\t";
    if(stu.student[num].permission == 1)
        cout << "��ί";
    else if(stu.student[num].permission == 2)
        cout << "����Ա";
    else
        cout << "�༶��Ա";

    cout << endl << "�������Ӧ�����֣��Դ�����Ҫ���ĵ�Ȩ��" << endl;
    cout << "0���༶��Ա 1����ί��2������Ա" << endl;
    stu.student[num].permission = CheckInputpermission();
    cout << "�޸ĳɹ�" << endl;
}

//ɾ��ĳ���༶��Ա
void deleteMember()
{
    int num = check();
    if(num == -1)
        return;
    stu.student[num].name = "";
    stu.student[num].number = -1;
    cout << "�޸ĳɹ�" << endl;
    stu.stuN--;
}

//�޸�ĳ���༶��Ա��Ϣ
void modifyInformation()
{
    int num = check();
    if(num == -1)
        return;
    showPersion(num);
    cout << "��������Ҫ�޸ĵ���Ϣ" << endl;
    cout << "1.����" << endl;
    cout << "2.ѧ��" << endl;
    int select = CheckInputUpdate();

    if(select == 1)
    {
        cout << "�������޸ĺ������" << endl;
        cin >> stu.student[num].name;
    }
    else
    {
        cout << "�������޸ĺ��ѧ��" << endl;
        cin >> stu.student[num].id;
        while(isIncludeID(stu.student[num].id, num))
        {
            cout << "ѧ���Ѵ��ڣ����߲��淶������������" << endl;
            cin >> stu.student[num].id;
        }
    }
    cout << "�޸ĳɹ�" << endl;
    cout << "�޸ĺ����Ϣ����" << endl;
    showPersion(num);
}

//���ĳ���༶��Ա��Ϣ
void addInformation()
{
    cout << "������Ҫ��ӵ�ѧ���İ༶���" << endl;
    int num = CheckInputNum();
    if(isInclude(num))
    {
        cout << "����ϵͳ�����д���" << endl;
        return;
    }
    if(stu.stuN == studentNum)
    {
        cout << "�洢��������" << endl;
        return;
    }
    stu.student[num].number = num;
    cout << "��������Ҫ��ӵ���Ϣ" << endl;
    cout << "1.����" << endl;
    cin >> stu.student[num].name;
    cout << "2.ѧ��" << endl;
    cin >> stu.student[num].id;
    while(isIncludeID(stu.student[num].id, num))
    {
        cout << "ѧ���Ѵ��ڣ����߲��淶������������" << endl;
        cin >> stu.student[num].id;
    }
    cout << "3.Ȩ��" << endl;
    cout << "0���༶��Ա 1����ί��2������Ա" << endl;
    stu.student[num].permission = CheckInputpermission();
    cout << "��Ӻ����Ϣ����" << endl;
    showPersion(num);
    stu.stuN++;
}

