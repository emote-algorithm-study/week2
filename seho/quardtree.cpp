#include<iostream>
#include<string>
using namespace std;


string Reverse(string::iterator& iter)
{
	char head = *iter; //string�� ����Ű�� ���� ���� ����Ų��.
	++iter;

	if (head == 'b' || head == 'w')
		return string(1, head); // ?

	string upperLeft = Reverse(iter);
	string upperRight = Reverse(iter);
	string lowerLeft = Reverse(iter);
	string lowerRight = Reverse(iter);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight; // ������ �ٲ۴�.

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
		case_output = Reverse(str_pointer); // ���� ���޽� ���� : ���� �̸�, lvalue

		cout << case_output << endl;

	}

	return 0;
}



/*
	- Reference�� �������� ����
	Reference�� �����ÿ� �ʱ�ȭ ���־�߸��ϴµ�, �̶� �ּҰ��� �ƴ� �����̸����� �ʱ�ȭ �Ѵ�.
	�Լ� ���ڷ� ���� �� ���� �ּҰ��� �Ѱ��ش� ���� �ƴ϶�, �����̸��� �Ѱ��־�� �Ѵ�.

	- �Լ��� ���ڷ� �ٷ� ������ �Ұ��� �Ҷ��� �ٸ� ������ �Ҵ� �Ŀ� �Ѱ� �ֵ���..(��const ������ ���� �ʱⰪ�� lvalue���� �մϴ�.)
	
	- �߰������� ���������� �������� ����غ� ��.

*/