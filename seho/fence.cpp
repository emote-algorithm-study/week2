#include<iostream>
#include<vector>
using namespace std;


int FindMinHeight(vector<int> board_hight, int start, int end) // board_hight 범위에서 가장 높이가 낮은 "index" 반환
{
	int min_index = start;
	for (int i = start+1; i <= end; i++)
	{
		if (board_hight[i] < board_hight[min_index])
		{
			min_index = i;
		}
	}

	return min_index;
}



int FindMaxMiddle(vector<int> board_higth, int start, int end) // 문제분할이 안 되므로 분할정복 불가, 완전탐색으로 구해야함.
{
	vector<int> areas;
	int min_index;
	int max_area;
	int max_of_max = 0;

	int mid_left = start + (end - start) / 2; // 중간 왼쪽 index
	int mid_right = start + (end - start) / 2 + 1; // 중간 오른쪽 index
	
	for (int right_ex = mid_right; right_ex <= end; right_ex++)
	{
		for (int left_ex = mid_left; left_ex >= start; left_ex--)
		{
			min_index = FindMinHeight(board_higth, left_ex, right_ex);
			max_area = board_higth[min_index] * (right_ex - left_ex + 1);  // 최소높이 * 보드 개수

			areas.push_back(max_area);
		}
	}

	
	for (int i = 0; i < areas.size(); i++) // 위에서 찾은 최대값들 중에 가장 큰 값을 찾는다.
	{
		if (max_of_max < areas[i])
		{
			max_of_max = areas[i];
		}
	}

	return max_of_max;
}



int FindMaxArea(vector<int> board_hight, int start, int end)
{
	int left_area, right_area, middle_area;
	int max;
	//base case : 높이 배열이 하나인 경우
	if ((end-start) == 1 | (end-start == 0))
	{
		return board_hight[start] <= board_hight[end] ? board_hight[end] : board_hight[start]; // 같은 경우에는 어차피 중간값이 가장 크게되므로 따로 처리x
	}

	//분할 : 왼쪽, 오른쪽, 걸친 경우로 나누기.
	left_area = FindMaxArea(board_hight, start, start + (end - start) / 2); // 왼쪽의 최대값. 왼쪽으로 한정된 배열만 전달.
	right_area = FindMaxArea(board_hight, start + ((end - start) / 2) + 1 , end);
	middle_area = FindMaxMiddle(board_hight, start, end);

	max = left_area;
	if (max < right_area)
	{
		max = right_area;
	}
	if (max < middle_area)
	{
		max = middle_area;
	}

	return max;

}


int main()
{
	int case_n;
	int num_board;
	vector<int> board_hight;
	int max; // 최대값 : 20000* 10000 이므로 int범위 내


	cin >> case_n;
	for (int i = 0; i < case_n; i++)
	{
		cin >> num_board; // 판자의 개수
		board_hight.assign(num_board, 0); // num_board 개의 원소를 0으로 할당한다.

		for (int j = 0; j < num_board; j++) // 판자의 높이 배열 생성
		{
			cin >> board_hight[j];
		}

		max = FindMaxArea(board_hight, 0, num_board-1);

		cout << max << endl;

		board_hight.clear();
	}

	return 0;
}


/*   FENCE Summary
	분할정복과 완전탐색을 같이 사용하는 문제였음.
	펜스를 절반으로 나누어서 왼쪽의 최대값, 오른쪽의 최대값을 구하는 과정은 분할 정복이지만,
	왼쪽과 오른쪽의 경계에 걸쳐있는 경우, 그것을 기준으로 하나씩 범위를 넓혀가며 모든 경우를 탐색해야했다.
	걸쳐있는 경우는 문제를 분할하는 것이 불가능하므로 분할정복이나 재귀를 통해 구하는 것은 불가능해보였다.

	결론은 기본적으로 왼쪽, 오른쪽, 경계에 걸친 경우를 나누어 생각하지만, 경계의 경우 완전탐색하는 문제였다.

	이번 문제는 조건을 면밀히 확인하지 않아서 디버깅 시간이 오래걸렸다. + 재귀적으로 함수를 구성하는 과정이 익숙하지 않음.

*/