#include <iostream>

using namespace std;

/*//����һ���������࣬����ڸü����������һ��%������Ҫ�޸�getResult��������Ͳ����Ͽ���ԭ���ڴ��͵Ĺ����У�getResult������߼����ܻ�ܸ��ӣ��Ӷ����²��������bug
class Calculator
{
public:
	Calculator(int a, int b, string moperator)
	{
		this->m_a = a;
		this->m_b = b;
		this->m_operator = moperator;
	};
    ~Calculator();
public:
	int getResult()
	{
		if (m_operator.compare("+") == 0)
		{
			return m_a + m_b;
		}
		else if (m_operator.compare("-") == 0)
		{
			return m_a - m_b;
		}
		else if (m_operator.compare("*") == 0)
		{
			return m_a * m_b;
		}
		else if (m_operator.compare("/") == 0)
		{
			return m_a / m_b;
		}
	};
private:
	int m_a;
	int m_b;
	string m_operator;
};*/

//���ﴴ��һ�������������������������ֿ��������������Ӷ��ﵽ��̬��Ч��
class AbstractCalculator
{
	//����ע��������д�����������AbstractCalculator��ֻ�ǵ�һ����Ϊ�����࣬���ܱ�ʵ�����������������������Ϊvirtual ������() = 0;������ʵ����������{}
public:
	virtual int getResult()=0;
	virtual void setOperatorNum(int a, int b){};
};
//�ӷ�������
class AddCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return m_a + m_b;
	}
	void setOperatorNum(int a, int b)
	{
		this->m_a = a;
		this->m_b = b;
	}
private:
	int m_a;
	int m_b;
};
//ȡ����������������ȡ�����������bug������Ӱ�쵽������������ʹ�ã�����
class RemainderCalculator : public AbstractCalculator
{
public:
	int getResult()
	{
		return m_a % m_b;
	}
	void setOperatorNum(int a, int b)
	{
		this->m_a = a;
		this->m_b = b;
	}
private:
	int m_a;
	int m_b;
};
int main()
{
	/*Calculator *c = new Calculator(43, 45, "*");
	cout << "result:" << c->getResult() << endl;*/
	AbstractCalculator *ac = new RemainderCalculator();
	ac->setOperatorNum(120, 34);
	cout << "result:"<<ac->getResult() << endl;
}