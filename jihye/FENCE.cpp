#include <iostream>
#include <vector>
using namespace std;

int main() {
	int case_num; //케이스 개수
	int board_num; //판자 개수
	int result = 0; //
	vector <int> v;

	cin >> case_num; //케이스의 개수

	for (int i = 0; i < case_num; i++) { //입력받은 케이스의 개수만큼

		cin >> board_num;
		int* Arr = new int[board_num]; //울타리의 개수만큼 배열동적할당

		for (int j = 0; j < board_num; j++) { //울타리의 높이 입력받음
			cin >> Arr[j];
		}

		/*최대 직사각형의 크기 계산*/
		int same_h; //근처의 같은 높이의 울타리의 개수
		int target;
		int max = 0; //최대 직사각형의 넓이

		for (int k = 0; k < board_num; k++) { //각각의 울타리에서 만들수 있는 넓이 비교 후 max값 재설정
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

		/*결과값 배열에 저장*/
		v.push_back(max); //마지막 원소 뒤에 max 값을 삽입

		if (i == case_num - 1) { //max값 순서대로 출력
			for (int a = 0; a < case_num; a++) {
				cout << v.at(a) << endl;
			}
		}

	}
	return 0;
}