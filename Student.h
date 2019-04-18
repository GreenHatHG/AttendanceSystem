#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H

#include <string>
using namespace std;

struct Lession
{
    //���������
    //1�����ڣ�2���ٵ���3�����Σ�4�����
    int attendance = -1;
    //������Ϣ�Ƿ���Ч�����������Ϣ��ɾ��������ڿο�����Ϣ��Ч
    bool effectiveness = false;
};

struct Day //������Ϣ�ṹ��
{
    Lession lession[10];

    //������Ϣ�Ƿ���Ч�����������Ϣ��ɾ���������쿼����Ϣ��Ч
    bool effectiveness = false;
};

struct Week //һ����7��
{
    Day day[10];
    double rate = 0.0; //������
    //������Ϣ�Ƿ���Ч�����������Ϣ��ɾ���������ܿ�����Ϣ��Ч
    bool effectiveness = false;
};

struct Student //ѧ��������Ϣ�ṹ��
{
    int number = -1; //�������
    long long id; //ѧ��
    string name = ""; //����
    //����ԱȨ�ޣ�
    //0���༶��Ա 1����ί��2������Ա
    int permission = 0;
    Week week[20];
};


//����ṹ��
typedef struct
{
    int week = -1;
    double rate = 0.0;
}Rate;

typedef struct
{
    string name = "";
    double rate = 0.0;
}stuRate;

extern int studentNum; //���ڱ�洢���ѧ������
typedef struct //���Ա�洢������Ϣ
{
    Student student[71];
    int stuN; //���Ա�ǰ����
}Stu;

extern Stu stu; //����ȫ�ֱ���

/*
 * �����ı���Ϣ��ϵͳ��
 */
//����ĿAttendanceInformation�ļ����е���ѧ��������Ϣ��ϵͳ��
void loadAttendanceInformation();

//����Ŀ��Ŀ¼�е���ѧ����Ϣ��ϵͳ��
void loadStudentInformation();

/*
 * ���淶��
 */
//��������ѡ���Ƿ�淶
int CheckInputpermission();

//��������ѡ���Ƿ�淶
int CheckInputUpdate();

//��������ѡ���Ƿ�淶
int CheckInputSelect();

//�������������Ƿ�淶
int CheckInputWeek();

//�������Ŀ�ʱ�Ƿ�淶
int CheckInputLession();

//�������������Ƿ�淶
int CheckInputDay();

//�������İ༶����Ƿ�淶
int CheckInputNum();

//��ѯѧ���Ƿ��Ѿ�������ϵͳ��
bool isIncludeID(long long ID, int num);

//������Ų��Ҽ�������Ƿ����
int check();

//����ĳ��ѧ���Ƿ��Ѿ��Ǽ����˿��ڱ�����
bool isInclude(const int num);

/*
 * �������
 */
//ѡ�������㷨
void SelectSort(Rate* arr, int len);
void selectSort(stuRate* arr, int len);

/*
 * ��ѯ������Ϣ
 */
//��ʾһ����Ա�ض��ܵĿ�����Ϣ
void showOneWeek();

//��ʾһ����Ա�ض����ڵĿ�����Ϣ
void showOneDay();

//��ʾһ����Ա�ض�ĳһ�ڿεĿ�����Ϣ
void showOneLession();

//��ʾһ����Ա�����п�����Ϣ
void showOneALL();

//��ѯȫ��ѧ��ĳ�ܳ�����
void showWeekRateAll();

//��ѯĳһ��ͬѧ�����ܵĿ�����
void showOneRate();

/*
 * ��ѯ���޸İ༶��Ա��Ϣ
 */
//��ʾĳ����Ա�İ༶��ţ�������ѧ��
void showPersion(const int num);

//��ʾϵͳ�������г�Ա����Ϣ
void showAllMember();

//�޸�ĳ���༶��Ա��Ϣ
void modifyInformation();

//ɾ��ĳ���༶��Ա
void deleteMember();

//���ĳ���༶��Ա��Ϣ
void addInformation();

//���İ༶��ԱȨ��
void modifyAuthority();

/*
 * �޸Ŀ�����Ϣ
 */
//���ѧ���Ŀ�����Ϣ
void addAttendance();

//�޸�ѧ���Ŀ�����Ϣ
void modifyAttendance();

//ɾ��ĳ��ѧ�������п�����Ϣ
void deleteAttendanceID();

//ɾ��ĳ��ѧ��ĳһ�ܵĿ�����Ϣ
void deleteAttendanceWeek();

//ɾ��ĳ��ѧ��ĳһ�ܵ�ĳһ�쿼����Ϣ
void deleteAttendanceDay();

//ɾ��ĳ��ѧ��ĳһ�ܵ�ĳһ���ĳһ�ڿο�����Ϣ
void deleteAttendanceLession();

//ˢ��ÿ��ѧ��ÿһ�ܵĳ�����
void RateAllWeek();

/*
 * ��ʾҳ��
 */
//��ʾ����Ա����ҳ��
void Administrator();

//��ί
void Committee();

//�༶��Ա
void Student();

#endif
