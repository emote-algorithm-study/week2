#include <iostream>
#include <vector>
using namespace std;

vector<int> clock_direction(16, 0);
vector<int> mirror(16, 0);
const int INF = 9999999,  SWITCHES = 10, CLOCKS = 16;
/*
const char linked[SWITCHES][CLOCKS + 1] = { // CLOCK+1인 이유는 문자열로 할당할때 마지막 NULL문자칸 을 위한 것.
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
}; // 연결됨 x /  연결 되지 않음 .
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
			cin >> clock_direction[j]; // 시계 방향 저장
			mirror[j] = clock_direction[j]; // 복사본
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
											if (IsAllTwelve()) // 위만큼 스위치를 눌렀을때 모두 정답이 나오면 누른 개수를 더함
											{
												solution_exist = true;
												if (i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10 < minimum)
												{
													minimum = i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10;
												}
											}
											// 다시 원래 시계방향으로 복구
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

	if (solution_exist == false) // 위 에서 모든 경우를 탐색했음에도 답이 나오지 않은 경우
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
		if (clock_direction[i] != 12) // 하나라도 12가 아니면 false 할당후 break;
		{
			all = false;
			break;
		}
	}
	return all;
}

/*
	- 스위치를 4번 누르면 다시 원래대로 돌아오므로, 4회 이상 누르는 것은 안 누르는 것과 같음.
	따라서, 최대 경우의 수는 각 스위치(10개)를 0~3회 누르는 것이 가능하므로, 최대 4^10라는 경우의 수를 같는다. (약 1,000,000)

	답이 나온경우 스위치를 누르는 순서는 중요하지 않다.
	
	- vector< vector<bool> > switch_to_clock(10, vector<bool>(16, false)); // false로 초기화된 2차원 벡터 생성
*/