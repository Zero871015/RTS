#include "Fleet.h"
#include <Cmath>


Fleet::Fleet()
{
	this->name = "GG";
	this->location = gcnew PointF(2, 2);
	this->maxSpeed = (float)0.1;
	this->shellSpeed = (float)0.1;
	this->attackCDNow = 0;
	this->defenseCDNow = 0;
	this->isDrawBig = false;
	this->type = 0;
	this->specialCD = 60;
	this->specialCDNow = 0;
}

Fleet::Fleet(System::String ^ name, System::Drawing::PointF ^ location)
{
	this->name = name;
	this->location = gcnew PointF(location->X,location->Y);
	this->maxSpeed = (float)0.1;
	this->shellSpeed = (float)0.1;
	this->attackCDNow = 0;
	this->defenseCDNow = 0;
	this->isDrawBig = false;
	this->type = 0;
	this->specialCD = 60;
	this->specialCDNow = 0;
}

void Fleet::Draw(Graphics ^ g, System::Drawing::Color color)
{
	float X = this->location->X*20;
	float Y = this->location->Y*20;
	float size = 10;
	//�e�T����
	array<PointF>^ curvePoints = { PointF(X,Y - size),
		PointF(X - size / 2 * sqrtf(3),Y + size / 2) ,
		PointF(X + size / 2 * sqrtf(3),Y + size / 2) };
	g->FillPolygon(gcnew SolidBrush(color), curvePoints);

	//�e�W�r
	g->DrawString(this->name,
		gcnew Font("Arial", 12),
		Brushes::Black,
		X + 10,
		Y - 20);
}

void Fleet::DrawBig(Graphics ^ g)
{
	float X = this->location->X * 20;
	float Y = this->location->Y * 20;
	float size = 13;
	//�e�T����
	array<PointF>^ curvePoints = { PointF(X,Y - size),
		PointF(X - size / 2 * sqrtf(3),Y + size / 2) ,
		PointF(X + size / 2 * sqrtf(3),Y + size / 2) };
	g->FillPolygon(gcnew SolidBrush(Color::Red), curvePoints);
}

void Fleet::Move()
{
	//�p��X-Y���q
	float trueAngle=angle/180* (float)3.14159265;
	this->location->X += speed * cosf(trueAngle);
	this->location->Y -= speed * sinf(trueAngle);
	
	//�ثe�b���
	if (whereAmI() == WALL)
	{
		this->location->X -= speed * cosf(trueAngle);
		this->location->Y += speed * sinf(trueAngle);
		System::Diagnostics::Debug::WriteLine("����");
		this->speed = 0;
		this->angle = 0;
	}
	else if (whereAmI() == SEA)
	{

	}
	else if (whereAmI() == STORM)
	{
		this->HP = 0;
	}
}

bool Fleet::Fire(System::Collections::Generic::List<Shell^>^ list, System::String ^ name, PointF ^ location)
{
	//�s�W���u�A�Z�������n�^��false(�٨S��)
	if (this->attackCDNow <= 0)
	{
		if ((this->location->X - location->X)*(this->location->X - location->X) +
			(this->location->Y - location->Y)*(this->location->Y - location->Y) >
			this->maxAttackRange*this->maxAttackRange)
		{
			this->attackCDNow = this->attackCD;
			System::Diagnostics::Debug::WriteLine("���b�����d��");
			return false;
		}
		Shell ^temp = gcnew Shell(name, shellSpeed,this->damage, this->location, location);
		list->Add(temp);
		this->attackCDNow = this->attackCD;
		return true;
	}
	else
	{
		System::Diagnostics::Debug::WriteLine("�����N�o��");
		return false;
	}
}

int Fleet::whereAmI()
{
	//�^�ǥثe��ĥ�b����
	return Board::getBoard(this->location->X, this->location->Y);
}

bool Fleet::setMove(float speed, float angle)
{
	//�]�w�t�׹L��
	speed /= 60;
	if (abs(speed) > this->maxSpeed)
	{
		return false;
	}
	if (angle < 0 || angle>359)
	{
		return false;
	}
	this->speed = speed;
	this->angle = angle;
	return true;
}

float Fleet::getShellSpeed()
{
	return this->shellSpeed;
}

void Fleet::setName(System::String ^ name)
{
	this->name = name;
}

PointF ^ Fleet::getLocation()
{
	return this->location;
}

void Fleet::setHP(int hp)
{
	this->HP = hp;
}

int Fleet::getHP()
{
	return this->HP;
}

System::String ^ Fleet::getName()
{
	return this->name;
}

System::String ^ Fleet::showAttackCD()
{
	System::String ^ str;
	str = (this->attackCDNow >= 0) ? (this->attackCD - this->attackCDNow).ToString() : this->attackCD.ToString();
	str += " / " + this->attackCD.ToString();
	return str;
}

System::String ^ Fleet::showDefenseCD()
{
	System::String ^ str;
	str = (this->defenseCDNow >= 0) ? (this->defenseCD - this->defenseCDNow).ToString() : this->defenseCD.ToString();
	str += " / " + this->defenseCD.ToString();
	return str;
}

System::String ^ Fleet::showSpecialCD()
{
	System::String ^ str;
	str = (this->specialCDNow >= 0) ? (this->specialCD - this->specialCDNow).ToString() : this->specialCD.ToString();
	str += " / " + this->specialCD.ToString();
	return str;
}

void Fleet::UpdataCD()
{
	this->attackCDNow--;
	this->defenseCDNow--;
	this->specialCDNow--;
}

bool Fleet::Defense(System::String ^ shellName, System::Collections::Generic::List<Shell^>^ list)
{
	if (this->defenseCDNow <= 0)
	{
		for each (auto var in list)
		{
			if (var->getName() == shellName)
			{
				list->Remove(var);
				return true;
			}
		}
	}
	else
	{
		System::Diagnostics::Debug::WriteLine("���m�N�o��");
	}
	return false;
}

void Fleet::SetDefenseCD()
{
	this->defenseCDNow = this->defenseCD;
}

int Fleet::whoAmI()
{
	//1=CV
	//2=BB
	//3=CG
	//4=DD
	//���ӧ��enum�A���L���i�F
	return this->type;
}

bool Fleet::specialAttack(System::Collections::Generic::List<Shell^>^ list, float angle)
{
	return false;
}

bool Fleet::specialAttack()
{
	return false;
}
