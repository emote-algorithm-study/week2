#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define H 20
#define W 20

int case_n, case_height, case_width;
int case_count;

int Count_cover(char board[][W])
{
	int sum = 0;
	int h, w;
	bool no_match;
	bool white_exist = false;
	bool exit_outer_loop = false;

	for (h = 0; h < case_height; h++) // ��ĭ�� ã�´�. case_height - 1 ������ ����(xxxx) => ��ĭ�� ������
	{
		for (w = 0; w < case_width; w++)
		{
			if (board[h][w] == '.')
			{
				if (case_height != H - 1 && case_width != W - 1) // ���� �ڸ� �κ��� �ƴѰ��
				{
					white_exist = true; // ��ĭ ã���� ��������.
					exit_outer_loop = true;
					break;
				}
				else // ���� ��ĭ�� ���� �ڸ��ΰ��, �� �̻� ä��� �Ұ��ϹǷ� 0����
				{
					return 0;
				}
			}
		}
		if (exit_outer_loop == true) break; // 2�� for�� Ż��
	}

	if (white_exist == false) { // ��ĭ�� ������ ��ĭ ä��� �ϼ�
		return 1;
	}
	else // �� ĭ�� �ִ� ��� �� ��ġ�� �������� case Ž��
	{
		no_match = true;
		if (board[h][w] == '.' && board[h][w + 1] == '.' && board[h + 1][w + 1] == '.') // ���� ������� ��ĭ ����
		{
			no_match = false;
			board[h][w] = board[h][w + 1] = board[h + 1][w + 1] = '#';
			sum += Count_cover(board); // �� ������� ���� ä��� ��� ȣ��
			board[h][w] = board[h][w + 1] = board[h + 1][w + 1] = '.'; // �ٽ� ����
		}
		if (board[h][w] == '.' && board[h + 1][w - 1] == '.' && board[h + 1][w] == '.' && w > 0) // �� ���, ���� �����ڸ� �϶��� pass(w > 0) �ڡڡڡڡڡ�
		{
			no_match = false;
			board[h][w] = board[h + 1][w - 1] = board[h + 1][w] = '#';
			sum += Count_cover(board);
			board[h][w] = board[h + 1][w -1] = board[h + 1][w] = '.';
		}
		if (board[h][w] == '.' && board[h + 1][w + 1] == '.' && board[h + 1][w] == '.') // �� ���
		{
			no_match = false;
			board[h][w] = board[h + 1][w + 1] = board[h + 1][w] = '#';
			sum += Count_cover(board);
			board[h][w] = board[h + 1][w + 1] = board[h + 1][w] = '.';
		}
		if (board[h][w] == '.' && board[h][w + 1] == '.' && board[h + 1][w] == '.') // �� ���
		{
			no_match = false;
			board[h][w] = board[h][w + 1] = board[h + 1][w] = '#';
			sum += Count_cover(board);
			board[h][w] = board[h][w + 1] = board[h + 1][w] = '.';
		}

		if (no_match == true) // �� ��ġ�� ��ĭ�� ������, ����� ���� �ʴ� ���
		{
			return 0; // �ڿ� ���� ��ĭ�� ������ε� �ִ��� ���̻� ä�� �� ����.
		}
		else
		{
			return sum;
		}


	}

	return 0;
}

int main()
{
	char board[H][W];

	int white, black;

	cin >> case_n;
	for (int i = 0; i < case_n; i++)
	{
		white = black = 0; // ���, ������ ��� ���� 0���� �ʱ�ȭ
		cin >> case_height >> case_width;

		// board ����
		for (int h = 0; h < case_height; h++)
		{
			for (int w = 0; w < case_width; w++)
			{
				cin >> board[h][w];
				if (board[h][w] == '#') black++;
				else if (board[h][w] == '.') white++;   // ��, �� ��ϰ��� ī��Ʈ
				else {
					cout << "���, ������ �ƴ� ��� ����\n";
					return 0;
				}
			}
		}


		if (white % 3 != 0) // ��� ����� ������ 3�� ����� �ƴϸ� 0��
		{
			cout << 0 << endl;
		}
		else // 3�� ����ΰ�� ���
		{
			cout << Count_cover(board) << endl;
		}

		// �� case ���� �� board �迭 �ʱ�ȭ
		for (int h = 0; h < case_height; h++)
		{
			for (int w = 0; w < case_width; w++)
			{
				board[h][w] = NULL;
			}
		}

	}


	return 0;
}





/*
	���� if - else ������ ���� if�� ������ �׻� ���ο� �Ѱ�
	��� �Լ��� ����ó���� �ִ��� ���� �صѰ�.

	ó�� �˻� ���� ���Ҷ� ��� ��� ������ ������ ��. �������� ��������
	: �� �������� ���� �տ�������(�迭����) ���ʴ�� ���ĭ�� ã�ұ� ������
	 ã�� ĭ�� �������� ���ʰ� ������ ������ ĭ���� ����� ��Ȳ�̹Ƿ�,
	 �׷� ��Ȳ���� �����غ� �� �ִ� case�� ���ĭ �������� �� ��, �¿� ���� ����̴�.
	  ã�� ������ ������ ������� ����ϸ� �ȵǴ� ���̽���.
*/