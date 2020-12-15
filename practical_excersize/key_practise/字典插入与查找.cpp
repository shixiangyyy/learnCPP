#include <iostream>
#include <map>
#include <cstring>
using namespace std;

int main()
{
	map<const char*, const char*> mp;
	map<const char*, const char*>::iterator iter;

	const char* key[3] = { "img", "system", "ip" };
	const char* val[3] = { "d:/a.img", "win7", "193.68.6.3" };

	//���Ԫ��
	for (int i = 0; i < 2; i++) mp.insert(make_pair(key[i], val[i]));
	mp.insert(pair<const char*, const char*>(key[2], val[2]));

	mp["addr"] = "�й�";

	for (iter = mp.begin(); iter != mp.end(); iter++) cout << iter->first << "\t" << iter->second << endl;

	char key1[20];
	cout << "�����밴��ֵkey���ң� " << endl;
	cin.getline(key1, 20);
	for (iter = mp.begin(); iter != mp.end(); iter++)
	{
		if (strcmp(iter->first, key1) == 0)
			cout << "���ҵ�����ļ�ֵ������map�У�" << iter->second << endl;
	}

	//ɾ��Ԫ��
	//��һ��ɾ����ʽ
	iter = mp.find("addr");
	if (iter != mp.end())
	{
		cout << iter->first << "���ռ�ֵ���ҳ����ˣ�" << "��Ӧ��valΪ��" << iter->second << endl;
		cout << "��ʼɾ����Ԫ�أ�" << endl;
		mp.erase(iter->first);
	}
	//�ڶ���ɾ����ʽ
	char drop_key[20];
	char drop_val[20];
	cout << "�����밴��ֵɾ����" << endl;
	cin.getline(drop_key, 20);
	cout << "�����밴valɾ���� " << endl;
	cin.getline(drop_val, 20);
	for (iter = mp.begin(); iter != mp.end(); iter++)
	{
		if (strcmp(iter->first, drop_key) == 0)
		{
			cout << iter->first << "���ռ�ֵ���ҳ����ˣ�" << "��Ӧ��valueΪ��" << iter->second << endl;
			cout << "��ʼɾ��Ԫ�أ�" << endl;
			mp.erase(iter->first);
			break;
		}
		if (strcmp(iter->second, drop_key) == 0)
		{
			cout << iter->second << "����value���ҳ����ˣ�" << "��Ӧ��keyΪ��" << iter->second << endl;
			cout << "��ʼɾ��Ԫ�أ�" << endl;
			mp.erase(iter->first);
			break;
		}
	}

	cout << "------ɾ��Ԫ���Ժ��map-------" << endl;
	for (iter = mp.begin(); iter != mp.end(); iter++)
		cout << iter->first << "\t" << iter->second << endl;

	system("pause");
	return 0;
}