#include <iostream>
using namespace std;

int Count_pairs(bool* is_paired, bool friend_array[][10]);

int n_case; // test case ��°
int num_student, num_friend_pair;
bool friend_array[10][10]; // ģ�����踦 ��Ÿ���� �迭
int temp_friend1, temp_friend2;
int count_result; // ���� ���: ģ�������� �л��鳢���� ¦�� �����ִ� ����� ��
bool is_paired[10]; // ¦�� �̷������ ���θ� ��Ÿ���� �迭

int main()
{


	fill_n(is_paired, 10, false); // ¦�� �ƹ��� �̷��� �ʾ����Ƿ� false�� �ʱ�ȭ
	// fill_n : �迭�� ���� ������ �ʱ�ȭ �ϴ� �Լ�

	cin >> n_case;
	for (int i = 0; i < n_case; i++)
	{
		// �� �ݺ����� is_paired, friend_array false�� �ʱ�ȭ
		for (int m = 0; m < 10; m++)
		{
			is_paired[m] = false;
			for (int n = 0; n < 10; n++)
			{
				friend_array[m][n] = false;
			}
		}
		
		cin >> num_student >> num_friend_pair;

		for (int j = 0; j < num_friend_pair; j++) // ģ�� �迭 ���� ����. ģ�� ���� ����ŭ �ݺ�.
		{
			cin >> temp_friend1 >> temp_friend2;
			friend_array[temp_friend1][temp_friend2] = true; // �Է����� ���� �� �л��� ģ����
			friend_array[temp_friend2][temp_friend1] = true; // ��Ŀ��� ��Ī�Ǵ� ���ҿ��� �Է��ص�.
		}
		// ģ�� ���� �迭 ���� �Ϸ�

		// ¦ ���� �� �ִ� ������ �������.
		count_result = Count_pairs(is_paired, friend_array);
		cout << count_result << endl;
	}
	
	return 0;
}


/*
	��� ȣ���� �ƴ� �Ϲ� �ݺ������� ����� ���� �� �����?
	 �л��� �������� for���� ��ø ������ �޶����Ƿ�, �Ϲ� �ݺ������δ� ���� �Ұ����� �� ����. -> ��Ͱ� �ʿ��� �����.
*/


int Count_pairs(bool* is_paired, bool friend_array[][10])
{
	int case_sum = 0;
	int not_paired = -1;

	//���� ¦�� �������� �л��� ����
	for (int i = 0; i < num_student; i++)
	{
		if (is_paired[i] == false) { not_paired = i; break; } // ã���� break;
	}

	if (not_paired == -1) {
		return 1;  
	}
	//base case : ���� ¦�� ���� ���� �л��� ���ٸ�(not_paired == -1) 1���� (�ϳ��� ��� �ϼ�)

	// �ִٸ�(not_paired =! -1)
	for (int i = not_paired + 1; i < num_student; i++)
	{
		if (friend_array[not_paired][i] == true && is_paired[i] == false) // ģ�� �����̰�, i�� ���� ¦�� ���� ���
		{
			is_paired[not_paired] = true;
			is_paired[i] = true; // �� ��� ¦ �̷�����Ƿ� is_paired ������Ʈ
			case_sum += Count_pairs(is_paired, friend_array); // ���� ������Ʈ �� �迭�� ���ڷ� �����ϸ� �ٽ� ȣ��
			is_paired[not_paired] = false; 
			is_paired[i] = false; // ��� ȣ�� �Ŀ��� �ٽ� Ǯ��� ���� �ݺ������� ����� ���� ����� �� �� ����.
			// �� ��츦 �ϼ��߰ų� ���߰ų� ���� ��츦 �������ؼ� ¦�� �ٽ� false�� �ξ����.
		}
	}

	return case_sum;
}




/*  Summary

	��Ϳ����� ���� base case�� � ������� �����ϰ�, �󸶳� ���� ������ ������ �����ؾ���.
	�׸��� return���� ��� ���� ���(base case���� �������� ����)

	����� ���� ���� ������ �� ���迡 ���� �ٽ� ������ �ǵ������� �������. (�̹��� : is_paired�� �ٽ� false�� �ǵ���..)
	����� ������ ����.. == �� =

	1���� �迭�� *�����ڷ� ���ް���
	2�����̻� �迭�� [][NUM].. ó�� ������ ä���� ���� - �ùٸ��� �ּҸ� ����ϱ� ���� ��¿�� ���� �ʿ��ϱ⶧��
*/