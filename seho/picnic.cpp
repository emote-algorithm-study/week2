#include <iostream>
using namespace std;

int Count_pairs(bool* is_paired, bool friend_array[][10]);

int n_case; // test case 번째
int num_student, num_friend_pair;
bool friend_array[10][10]; // 친구관계를 나타내는 배열
int temp_friend1, temp_friend2;
int count_result; // 최종 결과: 친구관계인 학생들끼리만 짝을 지어주는 경우의 수
bool is_paired[10]; // 짝을 이루었는지 여부를 나타내는 배열

int main()
{


	fill_n(is_paired, 10, false); // 짝을 아무도 이루지 않았으므로 false로 초기화
	// fill_n : 배열을 같은 값으로 초기화 하는 함수

	cin >> n_case;
	for (int i = 0; i < n_case; i++)
	{
		// 각 반복마다 is_paired, friend_array false로 초기화
		for (int m = 0; m < 10; m++)
		{
			is_paired[m] = false;
			for (int n = 0; n < 10; n++)
			{
				friend_array[m][n] = false;
			}
		}
		
		cin >> num_student >> num_friend_pair;

		for (int j = 0; j < num_friend_pair; j++) // 친구 배열 생성 과정. 친구 쌍의 수만큼 반복.
		{
			cin >> temp_friend1 >> temp_friend2;
			friend_array[temp_friend1][temp_friend2] = true; // 입력으로 받은 두 학생은 친구임
			friend_array[temp_friend2][temp_friend1] = true; // 행렬에서 대칭되는 원소에도 입력해둠.
		}
		// 친구 관계 배열 생성 완료

		// 짝 지을 수 있는 개수를 세어야함.
		count_result = Count_pairs(is_paired, friend_array);
		cout << count_result << endl;
	}
	
	return 0;
}


/*
	재귀 호출이 아닌 일반 반복문으로 경우의 수를 셀 방법은?
	 학생의 수에따라서 for문의 중첩 개수가 달라지므로, 일반 반복문으로는 거의 불가능할 것 같다. -> 재귀가 필요한 경우임.
*/


int Count_pairs(bool* is_paired, bool friend_array[][10])
{
	int case_sum = 0;
	int not_paired = -1;

	//아직 짝을 짓지못한 학생을 선택
	for (int i = 0; i < num_student; i++)
	{
		if (is_paired[i] == false) { not_paired = i; break; } // 찾으면 break;
	}

	if (not_paired == -1) {
		return 1;  
	}
	//base case : 만약 짝을 짓지 못한 학생이 없다면(not_paired == -1) 1리턴 (하나의 경우 완성)

	// 있다면(not_paired =! -1)
	for (int i = not_paired + 1; i < num_student; i++)
	{
		if (friend_array[not_paired][i] == true && is_paired[i] == false) // 친구 관계이고, i도 아직 짝이 없는 경우
		{
			is_paired[not_paired] = true;
			is_paired[i] = true; // 둘 모두 짝 이루었으므로 is_paired 업데이트
			case_sum += Count_pairs(is_paired, friend_array); // 새로 업데이트 된 배열을 인자로 전달하며 다시 호출
			is_paired[not_paired] = false; 
			is_paired[i] = false; // 재귀 호출 후에는 다시 풀어야 다음 반복문에서 경우의 수를 제대로 셀 수 있음.
			// 각 경우를 완성했거나 못했거나 다음 경우를 세기위해서 짝을 다시 false로 두어야함.
		}
	}

	return case_sum;
}




/*  Summary

	재귀에서는 먼저 base case가 어떤 경우인지 생각하고, 얼마나 작은 문제로 나눌지 생각해야함.
	그리고 return값을 어떻게 줄지 고민(base case부터 상향으로 생각)

	경우의 수를 세는 문제는 각 관계에 대해 다시 변수를 되돌려놓고 세어야함. (이문제 : is_paired를 다시 false로 되돌려..)
	사소한 연산자 오류.. == 와 =

	1차원 배열은 *연산자로 전달가능
	2차원이상 배열은 [][NUM].. 처럼 뒷항은 채워서 전달 - 올바르게 주소를 계산하기 위해 어쩔수 없이 필요하기때문
*/