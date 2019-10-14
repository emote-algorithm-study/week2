#include<iostream>
#include<string>
using namespace std;


string Reverse(string::iterator& iter)
{
	char head = *iter; //string이 가리키는 가장 앞을 가리킨다.
	++iter;

	if (head == 'b' || head == 'w')
		return string(1, head); // ?

	string upperLeft = Reverse(iter);
	string upperRight = Reverse(iter);
	string lowerLeft = Reverse(iter);
	string lowerRight = Reverse(iter);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight; // 순서를 바꾼다.

}


int main()
{
	int case_n;
	string case_input;
	string case_output;
	string::iterator str_pointer;

	cin >> case_n;
	for (int i = 0; i < case_n; i++)
	{
		cin >> case_input;
		
		str_pointer = case_input.begin();
		case_output = Reverse(str_pointer); // 참조 전달시 주의 : 변수 이름, lvalue

		cout << case_output << endl;

	}

	return 0;
}



/*
	- Reference와 포인터의 차이
	Reference는 생성시에 초기화 해주어야만하는데, 이때 주소값이 아닌 변수이름으로 초기화 한다.
	함수 인자로 받을 때 역시 주소값을 넘겨준느 것이 아니라, 변수이름을 넘겨주어야 한다.

	- 함수의 인자로 바로 전달이 불가능 할때는 다른 변수에 할당 후에 넘겨 주도록..(비const 참조에 대한 초기값은 lvalue여야 합니다.)
	
	- 중간과정이 생략가능한 문제인지 고민해볼 것.

*/