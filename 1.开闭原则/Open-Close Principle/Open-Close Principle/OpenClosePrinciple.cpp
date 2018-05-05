#include <iostream>

using namespace std;

/*//创建一个计算器类，如果在该计算器内添加一个%，则需要修改getResult函数，这就不符合开闭原则，在大型的工程中，getResult里面的逻辑可能会很复杂，从而导致产生更多的bug
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

//这里创建一个抽象计算器，将其他的运算分开构建计算器，从而达到多态的效果
class AbstractCalculator
{
	//这里注意有两种写法，如果想让AbstractCalculator类只是单一的作为抽象类，不能被实例化，下面的两个方法定义为virtual 函数名() = 0;否则请实现它，加上{}
public:
	virtual int getResult()=0;
	virtual void setOperatorNum(int a, int b){};
};
//加法计算器
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
//取余计算器，这样如果取余计算器出了bug，不会影响到其他计算器的使用！！！
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