#include <iostream>
#include <string>
#include "Student.h"
using namespace std;

//����������ѯ�༶���
void selectNoFromName()
{
    string name;
    cout << "��������Ҫ��ѯ������" << endl;
    cin >> name;
    for(int i = 1; i < studentNum; i++)
    {
        if(stu.student[i].name == name)
        {
            showPersion(i);
            return;
        }
    }
    cout << "���޴���" << endl;
}

//����ѧ�Ų�ѯ�༶���
void selectNoFromID()
{
    long long id;
    cout << "��������Ҫ��ѯ��ѧ��" << endl;
    cin >> id;
    for(int i = 1; i < studentNum; i++)
    {
        if(stu.student[i].id == id)
        {
            showPersion(i);
            return;
        }
    }
    cout << "���޴���" << endl;
}

//һ���˵�
void Level1Menu()
{
    cout << "��ѡ����Ҫ�Ĺ���" << endl;
    cout << "1.�༶��Ա��Ϣ����" << endl;
    cout << "2.�޸Ŀ�����Ϣ" << endl;
    cout << "3.��ѯ������Ϣ" << endl;
    cout << "4.��ѯ�༶���" << endl;
    cout << "5.ˢ��ÿ��ѧ��ÿһ�ܵĳ�����" << endl;
    cout << "0.�˳�" << endl;
}

//�����˵���һ��ѡ��
void Level2Menu1()
{
    cout << "��ѡ����Ҫ�Ĺ���" << endl;
    cout << "1.���İ༶��ԱȨ��" << endl;
    cout << "2.ɾ��ĳ���༶��Ա" << endl;
    cout << "3.�޸�ĳ���༶��Ա��Ϣ" << endl;
    cout << "4.���ĳ���༶��Ա��Ϣ" << endl;
    cout << "5.�鿴���г�Ա��Ϣ" << endl;
    cout << "0.������һ��" << endl;
}

//�����˵��ڶ���ѡ��
void Level2Menu2()
{
    cout << "��ѡ����Ҫ�Ĺ���" << endl;
    cout << "1.��ӿ�����Ϣ" << endl;
    cout << "2.�޸Ŀ�����Ϣ" << endl;
    cout << "3.ɾ��ĳ��ѧ�����еĿ�����Ϣ" << endl;
    cout << "4.ɾ��ĳ��ѧ��ĳһ�ܵĿ�����Ϣ" << endl;
    cout << "5.ɾ��ĳ��ѧ��ĳһ�ܵ�ĳһ�쿼����Ϣ" << endl;
    cout << "6.ɾ��ĳ��ѧ��ĳһ�ܵ�ĳһ���ĳһ�ڿο�����Ϣ" << endl;
    cout << "0.������һ��" << endl;
}

//�����˵�������ѡ��
void Level2Menu3()
{
    cout << "��ѡ����Ҫ�Ĺ���" << endl;
    cout << "1.��ʾһ����Ա�����п�����Ϣ" << endl;
    cout << "2.��ʾһ����Ա�ض��ܵĿ�����Ϣ" << endl;
    cout << "3.��ʾһ����Ա�ض���Ŀ�����Ϣ" << endl;
    cout << "4.��ʾһ����Ա�ض���ʱ�Ŀ�����Ϣ" << endl;
    cout << "5.��ѯĳһ��ͬѧ�����ܵĿ�����" << endl;
    cout << "6.��ѯȫ��ѧ��ĳ�ܳ�����" << endl;
    cout << "0.������һ��" << endl;
}

//�����˵����ĸ�ѡ��
void Level2Menu4()
{
    cout << "��ѡ����Ҫ�Ĺ���" << endl;
    cout << "1.����������ѯ�༶���" << endl;
    cout << "2.����ѧ�Ų�ѯ�༶���" << endl;
    cout << "0.������һ��" << endl;
}

void Administrator()
{
    int select1 = 0, select2 = 0;
    cout << "��ϵͳ��ʹ��ѧ���༶�������ѯ������֪���༶��ţ����õ��ĵ��ѯ" << endl;
    while(true)
    {
        cout << endl;
        Level1Menu();
        cin >> select1;
        while( 0 < select1 && select1 > 5)
        {
            cout << "�����������������" << endl;
            cin >> select1;
        }
        switch(select1)
        {
            case 0:
                return;
            case 1:
                while(true)
                {
                    cout << endl;
                    Level2Menu1();
                    cin >> select2;
                    while( 0 < select2 && select2 > 5)
                    {
                        cout << "�����������������" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            modifyAuthority();
                            break;
                        case 2:
                            deleteMember();
                            break;
                        case 3:
                            modifyInformation();
                            break;
                        case 4:
                            addInformation();
                            break;
                        case 5:
                            showAllMember();
                            break;
                    }
                }
                break;
            case 2:
                while(true)
                {
                    RateAllWeek();
                    cout << endl;
                    Level2Menu2();
                    cin >> select2;
                    while( 0 < select2 && select2 > 6)
                    {
                        cout << "�����������������" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            addAttendance();
                            break;
                        case 2:
                            modifyAttendance();
                            break;
                        case 3:
                            deleteAttendanceID();
                            break;
                        case 4:
                            deleteAttendanceWeek();
                            break;
                        case 5:
                            deleteAttendanceDay();
                            break;
                        case 6:
                            deleteAttendanceLession();
                            break;
                    }
                }
                break;
            case 3:
                while(true)
                {
                    cout << endl;
                    Level2Menu3();
                    cin >> select2;
                    while( 0 < select2 && select2 > 6)
                    {
                        cout << "�����������������" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            showOneALL();
                            break;
                        case 2:
                            showOneWeek();
                            break;
                        case 3:
                            showOneDay();
                            break;
                        case 4:
                            showOneLession();
                            break;
                        case 5:
                            showOneRate();
                            break;
                        case 6:
                            showWeekRateAll();
                            break;
                    }
                }
                break;
            case 4:
                while(true)
                {
                    cout << endl;
                    Level2Menu4();
                    cin >> select2;
                    while( 0 < select2 && select2 > 2)
                    {
                        cout << "�����������������" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            selectNoFromName();
                            break;
                        case 2:
                            selectNoFromID();
                            break;
                    }
                }
                break;
            case 5:
                RateAllWeek();
                break;
        }
    }
}


//һ���˵�
void CLevel1Menu()
{
    cout << "��ѡ����Ҫ�Ĺ���" << endl;
    cout << "1.�鿴���г�Ա��Ϣ" << endl;
    cout << "2.�޸Ŀ�����Ϣ" << endl;
    cout << "3.��ѯ������Ϣ" << endl;
    cout << "4.��ѯ�༶���" << endl;
    cout << "5.ˢ��ÿ��ѧ��ÿһ�ܵĳ�����" << endl;
    cout << "0.�˳�" << endl;
}

void Committee()
{
    int select1 = 0, select2 = 0;
    cout << "��ϵͳ��ʹ��ѧ���༶�������ѯ������֪���༶��ţ����õ��ĵ��ѯ" << endl;
    while(true)
    {
        cout << endl;
        CLevel1Menu();
        cin >> select1;
        while( 0 < select1 && select1 > 5)
        {
            cout << "�����������������" << endl;
            cin >> select1;
        }
        switch(select1)
        {
            case 0:
                return;
            case 1:
                showAllMember();
                break;
            case 2:
                while(true)
                {
                    RateAllWeek();
                    cout << endl;
                    Level2Menu2();
                    cin >> select2;
                    while( 0 < select2 && select2 > 6)
                    {
                        cout << "�����������������" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            addAttendance();
                            break;
                        case 2:
                            modifyAttendance();
                            break;
                        case 3:
                            deleteAttendanceID();
                            break;
                        case 4:
                            deleteAttendanceWeek();
                            break;
                        case 5:
                            deleteAttendanceDay();
                            break;
                        case 6:
                            deleteAttendanceLession();
                            break;
                    }
                }
                break;
            case 3:
                while(true)
                {
                    cout << endl;
                    Level2Menu3();
                    cin >> select2;
                    while( 0 < select2 && select2 > 6)
                    {
                        cout << "�����������������" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            showOneALL();
                            break;
                        case 2:
                            showOneWeek();
                            break;
                        case 3:
                            showOneDay();
                            break;
                        case 4:
                            showOneLession();
                            break;
                        case 5:
                            showOneRate();
                            break;
                        case 6:
                            showWeekRateAll();
                            break;
                    }
                }

                break;
            case 4:
                while(true)
                {
                    cout << endl;
                    Level2Menu4();
                    cin >> select2;
                    while( 0 < select2 && select2 > 2)
                    {
                        cout << "�����������������" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            selectNoFromName();
                            break;
                        case 2:
                            selectNoFromID();
                            break;
                    }
                }
                break;
            case 5:
                RateAllWeek();
                break;
        }
    }
}

void Student()
{
    int select1 = 0, select2 = 0;
    cout << "��ϵͳ��ʹ��ѧ���༶�������ѯ������֪���༶��ţ����õڶ����ѯ" << endl;
    cout << "��ѡ����Ҫ�Ĺ���" << endl;
    cout << "1.��ѯ������Ϣ" << endl;
    cout << "2.��ѯ�༶���" << endl;
    cout << "0.�˳�" << endl;
    while(true)
    {
        cin >> select1;
        while( 0 < select1 && select1 > 2)
        {
            cout << "�����������������" << endl;
            cin >> select1;
        }
        if(select1 == 0)
            return;
        switch(select1)
        {
            case 1:
            while(true)
            {
                cout << endl;
                Level2Menu3();
                cin >> select2;
                while( 0 < select2 && select2 > 6)
                {
                    cout << "�����������������" << endl;
                    cin >> select2;
                }
                if(select2 == 0)
                {
                    Level1Menu();
                    break;
                }
                switch(select2)
                {
                    case 1:
                        showOneALL();
                        break;
                    case 2:
                        showOneWeek();
                        break;
                    case 3:
                        showOneDay();
                        break;
                    case 4:
                        showOneLession();
                        break;
                    case 5:
                        showOneRate();
                        break;
                    case 6:
                        showWeekRateAll();
                        break;
                }
            }
            break;
            case 2:
                while(true)
                {
                    cout << endl;
                    Level2Menu4();
                    cin >> select2;
                    while( 0 < select2 && select2 > 2)
                    {
                        cout << "�����������������" << endl;
                        cin >> select2;
                    }
                    if(select2 == 0)
                    {
                        Level1Menu();
                        break;
                    }
                    switch(select2)
                    {
                        case 1:
                            selectNoFromName();
                            break;
                        case 2:
                            selectNoFromID();
                            break;
                    }
                }
                break;
        }
    }
}