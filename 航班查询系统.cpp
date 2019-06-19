#include <iostream>
#include <fstream>
#include <string>

const int MAX = 100; //100 个数据
int n = 0;
using namespace std;

//时间结构体
struct TIME
{
	string year;
	string mon;
	string day;
	string hour;
	string min;
};

//飞机结构体
struct PLANE
{
	string flightOn;  //航班号
	string star;       //起点站
	string end;       //终点站
	TIME takeOff;     //起飞时间
	TIME	arrial;   //到达时间
	string rang;    //排序的判断标准
}fly[MAX];


void inPutData()
{
	char ch;
	cout << "================输入N结束输入================\n\n";
	//stringstream sstr;
	while (1)
	{
		cout << "第" << n + 1 << "个航班信息数据输入\n";
		cout << "航班号: ";
		cin >> fly[n].flightOn;
		cout << "起点站: ";
		cin >> fly[n].star;
		cout << "终点站: ";
		cin >> fly[n].end;
		cout << "起飞时间, 输入年月日时分<24小时制>: ";
		cin >> fly[n].takeOff.year;
		cin >> fly[n].takeOff.mon;
		cin >> fly[n].takeOff.day;
		cin >> fly[n].takeOff.hour;
		cin >> fly[n].takeOff.min;
		//cin >> fly[n].takeOff.year  >> fly[n].takeOff.mon >> fly[n].takeOff.day >> fly[n].takeOff.hour >> fly[n].takeOff.min;
		cout << "到达时间: ";
		cin >> fly[n].arrial.year;
		cin >> fly[n].arrial.mon;
		cin >> fly[n].arrial.day;
		cin >> fly[n].arrial.hour;
		cin >> fly[n].arrial.min;
		fly[n].rang += fly[n].takeOff.year + fly[n].takeOff.mon + fly[n].takeOff.day + fly[n].takeOff.hour + fly[n].takeOff.min; //存放一整个字符串数字
		cout << "是否继续输入<Y/N>: ";
		cin >> ch;
		n++;
		if (ch == 'N' || ch == 'n')
			break;

	}
}


void sort()
{
	ofstream fout("E:plane.txt", ios::out);
	//冒泡输出，依据年龄的信息进行排序
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (fly[j].rang > fly[j + 1].rang)
			{
				PLANE temp = fly[j];
				fly[j] = fly[j + 1];
				fly[j + 1] = temp;
			}
		}
	}

	//AC1535 jiangxi anqing 2019 13 15 14 35 2019 13 15 45 35 
	//AC1533 aqwea azcx 2019 12 11 14 35 2019 13 15 45 35


	cout << "排序结果:\n\n";
	printf("航班\t\t起点站\t\t终点站\t\t\t起飞时间\t\t\t降落时间\n");
	for (int i = 0; i < n; ++i)
	{
		cout << fly[i].flightOn << "\t\t" << fly[i].star << "  --->  " << fly[i].end << "\t\t    ";
		cout << fly[i].takeOff.year << "-" << fly[i].takeOff.mon << "-" << fly[i].takeOff.day << "-" << fly[i].takeOff.hour << ":" << fly[i].takeOff.min
			<< "\t\t    " << fly[i].arrial.year << "-" << fly[i].arrial.mon << "-" << fly[i].arrial.day << "-" << fly[i].arrial.hour << ":" << fly[i].arrial.min << endl;
		//输入到文件
		fout << fly[i].flightOn << " " << fly[i].star << " " << fly[i].end << " " << fly[i].takeOff.year << " " << fly[i].takeOff.mon << " " << fly[i].takeOff.day << " " << fly[i].takeOff.hour << " " << fly[i].takeOff.min
			<< " " << fly[i].arrial.year << " " << fly[i].arrial.mon << " " << fly[i].arrial.day << " " << fly[i].arrial.hour << " " << fly[i].arrial.min << endl;
	}
}



//航班查找
void findFlightOn(string &str)
{
	int flag = 0;
	for (int i = 0; i < n; ++i)
	{
		if (str == fly[i].flightOn)  //若是找到
		{
			cout << fly[i].flightOn << " " << fly[i].star << "--->" << fly[i].end << " ";
			cout << fly[i].takeOff.year << " " << fly[i].takeOff.mon << " " << fly[i].takeOff.day << " " << fly[i].takeOff.hour << " " << fly[i].takeOff.min
				<< " " << fly[i].arrial.year << " " << fly[i].arrial.mon << " " << fly[i].arrial.day << " " << fly[i].arrial.hour << ":" << fly[i].arrial.min;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "未找到\n";
}

//出发点查找
void findstar(string &str)
{
	int flag = 0;
	for (int i = 0; i < n; ++i)
	{
		if (str == fly[i].star)  //若是找到
		{
			cout << fly[i].flightOn << " " << fly[i].star << "--->" << fly[i].end << " ";
			cout << fly[i].takeOff.year << " " << fly[i].takeOff.mon << " " << fly[i].takeOff.day << " " << fly[i].takeOff.hour << " " << fly[i].takeOff.min
				<< " " << fly[i].arrial.year << " " << fly[i].arrial.mon << " " << fly[i].arrial.day << " " << fly[i].arrial.hour << ":" << fly[i].arrial.min;
			flag = 1;
		}
		cout << endl;
	}
	if (flag == 0)
		cout << "未找到" << endl;
}

//着陆点查找
void findend(string &str)
{
	int flag = 0;
	for (int i = 0; i < n; ++i)
	{
		if (str == fly[i].end)  //若是找到
		{
			cout << fly[i].flightOn << " " << fly[i].star << "--->" << fly[i].end << " ";
			cout << fly[i].takeOff.year << " " << fly[i].takeOff.mon << " " << fly[i].takeOff.day << " " << fly[i].takeOff.hour << " " << fly[i].takeOff.min
				<< " " << fly[i].arrial.year << " " << fly[i].arrial.mon << " " << fly[i].arrial.day << " " << fly[i].arrial.hour << ":" << fly[i].arrial.min;
			flag = 1;
		}
		cout << endl;
	}
	if (flag == 0)
		cout << "未找到" << endl;
}

//起飞时间查找
void findTakeoff(const string y, const  string m, const string d, const string h, const string min)
{
	int flag = 0;
	for (int i = 0; i < n; ++i)
	{
		if (y == fly[i].takeOff.year && m == fly[i].takeOff.mon && d == fly[i].takeOff.day &&h == fly[i].takeOff.hour && min == fly[i].takeOff.min)
		{
			cout << fly[i].flightOn << " " << fly[i].star << "--->" << fly[i].end << " ";
			cout << fly[i].takeOff.year << " " << fly[i].takeOff.mon << " " << fly[i].takeOff.day << " " << fly[i].takeOff.hour << " " << fly[i].takeOff.min
				<< " " << fly[i].arrial.year << " " << fly[i].arrial.mon << " " << fly[i].arrial.day << " " << fly[i].arrial.hour << ":" << fly[i].arrial.min;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "未找到" << endl;
}

//降落时间查找
void findArral(const string y, const string m, const string d, const string h, const string min)
{
	int flag = 0;
	for (int i = 0; i < n; ++i)
	{
		if (y == fly[i].arrial.year && m == fly[i].arrial.mon && d == fly[i].arrial.day &&h == fly[i].arrial.hour && min == fly[i].arrial.min)
		{
			cout << fly[i].flightOn << " " << fly[i].star << "--->" << fly[i].end << " ";
			cout << fly[i].takeOff.year << " " << fly[i].takeOff.mon << " " << fly[i].takeOff.day << " " << fly[i].takeOff.hour << " " << fly[i].takeOff.min
				<< " " << fly[i].arrial.year << " " << fly[i].arrial.mon << " " << fly[i].arrial.day << " " << fly[i].arrial.hour << ":" << fly[i].arrial.min;
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "未找到" << endl;
}

void find()
{
	cout << " 0:退出\n";
	cout << " 1:以航班信息查询\n";
	cout << " 2:以起点站查询\n";
	cout << " 3:以终点站查询\n";
	cout << " 4:以起飞时间查询\n";
	cout << " 5:以到达时间查询\n";
	cout << " 6:添加新的航班\n";
	cout << " 你选择: ";
	int ch;
	string str;
	cin >> ch;
	if (ch == 0)
	{
		system("cls");
		cout << "谢谢使用" << endl;
		system("pause");
		exit(0);
	}
	if (ch == 1)
	{
		int flag = 0;
		cout << "输入航班号: ";
		cin >> str;
		findFlightOn(str);
	}

	else if (ch == 2)
	{
		int flag = 0;
		cout << "输入起点站: ";
		cin >> str;
		findstar(str);
	}
	else if (ch == 3)
	{
		int flag = 0;
		cout << "输入终点站: ";
		cin >> str;
		findend(str);
	}
	else if (ch == 4)
	{
		int flag = 0;
		cout << "输入起飞时间: ";
		string y, m, d, h, min;
		cin >> y >> m >> d >> h >> min;
		findTakeoff(y, m, d, h, min);
	}
	else if (ch == 5)
	{
		int flag = 0;
		cout << "输入着陆时间: ";
		string y, m, d, h, min;
		cin >> y >> m >> d >> h >> min;
		findArral(y, m, d, h, min);
	}
	else
		cout << "输入有误!\n";
}

//从文件获取信息
void FromDisk()
{
	ifstream fin("E:plane.txt", ios::in);
	string fon;
	while (1)
	{
		fin >> fon;
		if (fin.eof())
			break;
		else
		{
			fly[n].flightOn = fon;
			fin >> fly[n].star >> fly[n].end >> fly[n].takeOff.year >> fly[n].takeOff.mon >> fly[n].takeOff.day >> fly[n].takeOff.hour >>
				fly[n].takeOff.min >> fly[n].arrial.year >> fly[n].arrial.mon >> fly[n].arrial.day >> fly[n].arrial.hour >> fly[n].arrial.min;
			cout << fly[n].flightOn << " " << fly[n].star << " " << fly[n].end << " ";
			cout << fly[n].takeOff.year << " " << fly[n].takeOff.mon << " " << fly[n].takeOff.day << " " << fly[n].takeOff.hour << " " << fly[n].takeOff.min
				<< " " << fly[n].arrial.year << " " << fly[n].arrial.mon << " " << fly[n].arrial.day << " " << fly[n].arrial.hour << ":" << fly[n].arrial.min << endl;
			n++;
		}
	}
	fin.close();
}
int main()
{
	ifstream fin("E:plane.txt", ios::in);
	if ( !fin )    //如果是第一次使用该程序
	{
		cout << "你是第一次使用" << endl;
		inPutData();
	}
	else
	{
		cout << "欢迎第二次使用" << endl;
		FromDisk();
	}
	sort();
	while (1)
	{
		find();
		system("pause");
		system("cls");
	}
}
