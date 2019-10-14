#include<iostream>
#include<vector>
using namespace std;


int FindMinHeight(vector<int> board_hight, int start, int end) // board_hight �������� ���� ���̰� ���� "index" ��ȯ
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



int FindMaxMiddle(vector<int> board_higth, int start, int end) // ���������� �� �ǹǷ� �������� �Ұ�, ����Ž������ ���ؾ���.
{
	vector<int> areas;
	int min_index;
	int max_area;
	int max_of_max = 0;

	int mid_left = start + (end - start) / 2; // �߰� ���� index
	int mid_right = start + (end - start) / 2 + 1; // �߰� ������ index
	
	for (int right_ex = mid_right; right_ex <= end; right_ex++)
	{
		for (int left_ex = mid_left; left_ex >= start; left_ex--)
		{
			min_index = FindMinHeight(board_higth, left_ex, right_ex);
			max_area = board_higth[min_index] * (right_ex - left_ex + 1);  // �ּҳ��� * ���� ����

			areas.push_back(max_area);
		}
	}

	
	for (int i = 0; i < areas.size(); i++) // ������ ã�� �ִ밪�� �߿� ���� ū ���� ã�´�.
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
	//base case : ���� �迭�� �ϳ��� ���
	if ((end-start) == 1 | (end-start == 0))
	{
		return board_hight[start] <= board_hight[end] ? board_hight[end] : board_hight[start]; // ���� ��쿡�� ������ �߰����� ���� ũ�ԵǹǷ� ���� ó��x
	}

	//���� : ����, ������, ��ģ ���� ������.
	left_area = FindMaxArea(board_hight, start, start + (end - start) / 2); // ������ �ִ밪. �������� ������ �迭�� ����.
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
	int max; // �ִ밪 : 20000* 10000 �̹Ƿ� int���� ��


	cin >> case_n;
	for (int i = 0; i < case_n; i++)
	{
		cin >> num_board; // ������ ����
		board_hight.assign(num_board, 0); // num_board ���� ���Ҹ� 0���� �Ҵ��Ѵ�.

		for (int j = 0; j < num_board; j++) // ������ ���� �迭 ����
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
	���������� ����Ž���� ���� ����ϴ� ��������.
	�潺�� �������� ����� ������ �ִ밪, �������� �ִ밪�� ���ϴ� ������ ���� ����������,
	���ʰ� �������� ��迡 �����ִ� ���, �װ��� �������� �ϳ��� ������ �������� ��� ��츦 Ž���ؾ��ߴ�.
	�����ִ� ���� ������ �����ϴ� ���� �Ұ����ϹǷ� ���������̳� ��͸� ���� ���ϴ� ���� �Ұ����غ�����.

	����� �⺻������ ����, ������, ��迡 ��ģ ��츦 ������ ����������, ����� ��� ����Ž���ϴ� ��������.

	�̹� ������ ������ ����� Ȯ������ �ʾƼ� ����� �ð��� �����ɷȴ�. + ��������� �Լ��� �����ϴ� ������ �ͼ����� ����.

*/