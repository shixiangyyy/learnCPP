#include <iostream>
using namespace std;

class Base
{
public:
	Base(){}
	virtual ~Base(){}
	virtual void changeAttribute() = 0;
	static Base* create(int id); //���������鹹�캯���Ĺ��ܣ�����ʱ��̬�����������ж�ʵ�����ľ�������
	virtual Base* Clone() = 0;
};

class Derived1 :public Base
{
public:
	Derived1()
	{
		cout << "Derived1 created!" << endl;
	}
	Derived1(const Derived1& rhs)
	{
		cout << "Derived1 created by deep copy!" << endl;
	}
	
	~Derived1()
	{
		cout << "Derived1 destroyed!" << endl;
	}
	void changeAttribute()
	{
		cout << "Derived1 attributes changed." << endl;
	}
	Base* Clone()
	{
		return new Derived1(*this);
	}
};

class Derived2 :public Base
{
public:
	Derived2()
	{
		cout << "Derived2 created!" << endl;
	}
	Derived2(const Derived2& rhs)
	{
		cout << "Derived2 created by deep copy!" << endl;
	}

	~Derived2()
	{
		cout << "Derived2 destroyed!" << endl;
	}
	void changeAttribute()
	{
		cout << "Derived2 attributes changed." << endl;
	}
	Base* Clone()
	{
		return new Derived2(*this);
	}
};

class Derived3 :public Base
{
public:
	Derived3()
	{
		cout << "Derived3 created!" << endl;
	}
	Derived3(const Derived3& rhs)
	{
		cout << "Derived3 created by deep copy!" << endl;
	}

	~Derived3()
	{
		cout << "Derived3 destroyed!" << endl;
	}
	void changeAttribute()
	{
		cout << "Derived3 attributes changed." << endl;
	}
	Base* Clone()
	{
		return new Derived3(*this);
	}
};

//���������鹹�캯�����ܵ�����ʱ��̬�ж�����
//�����������ݣ�ȷ�����崴���Ķ�����������������
Base* Base::create(int id)
{
	if (id == 1)
	{
		return new Derived1;
	}
	else if (id == 2)
	{
		return new Derived2;
	}
	else
	{
		return new Derived3;
	}
}

class User
{
public:
	User() :pBase(0)
	{
		int input;
		cout << "Enter ID (1,2,or 3):";
		cin >> input;
		while (input != 1 && input != 2 && input != 3)
		{
			cout << "Enter ID (1,2,or  only):";
			cin >> input;
		}
		pBase = Base::create(input);
	};

	virtual ~User()
	{
		if (pBase)
		{
			delete pBase;
			pBase = 0;
		}
	}

	void Action()
	{
		//���Ƶ�ǰ����
		Base* pNewBase = pBase->Clone();
		pNewBase->changeAttribute();
		delete pNewBase;
	}
private:
	Base* pBase;
};

int main()
{
	User* user = new User();
	user->Action();

	delete user;
	system("pause");
	return 0;
}