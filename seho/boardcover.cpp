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

	for (h = 0; h < case_height; h++) // 빈칸을 찾는다. case_height - 1 까지임 주의(xxxx) => 빈칸은 끝까지
	{
		for (w = 0; w < case_width; w++)
		{
			if (board[h][w] == '.')
			{
				if (case_height != H - 1 && case_width != W - 1) // 가장 자리 부분이 아닌경우
				{
					white_exist = true; // 흰칸 찾으면 빠져나감.
					exit_outer_loop = true;
					break;
				}
				else // 만약 빈칸이 가장 자리인경우, 더 이상 채우기 불가하므로 0리턴
				{
					return 0;
				}
			}
		}
		if (exit_outer_loop == true) break; // 2중 for문 탈출
	}

	if (white_exist == false) { // 흰칸이 없으면 빈칸 채우기 완성
		return 1;
	}
	else // 흰 칸이 있는 경우 그 위치를 기준으로 case 탐색
	{
		no_match = true;
		if (board[h][w] == '.' && board[h][w + 1] == '.' && board[h + 1][w + 1] == '.') // ㄱ자 모양으로 빈칸 존재
		{
			no_match = false;
			board[h][w] = board[h][w + 1] = board[h + 1][w + 1] = '#';
			sum += Count_cover(board); // 각 모양으로 보드 채우고 재귀 호출
			board[h][w] = board[h][w + 1] = board[h + 1][w + 1] = '.'; // 다시 복구
		}
		if (board[h][w] == '.' && board[h + 1][w - 1] == '.' && board[h + 1][w] == '.' && w > 0) // 」 모양, 왼쪽 가장자리 일때는 pass(w > 0) ★★★★★★
		{
			no_match = false;
			board[h][w] = board[h + 1][w - 1] = board[h + 1][w] = '#';
			sum += Count_cover(board);
			board[h][w] = board[h + 1][w -1] = board[h + 1][w] = '.';
		}
		if (board[h][w] == '.' && board[h + 1][w + 1] == '.' && board[h + 1][w] == '.') // ㄴ 모양
		{
			no_match = false;
			board[h][w] = board[h + 1][w + 1] = board[h + 1][w] = '#';
			sum += Count_cover(board);
			board[h][w] = board[h + 1][w + 1] = board[h + 1][w] = '.';
		}
		if (board[h][w] == '.' && board[h][w + 1] == '.' && board[h + 1][w] == '.') // 「 모양
		{
			no_match = false;
			board[h][w] = board[h][w + 1] = board[h + 1][w] = '#';
			sum += Count_cover(board);
			board[h][w] = board[h][w + 1] = board[h + 1][w] = '.';
		}

		if (no_match == true) // 그 위치에 빈칸이 있지만, 모양이 맞지 않는 경우
		{
			return 0; // 뒤에 남은 빈칸이 어떤식으로든 있더라도 더이상 채울 수 없음.
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
		white = black = 0; // 흰색, 검은색 블록 개수 0으로 초기화
		cin >> case_height >> case_width;

		// board 생성
		for (int h = 0; h < case_height; h++)
		{
			for (int w = 0; w < case_width; w++)
			{
				cin >> board[h][w];
				if (board[h][w] == '#') black++;
				else if (board[h][w] == '.') white++;   // 흰, 검 블록개수 카운트
				else {
					cout << "흰색, 검정이 아닌 블록 존재\n";
					return 0;
				}
			}
		}


		if (white % 3 != 0) // 흰색 블록의 개수가 3의 배수가 아니면 0개
		{
			cout << 0 << endl;
		}
		else // 3의 배수인경우 계산
		{
			cout << Count_cover(board) << endl;
		}

		// 각 case 종료 후 board 배열 초기화
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
	다중 if - else 문에서 선행 if문 조건을 항상 염두에 둘것
	재귀 함수는 예외처리를 최대한 많이 해둘것.

	처음 검사 조건 정할때 모든 경우 세세히 따져볼 것. 기준점을 기준으로
	: 이 문제에서 나는 앞에서부터(배열순서) 차례대로 흰색칸을 찾았기 떄문에
	 찾은 칸을 기준으로 왼쪽과 위쪽은 검정색 칸임이 보장된 상황이므로,
	 그런 상황에서 생각해볼 수 있는 case는 흰색칸 기준으로 ㄱ ㄴ, 좌우 반전 모양이다.
	  찾은 점에서 떨어진 」모양은 고려하면 안되는 케이스임.
*/