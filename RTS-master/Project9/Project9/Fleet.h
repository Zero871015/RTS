#pragma once
#include "Shell.h"
#include "Board.h"
using namespace System::Drawing;

ref class Fleet
{
public:
	Fleet();
	Fleet(System::String ^ name, System::Drawing::PointF ^ location);
	void Draw(Graphics^ g);
	void Move();
	bool Fire(System::Collections::Generic::List<Shell^>^ list, System::String ^,PointF ^ location);
	int whereAmI();
	void setMove(float speed, float angle);
	float getSheelSpeed();
	void setName(System::String ^);
	PointF ^ getLocation();
	void setHP(int);
	int getHP();
	void UpdataCD();
	bool Defense(System::String ^ shellName, System::Collections::Generic::List<Shell^>^ list);
	void SetDefenseCD();
protected:
	System::String ^ name;	//��ĥ�W�r
	int type;	//��ĥ����(������~�ӥi�ಾ��)
	System::Drawing::PointF ^ location;	//�ثe��m

	int HP;	//��ĥ��q
	float maxSpeed;	//�̤j���ʳt��
	float speed;	//�ثe���ʳt��
	float angle;	//�ثe���ʨ���
	int maxAttackRange;	//��ĥ�̤j�����Z��
	int attackCD;	//�����N�o
	int attackCDNow;	//�����N�o�p��
	int maxDefenseRange;	//��ĥ�̤j���m�Z��
	int defenseCD;	//���m�N�o
	int defenseCDNow;	//���m�N�o�p��
	int damage;	//�o�g�����u�ˮ`
	float sheelSpeed;	//�o�g�����u�t��
};
