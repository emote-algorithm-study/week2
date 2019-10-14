#include <iostream>
#include <vector>
using namespace std;

vector<int> clock_direction(16, 0);
vector<int> mirror(16, 0);
const int INF = 9999999,  SWITCHES = 10, CLOCKS = 16;
/*
const char linked[SWITCHES][CLOCKS + 1] = { // CLOCK+1�� ������ ���ڿ��� �Ҵ��Ҷ� ������ NULL����ĭ �� ���� ��.
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
}; // ����� x /  ���� ���� ���� .
*/


int FindMinimumClick();
int PushSwitch(int, int);
bool IsAllTwelve();

int main()
{

	int result;
	int case_n;
	
	cin >> case_n;
	for (int i = 0; i < case_n; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cin >> clock_direction[j]; // �ð� ���� ����
			mirror[j] = clock_direction[j]; // ���纻
		}

		result = FindMinimumClick();
		if (result == INF)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << result << endl;
		}


	}

	return 0;
}




int PushSwitch(int switch_num, int num)
{
	for (int i = 0; i < num; i++)
	{
		switch (switch_num)
		{
		case 0:
		{
			clock_direction[0] += 3; if (clock_direction[0] == 15) clock_direction[0] = 3;
			clock_direction[1] += 3; if (clock_direction[1] == 15) clock_direction[1] = 3;
			clock_direction[2] += 3; if (clock_direction[2] == 15) clock_direction[2] = 3;
			break;
		}

		case 1:
		{
			clock_direction[3] += 3; if (clock_direction[3] == 15) clock_direction[3] = 3;
			clock_direction[7] += 3; if (clock_direction[7] == 15) clock_direction[7] = 3;
			clock_direction[9] += 3; if (clock_direction[9] == 15) clock_direction[9] = 3;
			clock_direction[11] += 3; if (clock_direction[11] == 15) clock_direction[11] = 3;
			break;
		}
		case 2:
		{
			clock_direction[4] += 3; if (clock_direction[4] == 15) clock_direction[4] = 3;
			clock_direction[10] += 3; if (clock_direction[10] == 15) clock_direction[10] = 3;
			clock_direction[14] += 3; if (clock_direction[14] == 15) clock_direction[14] = 3;
			clock_direction[15] += 3; if (clock_direction[15] == 15) clock_direction[15] = 3;
			break;
		}
		case 3:
		{
			clock_direction[0] += 3; if (clock_direction[0] == 15) clock_direction[0] = 3;
			clock_direction[4] += 3; if (clock_direction[4] == 15) clock_direction[4] = 3;
			clock_direction[5] += 3; if (clock_direction[5] == 15) clock_direction[5] = 3;
			clock_direction[6] += 3; if (clock_direction[6] == 15) clock_direction[6] = 3;
			clock_direction[7] += 3; if (clock_direction[7] == 15) clock_direction[7] = 3;
			break;
		}
		case 4:
		{
			clock_direction[6] += 3; if (clock_direction[6] == 15) clock_direction[6] = 3;
			clock_direction[7] += 3; if (clock_direction[7] == 15) clock_direction[7] = 3;
			clock_direction[8] += 3; if (clock_direction[8] == 15) clock_direction[8] = 3;
			clock_direction[10] += 3; if (clock_direction[10] == 15) clock_direction[10] = 3;
			clock_direction[12] += 3; if (clock_direction[12] == 15) clock_direction[12] = 3;
			break;
		}
		case 5:
		{
			clock_direction[0] += 3; if (clock_direction[0] == 15) clock_direction[0] = 3;
			clock_direction[2] += 3; if (clock_direction[2] == 15) clock_direction[2] = 3;
			clock_direction[14] += 3; if (clock_direction[14] == 15) clock_direction[14] = 3;
			clock_direction[15] += 3; if (clock_direction[15] == 15) clock_direction[15] = 3;
			break;
		}
		case 6:
		{
			clock_direction[3] += 3; if (clock_direction[3] == 15) clock_direction[3] = 3;
			clock_direction[14] += 3; if (clock_direction[14] == 15) clock_direction[14] = 3;
			clock_direction[15] += 3; if (clock_direction[15] == 15) clock_direction[15] = 3;
			break;
		}
		case 7:
		{
			clock_direction[4] += 3; if (clock_direction[4] == 15) clock_direction[4] = 3;
			clock_direction[5] += 3; if (clock_direction[5] == 15) clock_direction[5] = 3;
			clock_direction[7] += 3; if (clock_direction[7] == 15) clock_direction[7] = 3;
			clock_direction[14] += 3; if (clock_direction[14] == 15) clock_direction[14] = 3;
			clock_direction[15] += 3; if (clock_direction[15] == 15) clock_direction[15] = 3;
			break;
		}
		case 8:
		{
			clock_direction[1] += 3; if (clock_direction[1] == 15) clock_direction[1] = 3;
			clock_direction[2] += 3; if (clock_direction[2] == 15) clock_direction[2] = 3;
			clock_direction[3] += 3; if (clock_direction[3] == 15) clock_direction[3] = 3;
			clock_direction[4] += 3; if (clock_direction[4] == 15) clock_direction[4] = 3;
			clock_direction[5] += 3; if (clock_direction[5] == 15) clock_direction[5] = 3;
			break;
		}
		case 9:
		{
			clock_direction[3] += 3; if (clock_direction[3] == 15) clock_direction[3] = 3;
			clock_direction[4] += 3; if (clock_direction[4] == 15) clock_direction[4] = 3;
			clock_direction[5] += 3; if (clock_direction[5] == 15) clock_direction[5] = 3;
			clock_direction[9] += 3; if (clock_direction[9] == 15) clock_direction[9] = 3;
			clock_direction[13] += 3; if (clock_direction[13] == 15) clock_direction[13] = 3;
			break;
		}
		}
	}
	return 0;
}

int FindMinimumClick()
{
	int count = 0;
	int minimum = INF;
	bool solution_exist = false;

	for (int i1 = 0; i1 < 4; i1++)
	{
		for (int i2 = 0; i2 < 4; i2++)
		{
			for (int i3 = 0; i3 < 4; i3++)
			{
				for (int i4 = 0; i4 < 4; i4++)
				{
					for (int i5 = 0; i5 < 4; i5++)
					{
						for (int i6 = 0; i6 < 4; i6++)
						{
							for (int i7 = 0; i7 < 4; i7++)
							{
								for (int i8 = 0; i8 < 4; i8++)
								{
									for (int i9 = 0; i9 < 4; i9++)
									{
										for (int i10 = 0; i10 < 4; i10++)
										{
											PushSwitch(0, i1);
											PushSwitch(1, i2);
											PushSwitch(2, i3);
											PushSwitch(3, i4);
											PushSwitch(4, i5);
											PushSwitch(5, i6);
											PushSwitch(6, i7);
											PushSwitch(7, i8);
											PushSwitch(8, i9);
											PushSwitch(9, i10);
											if (IsAllTwelve()) // ����ŭ ����ġ�� �������� ��� ������ ������ ���� ������ ����
											{
												solution_exist = true;
												if (i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10 < minimum)
												{
													minimum = i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10;
												}
											}
											// �ٽ� ���� �ð�������� ����
											for (int j = 0; j < 16; j++)
											{
												clock_direction[j] = mirror[j];
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if (solution_exist == false) // �� ���� ��� ��츦 Ž���������� ���� ������ ���� ���
	{
		return INF;
	}


	return minimum;
}

bool IsAllTwelve()
{
	bool all = true;
	for (int i = 0; i < 16; i++)
	{
		if (clock_direction[i] != 12) // �ϳ��� 12�� �ƴϸ� false �Ҵ��� break;
		{
			all = false;
			break;
		}
	}
	return all;
}

/*
	- ����ġ�� 4�� ������ �ٽ� ������� ���ƿ��Ƿ�, 4ȸ �̻� ������ ���� �� ������ �Ͱ� ����.
	����, �ִ� ����� ���� �� ����ġ(10��)�� 0~3ȸ ������ ���� �����ϹǷ�, �ִ� 4^10��� ����� ���� ���´�. (�� 1,000,000)

	���� ���°�� ����ġ�� ������ ������ �߿����� �ʴ�.
	
	- vector< vector<bool> > switch_to_clock(10, vector<bool>(16, false)); // false�� �ʱ�ȭ�� 2���� ���� ����
*/