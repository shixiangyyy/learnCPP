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

	//添加元素
	for (int i = 0; i < 2; i++) mp.insert(make_pair(key[i], val[i]));
	mp.insert(pair<const char*, const char*>(key[2], val[2]));

	mp["addr"] = "中国";

	for (iter = mp.begin(); iter != mp.end(); iter++) cout << iter->first << "\t" << iter->second << endl;

	char key1[20];
	cout << "请输入按键值key查找： " << endl;
	cin.getline(key1, 20);
	for (iter = mp.begin(); iter != mp.end(); iter++)
	{
		if (strcmp(iter->first, key1) == 0)
			cout << "查找到输入的键值存在于map中：" << iter->second << endl;
	}

	//删除元素
	//第一种删除方式
	iter = mp.find("addr");
	if (iter != mp.end())
	{
		cout << iter->first << "按照键值查找出来了！" << "对应的val为：" << iter->second << endl;
		cout << "开始删除该元素：" << endl;
		mp.erase(iter->first);
	}
	//第二种删除方式
	char drop_key[20];
	char drop_val[20];
	cout << "请输入按键值删除：" << endl;
	cin.getline(drop_key, 20);
	cout << "请输入按val删除： " << endl;
	cin.getline(drop_val, 20);
	for (iter = mp.begin(); iter != mp.end(); iter++)
	{
		if (strcmp(iter->first, drop_key) == 0)
		{
			cout << iter->first << "按照键值查找出来了！" << "对应的value为：" << iter->second << endl;
			cout << "开始删除元素！" << endl;
			mp.erase(iter->first);
			break;
		}
		if (strcmp(iter->second, drop_key) == 0)
		{
			cout << iter->second << "按照value查找出来了！" << "对应的key为：" << iter->second << endl;
			cout << "开始删除元素！" << endl;
			mp.erase(iter->first);
			break;
		}
	}

	cout << "------删除元素以后的map-------" << endl;
	for (iter = mp.begin(); iter != mp.end(); iter++)
		cout << iter->first << "\t" << iter->second << endl;

	system("pause");
	return 0;
}