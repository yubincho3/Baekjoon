/*
Brainfuck 인티프리터를 구현하는 문제다.
메모리의 자료형은 0~255까지 저장 가능해야 한다.
또한, 255에서 1을 더해서 0으로 오버플로우가 되야 하고,
0에서 1을 빼서 255로 언더플로우가 되야 한다.
이는 0~255까지의 범위를 가지는 unsigned char 자료형을 사용하면 된다.
코드를 실행하기 전에 대괄호 쌍이 맞는지 확인해야 한다.
또, 대괄호 쌍의 인덱스를 저장하여 적절하게 인덱스를 옮길 수 있어야 한다.
반복문을 이용해 구현해도 되지만, 코드 실행 전에 map(파이썬에서는 dictionary)에
인덱스 쌍을 저장해 놓으면 간편하다. 
*/
#include <bits/stdc++.h>
using byte = unsigned char;
using namespace std;

stack<int> lbracket;
map<int, int> lpair;
map<int, int> rpair;
string result;
byte mem[32769];
byte *ptr = mem;
int idx;

string cmd, input;
int t;

void Execute(void)
{
	do
	{
		switch (cmd[idx])
		{
			case '>':
				if (ptr == mem + 32767)
					ptr = mem;
				else
					ptr++;
				break;
			case '<':
				if (ptr == mem)
					ptr += 32767;
				else
					ptr--;
				break;
			case '+':
				++*ptr;
				break;
			case '-':
				--*ptr;
				break;
			case '.':
				result.push_back(*ptr);
				break;
			case '[':
				if (*ptr == 0)
					idx = lpair[idx];
				break;
			case ']':
				if (*ptr != 0)
					idx = rpair[idx];
				break;
		}
	} while (cmd[++idx]);
}

void Initialize(void)
{
	memset(mem, 0, sizeof(mem));
	lpair.clear();
	rpair.clear();
	result.clear();
	cmd.clear();
	ptr = mem;
	idx = 0;
}

int main(void)
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	cin >> t;
	cin.ignore();
	
	for (int i = 1; i <= t; i++)
	{
		while (true)
		{
			getline(cin, input);
			
			if (input == "end")
				break;
			
			size_t finded = input.find("%");
			if (finded != string::npos)
				cmd += input.substr(0, finded);
			else
				cmd += input;
		}
		
		int cnt = 0;
		for (int i = 0; i < cmd.length(); i++)
		{
			if (cmd[i] == '[')
				cnt++;
			else if(cmd[i] == ']')
				cnt--;
		}
		
		if (cnt == 0)
		{
			for (int i = 0; i < cmd.length(); i++)
			{
				if (cmd[i] == '[')
					lbracket.push(i);
				else if (cmd[i] == ']')
				{
					int left = lbracket.top();
					lbracket.pop();
					
					lpair.insert({left, i});
					rpair.insert({i, left});
				}
			}
			
			Execute();
		}
		else
			result = "COMPILE ERROR";
				
		printf("PROGRAM #%d:\n", i);
		printf("%s\n", result.c_str());
		Initialize();
	}
	
	return 0;
}

