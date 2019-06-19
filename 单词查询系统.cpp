#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//要查到的单词结构体，初始化的时候都为-1，表示没有数据
struct
{
	string name;
	int num;
	int line;
}Baseword[6] = { {"int",0,-1,},{"char",0,-1}, {"for",0,-1},{"while",0,-1},{"return",0,-1},{"struct",0,-1} };

//查找该单词是否为要统计的
void FindBaseword(string name, int n)
{
	for (int i = 0; i < 6; ++i)
	{
		if (name == Baseword[i].name)
		{
			Baseword[i].num++;
			Baseword[i].line = n;
		}
	}
}

//先从文本获取单词数据
void FormDisk(vector<string> w, string filename)
{
	ifstream fin(filename, ios::in);
	char word[1000];   //一行不超过1000个字符数目

	int n = 1;
	while (fin.getline(word, 1000))
	{
		string temp;
		for (int i = 0; word[i] != '\0'; ++i)
		{
			char ch = word[i];
			if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == ' ')
			{
				temp += ch;
				if (ch == ' ')
				{
					temp.erase(temp.size()-1, 1);         //去掉单词的空格
					FindBaseword(temp, n);
					temp.clear();
				}
			}
		}
		n++;
	}
	fin.close();
}


void InitSize(vector<string> word, const int n)
{
	word.reserve(n);  //初始初始单词个数，如果多了会自动增加
}

void PrintWord()
{
	cout << endl << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << Baseword[i].name << "个数: " << Baseword[i].num << " 行号:" << Baseword[i].line << endl;
	}
}

void FromKeyBoard(vector<string> word)
{
	cout << "输入文本，/换行 #结束" << endl;
	string temp;
	word.push_back("/");            //在顺序表最前面插入一个/，作为该段的标识
	while (cin >> temp && temp != "#")
	{
		if (temp != " ")
		{
			word.push_back(temp);
		}

	}
	int line = 0;
	while (word.empty() != true) //当顺序表不为空的时候,执行循环
	{
		if (word.back() == "/")   	       //如果读取到了 / 表明为一行
			line++;                             //此时行数加1
		FindBaseword(word.back(),line);  //判断该单词是否为所要找的单词
		word.pop_back();                            //完毕之后再将该单词去除。
	}
}

void Menu()
{
	vector<string> word;
	InitSize(word, 3000);  //顺序表的初始化，三千个单词量
	cout << "1：从文本获取" << endl;
	cout << "2: 从键盘输入" << endl;
	int c;
	cout << "你选择：";
	cin >> c;
	if (c == 1)
	{
		string filename;
		cout << "输入文件位置: ";
		cin >> filename;
		FormDisk(word, filename);        //把从单词表的
	}
	else
	{
		FromKeyBoard(word);
	}
}
int main()
{
	Menu();
	PrintWord();
	return 0;
}
