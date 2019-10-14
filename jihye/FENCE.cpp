#include <iostream>
#include <vector>
using namespace std;

int main() {
	int case_num; //���̽� ����
	int board_num; //���� ����
	int result = 0; //
	vector <int> v;

	cin >> case_num; //���̽��� ����

	for (int i = 0; i < case_num; i++) { //�Է¹��� ���̽��� ������ŭ

		cin >> board_num;
		int* Arr = new int[board_num]; //��Ÿ���� ������ŭ �迭�����Ҵ�

		for (int j = 0; j < board_num; j++) { //��Ÿ���� ���� �Է¹���
			cin >> Arr[j];
		}

		/*�ִ� ���簢���� ũ�� ���*/
		int same_h; //��ó�� ���� ������ ��Ÿ���� ����
		int target;
		int max = 0; //�ִ� ���簢���� ����

		for (int k = 0; k < board_num; k++) { //������ ��Ÿ������ ����� �ִ� ���� �� �� max�� �缳��
			target = k;
			same_h = 1;
			while (target - 1 >= 0 && Arr[target - 1] >= Arr[k]) {
				same_h++;
				target--;
			}

			target = k;
			while (target + 1 < board_num && Arr[target + 1] >= Arr[k]) {
				same_h++;
				target++;
			}

			if (same_h * Arr[k] >= max)
				max = same_h * Arr[k];
		}

		/*����� �迭�� ����*/
		v.push_back(max); //������ ���� �ڿ� max ���� ����

		if (i == case_num - 1) { //max�� ������� ���
			for (int a = 0; a < case_num; a++) {
				cout << v.at(a) << endl;
			}
		}

	}
	return 0;
}