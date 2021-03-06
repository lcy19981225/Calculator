#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>
#include<cstdio>
#include<stack> 
#include<string>

#define null 0
using namespace std;

int va[1000], vb[1000];

//顺序表计算向量
void cal_vector() {
	int n;
	cout << "请输入你要计算的维数：" << endl;
	cin >> n;
	cout << "请输入第一个向量：" << endl;
	for (int i = 0; i < n; ++i)
		cin >> va[i];
	cout << "请输入第二个向量：" << endl;
	for (int i = 0; i < n; ++i)
		cin >> vb[i];
	cout << "请选择你要进行的操作：" << endl;
	cout << "1.加法" << endl;
	cout << "2.减法" << endl;
	cout << "3.计算向量夹角余弦" << endl;
	int k;
	cin >> k;
	if (k == 1)
	{
		for (int i = 0; i < n; ++i)
			va[i] += vb[i];
		cout << "计算结果:" << endl;
		for (int i = 0; i < n; ++i)
			cout << va[i] << ' ';
		cout << endl;
	}
	else if (k == 2)
	{
		for (int i = 0; i < n; ++i)
			va[i] -= vb[i];
		cout << "计算结果:" << endl;
		for (int i = 0; i < n; ++i)
			cout << va[i] << ' ';
		cout << endl;
	}
	else
	{
		int sum = 0;
		double q1 = 0, q2 = 0;
		for (int i = 0; i < n; i++)
		{
			sum += va[i] * vb[i];
			q1 += va[i] * va[i];
			q2 += vb[i] * vb[i];
		}
		q1 = sqrt(q1);
		q2 = sqrt(q2);
		double cos;
		cos = sum / (q1*q2);
		cout << "计算结果:" << endl;
		cout << cos << endl;
	}
}

int pa[1000][2];
int pb[1000][2];

//顺序表计算多项式
void cal_poly_sequence()
{
	int k1 = 0, k2 = 0;
	cout << "请选择你要进行的操作：" << endl;
	cout << "1.加法" << endl;
	cout << "2.减法" << endl;
	cout << "3.乘法" << endl;
	cout << "4.求导" << endl;
	int s;
	cin >> s;
	if (s == 1)
	{
		cout << "请输入第一个多项式各项系数与次数：" << endl;
		while (cin >> pa[k1][0] >> pa[k1][1])
		{
			if (pa[k1][0] == 0 && pa[k1][1] == 0)
				break;
			k1++;
		}
		cout << "请输入第二个多项式各项系数与次数：" << endl;
		while (cin >> pb[k2][0] >> pb[k2][1])
		{
			if (pb[k2][0] == 0 && pb[k2][1] == 0)
				break;
			k2++;
		}
		int i = 0, j = 0;
		while (i < k1&&j < k2)
		{
			if (pa[i][1] < pb[j][1])
			{
				cout << pa[i][0] << ' ' << pa[i][1] << endl;
				i++;
			}
			else if (pa[i][1] > pb[j][1])
			{
				cout << pb[j][0] << ' ' << pb[j][1] << endl;
				j++;
			}
			else
			{
				pa[i][0] += pb[j][0];
				cout << pa[i][0] << ' ' << pa[i][1] << endl;
				i++;
				j++;
			}
		}
		while (i < k1)
		{
			cout << pa[i][0] << ' ' << pa[i][1] << endl;
			i++;
		}
		while (j < k2)
		{
			cout << pb[j][0] << ' ' << pb[j][1] << endl;
			j++;
		}
	}
	else if (s == 2)
	{
		cout << "请输入第一个多项式各项系数与次数：" << endl;
		while (cin >> pa[k1][0] >> pa[k1][1])
		{
			if (pa[k1][0] == 0 && pa[k1][1] == 0)
				break;
			k1++;
		}
		cout << "请输入第二个多项式各项系数与次数：" << endl;
		while (cin >> pb[k2][0] >> pb[k2][1])
		{
			if (pb[k2][0] == 0 && pb[k2][1] == 0)
				break;
			k2++;
		}
		int i = 0, j = 0;
		while (i < k1&&j < k2)
		{
			if (pa[i][1] < pb[j][1])
			{
				cout << pa[i][0] << ' ' << pa[i][1] << endl;
				i++;
			}
			else if (pa[i][1] > pb[j][1])
			{
				cout << pb[j][0] << ' ' << pb[j][1] << endl;
				j++;
			}
			else
			{
				pa[i][0] -= pb[j][0];
				cout << pa[i][0] << ' ' << pa[i][1] << endl;
				i++;
				j++;
			}
		}
		while (i < k1)
		{
			cout << pa[i][0] << ' ' << pa[i][1] << endl;
			i++;
		}
		while (j < k2)
		{
			cout << pb[j][0] << ' ' << pb[j][1] << endl;
			j++;
		}
	}
	else if (s == 3)
	{
		cout << "请输入第一个多项式各项系数与次数：" << endl;
		while (cin >> pa[k1][0] >> pa[k1][1])
		{
			if (pa[k1][0] == 0 && pa[k1][1] == 0)
				break;
			k1++;
		}
		cout << "请输入第二个多项式各项系数与次数：" << endl;
		while (cin >> pb[k2][0] >> pb[k2][1])
		{
			if (pb[k2][0] == 0 && pb[k2][1] == 0)
				break;
			k2++;
		}
		int pc[1000][2];
		int k3 = 0;
		for (int i = 0; i < k1; i++)
			for (int j = 0; j < k2; j++)
			{
				pc[k3][0] = pa[i][0] * pb[j][0];
				pc[k3][1] = pa[i][1] + pb[j][1];
				k3++;
			}
		for (int i = 0; i < k3; i++)
			for (int j = 0; j < k3 - 1 - i; j++)
			{
				if (pc[j][1] > pc[j + 1][1])
				{
					int p = pc[j][1];
					pc[j][1] = pc[j + 1][1];
					pc[j + 1][1] = p;
					int q = pc[j][0];
					pc[j][0] = pc[j + 1][0];
					pc[j + 1][0] = q;
				}
			}
		int tmp[1000][2];
		for (int i = 0; i < 1000; i++)
			for (int j = 0; j < 2; j++)
				tmp[i][j] = 0;
		int t = 0;
		int mark;
		for (int i = 0; i < k3; i++)
		{
			if (pc[i][1] == pc[i + 1][1])
			{
				mark = 0;
				tmp[t][0] += pc[i][0];
				tmp[t][1] = pc[i][1];
			}
			else
			{
				mark = 1;
				tmp[t][0] += pc[i][0];
				tmp[t][1] = pc[i][1];
				t++;
			}
		}
		cout << "计算结果为：" << endl;
		if (mark == 0)
		{
			for (int i = 0; i <= t; i++)
				cout << tmp[i][0] << ' ' << tmp[i][1] << endl;
		}
		else
		{
			for (int i = 0; i < t; i++)
				cout << tmp[i][0] << ' ' << tmp[i][1] << endl;
		}
	}
	else
	{
		cout << "请输入你要求的导数的阶数：" << endl;
		int n;
		cin >> n;
		cout << "请输入多项式各项系数与次数：" << endl;
		while (cin >> pa[k1][0] >> pa[k1][1])
		{
			if (pa[k1][0] == 0 && pa[k1][1] == 0)
				break;
			k1++;
		}
		for (int i = 0; i < k1; i++)
			for (int j = 1; j <= n; j++)
				pa[i][0] *= (pa[i][1] - j + 1);
		for (int i = 0; i < k1; i++)
			for (int j = 1; j <= n; j++)
				pa[i][1]--;
		for (int i = 0; i < k1; i++)
		{
			if (pa[i][1] < 0)
				continue;
			cout << pa[i][0] << ' ' << pa[i][1] << endl;
		}
	}
}

typedef struct
{
	int coef;//系数
	int expn;//指数
}term;

typedef struct Lnode
{
	term data;
	Lnode *next;
}*Link, *Linklist;

void Orderinsertmerge(Linklist &L, term e, int(*compara)(term, term));

int cmp(term a, term b)//将指数从小到大排序
{
	if (a.expn == b.expn)
		return 0;
	else
		return (a.expn - b.expn) / abs(a.expn - b.expn);
}

void Orderinsert(Linklist &L, term e, int(*comp)(term, term))//直接将输入的项数和指数放入链表（没有可以合并的项）
{
	Link o, p, q;
	q = L;
	p = q->next;
	while (p&&comp(p->data, e) < 0)
	{
		q = p;
		p = p->next;
	}
	o = (Link)malloc(sizeof(Lnode));
	o->data = e;
	q->next = o;
	o->next = p;
}

void chengfa(Linklist &L1, Linklist &L2, Linklist &L3)
{
	L3 = (Link)malloc(sizeof(Lnode));
	L3->next = null;
	Link S = L1->next;
	term s, e;
	while (S)
	{
		s.coef = S->data.coef;
		s.expn = S->data.expn;
		Link Q = L2->next;
		while (Q)
		{
			e.coef = s.coef * Q->data.coef;
			e.expn = s.expn + Q->data.expn;
			Orderinsertmerge(L3, e, cmp);
			Q = Q->next;
		}
		S = S->next;
	}
}

int LocateElem(Linklist L, term e, Link &s, Link &q, int(*comp)(term, term))//判断是否有可以合并的项
{
	Link p;
	s = L;
	p = s->next;
	while (p&&comp(p->data, e) != 0)
	{
		s = p;
		p = p->next;
	}
	if (!p)
	{
		s = q = null;
		return 0;
	}
	else
	{
		q = p;
		return 1;
	}
}

void Delnext(Linklist &L, Link s)
{
	Link q = s->next;
	s->next = q->next;
	free(q);
}

void Orderinsertmerge(Linklist &L, term e, int(*compara)(term, term))//将同一个多项式里相同的项合并
{
	Link q, s;
	if (LocateElem(L, e, s, q, compara))
	{
		q->data.coef += e.coef;
		if (!q->data.coef)
		{
			Delnext(L, s);
		}
	}
	else
		Orderinsert(L, e, compara);
}

void Creatpolyn(Linklist &p, int m)//输入多项式的系数和指数
{
	term e;
	int i;
	p = (Link)malloc(sizeof(Lnode));//给链表开拓空间
	p->next = null;
	printf("\n请输入%d个系数和指数用空格符间隔：\n", m);
	for (i = 1; i <= m; i++)
	{
		cin >> e.coef >> e.expn;
		Orderinsertmerge(p, e, cmp);//将输入的多项式中可以合并的项合并
	}
}

void add(Linklist &La, Linklist Lb)//合并两个多项式
{
	Link qb; term b;
	qb = Lb->next;
	while (qb)
	{
		b = qb->data;
		Orderinsertmerge(La, b, cmp);
		qb = qb->next;
	}
	//销毁链表Lb
}

void Minus(Linklist &La, Linklist &Lb)
{
	Link qb; term b;
	qb = Lb->next;
	while (qb)
	{
		qb->data.coef = -qb->data.coef;
		qb = qb->next;
	}
	qb = Lb->next;
	while (qb)
	{
		b = qb->data;
		Orderinsertmerge(La, b, cmp);
		qb = qb->next;
	}
}

void printpolyn(Linklist p)//打印出相加后的多项式
{
	Link q;
	q = p->next;
	int t = 0;
	while (q)
	{
		if (t == 0)
		{
			if (q->data.coef == 1)
				printf("x^%d", q->data.expn);
			else if (q->data.coef == -1)
				printf("-x^%d", q->data.expn);
			else if (q->data.coef > 0)
				printf("%d*x^%d", q->data.coef, q->data.expn);
			else if (q->data.coef < 0)
				printf("%d*x^%d", q->data.coef, q->data.expn);
		}
		else
		{
			if (q->data.coef == 1)
				printf("+x^%d", q->data.expn);
			else if (q->data.coef == -1)
				printf("-x^%d", q->data.expn);
			else if (q->data.coef > 0)
				printf("+%d*x^%d", q->data.coef, q->data.expn);
			else if (q->data.coef < 0)
				printf("%d*x^%d", q->data.coef, q->data.expn);
		}
		q = q->next;
		t++;
	}
}

void d(Linklist head, int n)
{
	Link p = head->next;
	while (p)
	{
		for (int i = 0; i < n; i++)
		{
			p->data.coef *= p->data.expn;
			p->data.expn--;
		}
		p = p->next;
	}
}

//多项式计算
void cal_poly_list()
{
	cout << "请选择你要进行的操作：" << endl;
	cout << "1.加法" << endl;
	cout << "2.减法" << endl;
	cout << "3.乘法" << endl;
	cout << "4.求导" << endl;
	int k;
	cin >> k;
	if (k == 1)
	{
		int x;
		Linklist L1, L2;
		printf("\n请输入第一个一元多项式的项数:");
		cin >> x;
		Creatpolyn(L1, x);
		printf("\n请输入第二个一元多项式的项数:");
		cin >> x;
		Creatpolyn(L2, x);
		add(L1, L2);
		printf("\n相加以后的一元多项式为：\n");
		printpolyn(L1);
	}
	else if (k == 2)
	{
		int x;
		Linklist L1, L2;
		printf("\n请输入第一个一元多项式的项数:");
		cin >> x;
		Creatpolyn(L1, x);
		printf("\n请输入第二个一元多项式的项数:");
		cin >> x;
		Creatpolyn(L2, x);
		Minus(L1, L2);
		printf("\n相减以后的一元多项式为：\n");
		printpolyn(L1);
	}
	else if (k == 3)
	{
		int x;
		Linklist L1, L2, L3;
		printf("\n请输入第一个一元多项式的项数:");
		cin >> x;
		Creatpolyn(L1, x);
		printf("\n请输入第二个一元多项式的项数:");
		cin >> x;
		Creatpolyn(L2, x);
		printf("\n相乘以后的一元多项式为：\n");
		chengfa(L1, L2, L3);
		printpolyn(L3);
	}
	else
	{
		int n, x;
		Linklist L1;
		cout << "请输入你要求的导数的阶数：" << endl;
		cin >> n;
		printf("\n请输入第一个一元多项式的项数:");
		cin >> x;
		Creatpolyn(L1, x);
		printf("\n相乘以后的一元多项式为：\n");
		d(L1, n);
		printpolyn(L1);

	}
	return;
}

//---------------------------------------------------------------------------------

stack<char> opter;    //运算符栈
stack<double> opval;  //操作数栈

const int Expmax_length = 1001;//表达式最大长度，可根据适当情况调整 

struct Ope_unit
{//定义操作单元 
	int    flag;//=1表示是操作数 =0表示是操作符 -1表示符号单元 
	char   oper;//操作符 
	double real;//操作数，为双精度浮点数 
};

int Check(string Exp_arry);
void Evalua(); //先调用Conver操作单元化，再调用Calculate函数计算结果并输出 
int  Conver(struct Ope_unit Opeunit_arry[], string Exp_arry);//将字符串处理成操作单元 
int  Isoper(char ch);//判断合法字符（+ - * / ( ) =）
char  Ope_Compar(char ope1, char ope2);//操作符运算优先级比较 
//double Calculate(struct Ope_unit Opeunit_arry[], int Opeunit_count);//用栈计算表达式结果 
double Four_arithm(double x, double y, char oper);//四则运算 
double getAnswer(struct Ope_unit Opeunit_arry[], int Opeunit_count);   //表达式求值

int Check(string Exp_arry)
{//检查是否有非法字符，返回1表示不合法，0表示合法
	int Explength = Exp_arry.size(), i;
	for (i = 0; i < Explength; i++)
	{
		if (!Isoper(Exp_arry[i]) && Exp_arry[i] != '.' && !isdigit(Exp_arry[i]) && Exp_arry[i]!='e')
			return 1;
		if (isdigit(Exp_arry[i]))
		{
			int Dig_number = 0, Cur_positoin = i + 1;
			while (isdigit(Exp_arry[Cur_positoin]) || Exp_arry[Cur_positoin] == '.')
			{
				Dig_number++;
				Cur_positoin++;
			}
			if (Dig_number >= 16)//最多能够计算15位有效数字 
				return 1;
		}
	}
	return 0;
}

	int  Conver(struct Ope_unit Opeunit_arry[], string Exp_arry)
	{//将字符串操作单元化
		int Explength= Exp_arry.size();//处理字符替换后的表达式
		int n = Exp_arry.size();
		for (int i = 0; i < n; i++)
		{
			if (Exp_arry[i] == '\0')
			{
				Explength = i;
				break;
			}
		}
		int i, Opeunit_count = 0;
		for (i = 0; i < Explength; i++)
		{
			if (Isoper(Exp_arry[i]))//是操作符 
			{
				Opeunit_arry[Opeunit_count].flag = 0;
				Opeunit_arry[Opeunit_count++].oper = Exp_arry[i];
			}
			else//是操作数 
			{
				Opeunit_arry[Opeunit_count].flag = 1;
				char temp[Expmax_length];
				int k = 0;
				bool flag = true;
				int p;
				for (; isdigit(Exp_arry[i]) || Exp_arry[i] == '.' || Exp_arry[i]=='e' ; i++)
				{
					if (Exp_arry[i] == 'e')
					{
						p = k;
						flag = false;
					}
					temp[k++] = Exp_arry[i];
				}
				i--;
				temp[k] = '\0';
				if(flag)
				Opeunit_arry[Opeunit_count].real = atof(temp);//将字符转化为浮点数
				else
				{//处理科学计数法表示的数字
					char temp1[Expmax_length],temp2[Expmax_length];
					for (int i = 0; i <= p - 1; i++)
						temp1[i] = temp[i];
					temp1[p] = '\0';
					for (int i = p + 1; i < k; i++)
						temp2[i - p - 1] = temp[i];
					temp2[k - p - 1] = '\0';
					double a = atof(temp1);
					double b = atof(temp2);
					double sum = 1;
					sum *= a;
					for (int i = 0; i < b; i++)
						sum *= 10;
					Opeunit_arry[Opeunit_count].real = sum;
				}
			  //负数 
				if (Opeunit_count == 1 && Opeunit_arry[Opeunit_count - 1].flag == 0
					&& Opeunit_arry[Opeunit_count - 1].oper == '-')
				{
					Opeunit_arry[Opeunit_count - 1].flag = -1;
					Opeunit_arry[Opeunit_count].real *= -1;
				}// -9 
				if (Opeunit_count >= 2 && Opeunit_arry[Opeunit_count - 1].flag == 0
					&& Opeunit_arry[Opeunit_count - 1].oper == '-' && Opeunit_arry[Opeunit_count - 2].flag == 0
					&& Opeunit_arry[Opeunit_count - 2].oper != ')')
				{
					Opeunit_arry[Opeunit_count - 1].flag = -1;
					Opeunit_arry[Opeunit_count].real *= -1;
				}// )-9

				//正数 
				if (Opeunit_count == 1 && Opeunit_arry[Opeunit_count - 1].flag == 0
					&& Opeunit_arry[Opeunit_count - 1].oper == '+')
				{
					Opeunit_arry[Opeunit_count - 1].flag = -1;
				}// +9 
				if (Opeunit_count >= 2 && Opeunit_arry[Opeunit_count - 1].flag == 0
					&& Opeunit_arry[Opeunit_count - 1].oper == '+' && Opeunit_arry[Opeunit_count - 2].flag == 0
					&& Opeunit_arry[Opeunit_count - 2].oper != ')')
				{
					Opeunit_arry[Opeunit_count - 1].flag = -1;
				}// )+9
				Opeunit_count++;
			}
		}
		/*for (i = 0; i < Opeunit_count; i++)
		{//查看各操作单元是否正确,1是操作数，0是操作符
			if (Opeunit_arry[i].flag == 1)
			{
				cout << "i:" << i << endl;
				printf("该单元是操作数为：%lf\n", Opeunit_arry[i].real);
			}
			else if (Opeunit_arry[i].flag == 0)
			{
				cout << "i:" << i << endl;
				printf("该单元是操作符为：%c\n", Opeunit_arry[i].oper);
			}
			else
			{
				cout << "i:" << i << endl;
				printf("该单元是负号符为：%c\n", Opeunit_arry[i].oper);
			}
		}*/
		return Opeunit_count;
	}

void Evalua()
{//先调用Conver函数将字符串操作单元化，再调用Calculate函数计算结果并输出
	string Exp_arry;
	int flag = 0;//假设刚开始不合法，1表达式合法，0不合法 
	struct Ope_unit Opeunit_arry[Expmax_length];

	getchar();//吃掉一个换行符 
	printf("请输入四则运算表达式：\n");
	cin >> Exp_arry;
	flag = Check(Exp_arry);
	if (flag)
		printf("该表达式不合法！\n");
	else
	{
		int Opeunit_count = Conver(Opeunit_arry, Exp_arry);
		//cout <<"Opeunit_count:"<< Opeunit_count << endl;
		double ans = getAnswer(Opeunit_arry, Opeunit_count);
		printf("计算结果为：\n");
		cout << "ans:" << ans << endl;
	}
}

void Evalua_without_cin(string Exp_arry)
{//先调用Conver函数将字符串操作单元化，再调用Calculate函数计算结果并输出
	struct Ope_unit Opeunit_arry[Expmax_length];
	int Opeunit_count = Conver(Opeunit_arry, Exp_arry);
	//cout << "Opeunit_count:" << Opeunit_count << endl;
	double ans = getAnswer(Opeunit_arry, Opeunit_count);
	printf("计算结果为：\n");
	cout << "ans:" << ans << endl;
}

//老版本
/*double Calculate(struct Ope_unit Opeunit_arry[], int Opeunit_count)
{//根据运算规则，利用栈进行计算
	int i, dS_pointer = 0, oS_pointer = 0;//dS_pointer为操作数栈顶指示器，oS_pointer为操作符栈顶指示器 
	double Dig_stack[Expmax_length];//操作数栈（顺序存储结构） 
	char   Ope_stack[Expmax_length];//操作符栈 

	for (i = 0; i < Opeunit_count; i++)
	{
		if (Opeunit_arry[i].flag != -1)
		{
			if (Opeunit_arry[i].flag)//是操作数 
			{
				Dig_stack[dS_pointer++] = Opeunit_arry[i].real;//入操作数栈 
				//printf("%lf\n",Digit[dS_pointer-1]);
			}
			else//是操作符 + - * / ( ) ^ 
			{
				//操作符栈为空或者左括号 入栈
				if (oS_pointer == 0 || Opeunit_arry[i].oper == '(')
				{
					Ope_stack[oS_pointer++] = Opeunit_arry[i].oper;
					//printf("%oS_pointer\Ope_u_count",Operator[oS_pointer-1]);
				}
				else
				{
					if (Opeunit_arry[i].oper == ')')//是右括号将运算符一直出栈，直到遇见左括号 
					{
						oS_pointer--;//指向栈顶 
						dS_pointer--;//指向栈顶 
						while (Ope_stack[oS_pointer] != '(' && oS_pointer != 0)
						{
							Dig_stack[dS_pointer - 1] = Four_arithm(Dig_stack[dS_pointer - 1], Dig_stack[dS_pointer],
								Ope_stack[oS_pointer--]);//oS_pointer--为操作符出栈 

							dS_pointer--;//前一个操作数出栈 
							  //printf("操作数栈顶元素等于%lf\n",Digit[dS_pointer]);
						}
						oS_pointer--;//左括号出栈

						oS_pointer++;//恢复指向栈顶之上 
						dS_pointer++;
					}
										
					//不知道为什么要这么做

					else if (Ope_Compar(Opeunit_arry[i].oper, Ope_stack[oS_pointer - 1]))//和栈顶元素比较 
					{
						Ope_stack[oS_pointer++] = Opeunit_arry[i].oper;
						//printf("%oS_pointer\Ope_u_count",Operator[oS_pointer-1]);
					}
					else//运算符出栈，再将该操作符入栈 
					{
						oS_pointer--;//指向栈顶 
						dS_pointer--;//指向栈顶
						while (Ope_Compar(Opeunit_arry[i].oper, Ope_stack[oS_pointer]) == 0 && oS_pointer != -1)
						{//当前操作符比栈顶操作符优先级高 
							Dig_stack[dS_pointer - 1] = Four_arithm(Dig_stack[dS_pointer - 1], Dig_stack[dS_pointer],
								Ope_stack[oS_pointer--]);
							dS_pointer--;
							//printf("操作数栈顶元素等于%lf\n",Digit[dS_pointer]);
						}
						oS_pointer++;//恢复指向栈顶之上  
						dS_pointer++;
						Ope_stack[oS_pointer++] = Opeunit_arry[i].oper;
					}
				}
			}
		}
	}
	for(i=0;i<oS_pointer;i++)
4         printf("操作符栈%oS_pointer\Ope_u_count",Operator[i]);
	for(i=0;i<dS_pointer;i++)
6         printf("操作数栈%lf\n",Digit[i]);
	oS_pointer--;//指向栈顶元素 
	dS_pointer--;//指向栈顶元素 
	while (oS_pointer != -1)
	{
		Dig_stack[dS_pointer - 1] = Four_arithm(Dig_stack[dS_pointer - 1], Dig_stack[dS_pointer],
			Ope_stack[oS_pointer--]);//oS_pointer--为操作符出栈 
		dS_pointer--;//前一个操作数出栈 
		//printf("操作数栈顶元素为%lf\Ope_u_count",Digit[dS_pointer]);
	}
	//printf("%dS_pointer,%dS_pointer\n",oS_pointer,dS_pointer);
	return Dig_stack[0];
}*/

char Ope_Compar(char ope1, char ope2)
{//操作符运算优先级比较
	char list[] = {'#','+','-','*','/','^','(',')','='};
	char map[9][9] = {//先行后列，行比列的运算级优先级低为0，高为1 
		//        '#', '+', '-', '*', '/', '^', '(', ')', '=' 
		/* '#'*/ {'=', '<', '<', '<', '<', '<', '<', '<', '<' },
		/* '+'*/ {'>', '>', '>', '<', '<', '<', '<', '>', '>' },
		/* '-'*/ {'>', '>', '>', '<', '<', '<', '<', '>', '>' },
		/* '*'*/ {'>', '>', '>', '>', '>', '<', '<', '>', '>' },
		/* '/'*/ {'>', '>', '>', '>', '>', '<', '<', '>', '>' },
		/* '^'*/ {'>', '>', '>', '>', '>', '>', '<', '>', '>' },
		/* '('*/ {'>', '<', '<', '<', '<', '<', '<', '=', ' ' },
		/* ')'*/ {'>', '>', '>', '>', '>', '>', ' ', '>', '>' },
		/* '='*/ {'>', '<', '<', '<', '<', '<', '<', ' ', '=' }
	};  //优先级表格
	int i, j;
	for (i = 0; i < 9; i++)
		if (ope1 == list[i]) break;
	for (j = 0; j < 9; j++)
		if (ope2 == list[j]) break;
	return map[i][j];
}

double Four_arithm(double x, double y, char oper)
{//四则运算
	switch (oper)//保证不含其它运算符 
	{
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;//y不能为0 
	case '^':
	{
		double sum = x;
		for (int i = 1; i <= y - 1; i++)
			sum *= x;
		return sum;
	}

	default: return 0;
	}
}

int  Isoper(char ch)
{//判断合法字符  + - * / ( ) =
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=' || ch == '^')
		return 1;
	return 0;
}

void printstack_double(stack<double> a)
{
	double tmp[100];
	int n = a.size();
	if (n == 0)
		cout << "操作数栈：empty" << endl;
	else
	{
		for (int i = 0; i < n; i++)
		{
			tmp[i] = a.top();
			a.pop();
		}
		for (int i = n - 1; i >= 0; i--)
		{
			a.push(tmp[i]);
		}
		cout << "操作数栈：";
		for (int i = n - 1; i >= 0; i--)
			cout << tmp[i] << " ";
		cout << endl;
	}
}

void printstack_char(stack<char> a)
{
	char tmp[100];
	int n = a.size();
	if (n == 0)
		cout << "操作符栈：empty" << endl;
	else
	{
		for (int i = 0; i < n; i++)
		{
			tmp[i] = a.top();
			a.pop();
		}
		for (int i = n - 1; i >= 0; i--)
		{
			a.push(tmp[i]);
		}
		cout << "操作符栈：";
		for (int i = n - 1; i >= 0; i--)
			cout << tmp[i] << " ";
		cout << endl;
	}
}

double getAnswer(struct Ope_unit Opeunit_arry[], int Opeunit_count)   //表达式求值
{
	//cout << "开始运算" << endl;
	opter.push('#');      //首先将'#'入栈opte
	int i = 0;
	while (i < Opeunit_count )   //终止条件
	{
		//cout << "haha" << endl;
		//cout << "i:" << i << endl;
		//printstack_double(opval);
		//printstack_char(opter);
		//cout<<"check:"<< Opeunit_arry[3].oper<<endl;
		if (Opeunit_arry[i].flag != -1)
		{
			if (Opeunit_arry[i].flag == 1)
			{
				opval.push(Opeunit_arry[i].real);     //将c对应的数值入栈opval
				i++;
			}
			else if (Opeunit_arry[i].flag == 0)
			{
				//符号栈为空或者左括号入栈
				if (opter.top() == '#' || Opeunit_arry[i].oper == '(')
				{
					opter.push(Opeunit_arry[i].oper);
					i++;
				}
				else
				{//如果是右括号入栈
					if (Opeunit_arry[i].oper == ')')
					{
						/*if (opter.top == '#')
						{
							i++;
							continue;
						}*/
						while (opter.top() != '('&&!opter.empty())
						{
							char theta = opter.top();
							opter.pop();
							double a = opval.top();
							//cout << a << "!!!!!!!!!!!!!!!!" << endl;
							opval.pop();
							double b = opval.top();
							//cout << b <<"!!!!!!!!!!!!!!!!!!"<< endl;
							opval.pop();
							//cout << "神奇的运算结果是：" << Four_arithm(b, a, theta) << endl;
							opval.push(Four_arithm(b, a, theta));
						}
						if (opter.top() == '(')
						{
							//cout << "haha" << endl;
							opter.pop();
							i++;
							continue;
						}
						opter.pop();
					}
					switch (Ope_Compar(opter.top(), Opeunit_arry[i].oper))   //获取运算符栈opter栈顶元素与c之间的优先级，用'>'，'<'，'='表示
					{
					case '<':               //<则将c入栈opter
						opter.push(Opeunit_arry[i].oper);
						i++;
						break;
					case '=':               //=将opter栈顶元素弹出，用于括号的处理
						opter.pop();
						i++;
						break;
					case '>':               //>则计算
						char theta = opter.top();
						opter.pop();
						double a = opval.top();
						opval.pop();
						double b = opval.top();
						opval.pop();
						/*cout << "haha" << endl;
						cout <<"a:"<< a << endl;
						cout << "b:" << b << endl;
						cout << "theta:" << theta << endl;*/
						double tmp = Four_arithm(b, a, theta);
						opval.push(tmp);
					}
				}

			}
		}
		else
			i++;
		//cout << "arrivehere" << endl;
		//cout << "opval.top():" << opval.top() << endl;
		//cout << "opter.top():" << opter.top() << endl;
	}
	while (opter.top()!= '#')
	{
		char theta = opter.top();
		opter.pop();
		double a = opval.top();
		opval.pop();
		double b = opval.top();
		opval.pop();
		opval.push(Four_arithm(b, a, theta));
	}
	//cout << "opval.top:" << opval.top() << endl;
	return opval.top();   //返回opval栈顶元素的值
}
//-----------------------------------------------------------------------------

void strreplace(string &a, string &b, string &c)
{//字符串替换
	int d[100];
	int k = 0;
	int la = a.size(), lb = b.size(), lc = c.size();
	for (int i = 0; i < la; i++)
	{
		int tmp = 0;
		for (int j = 0; j < lb; j++)
		{
			if (a[i + j] == b[j])
				tmp++;
		}
		if (tmp == lb)
		{
			d[k++] = i;

		}
	}
	int dis = lb - lc;
	if (dis >= 0)
	{
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < lc; j++)
				a[d[i] + j] = c[j];
		}
		for (int i = k - 1; i >= 0; i--)
		{
			for (int j = d[i] + lc; j < la - dis; j++)
			{
				a[j] = a[j + dis];
			}
			la -= dis;
		}
		a[la] = '\0';
	}
	else
	{
		dis = lc - lb;
		a.resize(la + k * dis);
		la = a.size();
		for (int i = 0; i < k; i++)
		{
			int tmp = d[i];
			for (int j = la - 1; j >= tmp + lb + dis; j--)
			{
				a[j] = a[j - dis];
			}
		}
		for (int i = 0; i < k; i++)
		{
			for (int j = d[i]; j < d[i] + lc; j++)
			{
				a[j] = c[j - d[i]];
			}
		}
		a[la] = '\0';
	}
	return;
}

void Evalua_x()
{//先调用Conver函数将字符串操作单元化，再调用Calculate函数计算结果并输出
	string Exp_arry;
	struct Ope_unit Opeunit_arry[Expmax_length];

	getchar();//吃掉一个换行符 
	cout << "请输入自变量：" << endl;
	string x;
	cin >> x;
	cout << "请给自变量赋值：" << endl;
	string n;
	cin >> n;
	printf("请输入四则运算表达式：\n");
	cin >> Exp_arry;
	strreplace(Exp_arry, x, n);
	//cout << Exp_arry << endl;
	int Opeunit_count = Conver(Opeunit_arry, Exp_arry);
	double ans = getAnswer(Opeunit_arry, Opeunit_count);
	//cout << "答案是！！！！！！！！！！！！！！" << ans << endl;
	printf("计算结果为：\n");
	cout << ans << endl;
}

struct function
{
	string name;
	string fomula;
	string var;
};

function f;
//????????????????????????????????????????????????????????????????????????????????????????????????
/*typedef struct save_his
{
	string fomula;
	string name;
	save_his* next;
}*node_save;

node_save L;

node_save tmp = L;*/

string his[100][2];
int mark = 0;

void def()
{
	getchar();
	string a;
	string b;
	getline(cin, a);
	getline(cin, b);
	int la = a.size(), lb = b.size();
	//cout << la << endl;
	//cout << lb << endl;
	int pos[100];
	int k = 0;
	bool flag = false;
	for (int i = 0; i < la; i++)
	{
		if (a[i] == ' ')
			pos[k++] = i;
		if (a[i] == '('&&flag == false)
			pos[k++] = i;
		if (a[i] == ')'&&flag == false)
		{
			pos[k++] = i;
			flag = true;
		}
		if (a[i] == ';')
			pos[k++] = i;
	}
	f.name = a.substr(pos[0] + 1, pos[1] - pos[0] - 1);
	f.var = a.substr(pos[1] + 1, pos[2] - pos[1] - 1);
	f.fomula = a.substr(pos[2] + 2, pos[3] - pos[2] - 2);
	string value;
	int m, n;
	for (int i = 0; i < lb; i++)
	{
		if (b[i] == '(')
			m = i;
		if (b[i] == ')')
		{
			n = i;
			break;
		}
	}
	value = b.substr(m + 1, n - m - 1);

	string x = "x";
	strreplace(f.fomula, f.var,x);
	his[mark][0] = f.name;
	his[mark][1] = f.fomula;

	/*node_save p= (save_his*)malloc(sizeof(save_his));
	p->fomula = f.fomula;
	p->name = f.name;
	p->next = tmp->next;
	tmp->next = p;
	tmp = tmp->next;*/
	
	strreplace(f.fomula, x, value);
	Evalua_without_cin(f.fomula);
}

void DEF()
{
	function tmp;
	getchar();
	cout << "定义函数：" << endl;
	string a;
	getline(cin, a);
	int la = a.size();
	int pos[100];
	int k = 0;
	bool flag = false;
	for (int i = 0; i < la; i++)
	{
		if (a[i] == ' ')
			pos[k++] = i;
		if (a[i] == '('&&flag == false)
			pos[k++] = i;
		if (a[i] == ')'&&flag == false)
		{
			pos[k++] = i;
			flag = true;
		}
		if (a[i] == ';')
			pos[k++] = i;
	}
	tmp.name = a.substr(pos[0] + 1, pos[1] - pos[0] - 1);
	tmp.var = a.substr(pos[1] + 1, pos[2] - pos[1] - 1);
	tmp.fomula = a.substr(pos[2] + 2, pos[3] - pos[2] - 2);
	his[mark][0] = tmp.name;
	his[mark][1] = tmp.fomula;
	mark++;
}

void add_brackets_x(string &a)
{
	int n = a.size();
	a.resize(n + 3);
	a[n] = '(';
	a[n + 1] = 'x';
	a[n + 2] = ')';
	return;
}

void change()
{
	for (int i = 0; i < mark; i++)
		for (int j = i + 1; j < mark; j++)
		{
			if (his[j][1].find(his[i][0]) != 0)
			{
				string tmp = his[i][0];
				//cout << "tmp1:" << tmp << endl;
				add_brackets_x(tmp);
				//cout << "tmp2:" << tmp << endl;
				strreplace(his[j][1], tmp, his[i][1]);
				//cout << his[i][1] << endl;
				//cout << "test:" << his[j][1] << endl;
				continue;
			}
		}
}

void cout_DEF()
{
	for (int i = 0; i < mark; i++)
	{
		cout << his[i][0] << endl;
		cout << his[i][1] << endl;
	}
}

void run()
{
	string fomula;
	string name;
	string value;
	string x = "x";
	cout << "请输入你要查找的历史函数名：" << endl;
	cin >> name;
	int flag = 0;
	for (int i = 0; i < mark; i++)
	{
		//cout << his[i][0] << endl;
		//cout << his[i][1] << endl;
		if (name.compare(his[i][0])==0)
		{
			//cout << "i:" << i << endl;
			fomula = his[i][1];
			//cout << fomula << endl;
			flag = 1;
			break;
		}
	}
	if (flag==0)
		cout << "未查找到该函数" << endl;
	else
	{
		cout << "查找成功，请输入自变量的值：" << endl;
		cin >> value;
		strreplace(fomula, x, value);
		//cout << fomula << endl;
		Evalua_without_cin(fomula);
	}
}

function F, G;

void add_brackets(string &a)
{
	int n = a.size();
	a.resize(n + 2);
	for (int i = n; i >= 1; i--)
	{
		a[i] = a[i - 1];
	}
	a[n + 1] = ')';
	a[0] = '(';
	return;
}

void call_function()
{
	string a, b,c;
	//cout << "请定义函数f:" << endl;
	getchar();
	getline(cin, a);
	//cout << "请定义函数g:" << endl;
	getchar();
	getline(cin, b);
	getchar();
	getline(cin, c);
	int la = a.size(), lb = b.size(),lc=c.size();
	int pos[100];
	int k = 0;
	for (int i = 0; i < la; i++)
	{
		if (a[i] == ' ')
			pos[k++] = i;
		if (a[i] == '(')
			pos[k++] = i;
		if (a[i] == ')')
			pos[k++] = i;
		if (a[i] == ';')
			pos[k++] = i;
	}
	F.name = a.substr(pos[0] + 1, pos[1] - pos[0] - 1);
	F.var = a.substr(pos[1] + 1, pos[2] - pos[1] - 1);
	F.fomula = a.substr(pos[2] + 2, pos[3] - pos[2] - 2);
	k = 0;
	for (int i = 0; i < lb; i++)
	{
		if (b[i] == ' ')
			pos[k++] = i;
		if (b[i] == '(')
			pos[k++] = i;
		if (b[i] == ')')
			pos[k++] = i;
	}
	G.name = b.substr(pos[0] + 1, pos[1] - pos[0] - 1);
	G.var = b.substr(pos[1] + 1, pos[2] - pos[1] - 1);
	for (int i = 0; i < lb; i++)
	{
		string tmp = b.substr(i, 1);
		if (tmp.compare(F.name))
		{
			pos[k++] = i;
		}
	}
	G.fomula = b.substr(pos[2] + 2, pos[3] - pos[2]-2);
	/*cout << G.name << endl;
	cout << G.var << endl;
	cout << G.fomula << endl;*/
	string value;
	int m, n;
	for (int i = 0; i < lc; i++)
	{
		if (c[i] == '(')
			m = i;
		if (c[i] == ')')
		{
			n = i;
			break;
		}
	}
	value = c.substr(m + 1, n - m - 1);
	add_brackets(F.fomula);
	//cout << F.fomula << endl;
	strreplace(G.fomula, F.name, F.fomula);
	strreplace(G.fomula, F.var, value);
	//cout << G.fomula << endl;
	Evalua_without_cin(G.fomula);
}

typedef struct dalao {
	int gpa;
}Gan_Zeyu;

struct matrix
{
	int n;
	int m;
	double v[100][100];
};

matrix a, b,c;

#define MAX_ROW 8

double calculate(double[][MAX_ROW], int);
void exchange(double[][MAX_ROW], int, int);

void exchange(double matrix[MAX_ROW][MAX_ROW], int dim, int flag)
{
	int i, j;

	for (i = 0; i < dim - 1; i++)
		for (j = 0; j < dim; j++)
			matrix[i][j] = matrix[i + 1][j];

	for (j = flag; j < dim; j++)
		for (i = 0; i < dim - 1; i++)
			matrix[i][j] = matrix[i][j + 1];

	return;
}

double calculate(double matrix[MAX_ROW][MAX_ROW], int dim)
{
	double replica[MAX_ROW][MAX_ROW];
	double vector[10];
	double result = 0;
	int i, j, k;

	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			replica[i][j] = matrix[i][j];
	for (i = 0; i < dim; i++)
		vector[i] = matrix[0][i];

	if (dim == 1)
		result = matrix[0][0];
	else
		for (i = 0; i < dim; i++) {
			exchange(matrix, dim, i);
			if (i % 2 == 0)
				result += vector[i] * calculate(matrix, dim - 1);
			else
				result -= vector[i] * calculate(matrix, dim - 1);
			for (j = 0; j < dim; j++)
				for (k = 0; k < dim; k++)
					matrix[j][k] = replica[j][k];
		}

	return result;
}

void cal_det()
{
	double matrix[MAX_ROW][MAX_ROW];
	double det_value;
	int row, i, j;

	cout << "请输入方阵的阶数：" << endl;
	cin >> row;
	cout << "请输入方阵：" << endl;
	for (i = 0; i < row; i++)
		for (j = 0; j < row; j++)
			cin >> matrix[i][j];
	det_value = calculate(matrix, row);
	cout << "行列式的值为：";
	cout << det_value << endl;
	return;
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//纯C里面定义的布尔类型
typedef enum { False = 0, True = 1 }Bool;
//定义矩阵元素的类型为matrixType
typedef double matrixType;

//此结构体用来表示矩阵，其中row为行，column为列，height为高，array用来存放矩阵元素(用一维来模拟二维/三维)
typedef struct
{
	unsigned  row, column, height;
	matrixType *array; //使用时，必须对*array进行初始化
}Matrix;

//---------下面是QR分解，求解线性方程所用到的一些函数-----------
/*
matrix为要设置大小并分配内存的矩阵，row、column、height分别为行，列，高。
函数调用成功则则返回true,否则返回false
*/
Bool SetMatrixSize(Matrix *matrix, const unsigned row, const unsigned column, const unsigned height)
{
	unsigned size = row * column * height * sizeof(matrixType);
	if (size <= 0)
	{
		return False;
	}

	matrix->array = (matrixType*)malloc(size);

	//如果分配内存成功
	if (matrix->array)
	{
		matrix->row = row;
		matrix->column = column;
		matrix->height = height;
		return True;
	}
	else
	{
		matrix->row = matrix->column = matrix->height = 0;
		return False;
	}
}

//设置Matrix矩阵中的所有元素大小为ele
void SetMatrixEle(Matrix *matrix, matrixType ele)
{
	unsigned size = matrix->row * matrix->column * matrix->height;
	unsigned i;

	for (i = 0; i < size; ++i)
	{
		matrix->array[i] = ele;
	}
}

//设置Matrix矩阵中的所有元素大小为0
void SetMatrixZero(Matrix*matrix)
{
	SetMatrixEle(matrix, 0);
}

//判断矩阵是否为空，若为空则返回1，否则返回0
Bool IsNullMatrix(const Matrix* matrix)
{
	unsigned size = matrix->row * matrix->column * matrix->column;

	if (size <= 0 || matrix->array == NULL)
	{
		return True;
	}
	return False;
}

//销毁矩阵，即释放为矩阵动态分配的内存,并将矩阵的长宽高置0
void DestroyMatrix(Matrix *matrix)
{
	if (!IsNullMatrix(matrix))
	{
		free(matrix->array);
		matrix->array = NULL;
	}

	matrix->row = matrix->column = matrix->height = 0;
}

//计算矩阵可容纳元素个数，即return row*column*height
unsigned MatrixCapacity(const Matrix*matrix)
{
	return matrix->row * matrix->column * matrix->height;
}


//||matrix||_2  求A矩阵的2范数
matrixType MatrixNorm2(const Matrix *matrix)
{
	unsigned size = matrix->row * matrix->column *matrix->height;
	unsigned i;
	matrixType norm = 0;

	for (i = 0; i < size; ++i)
	{
		norm += (matrix->array[i]) *(matrix->array[i]);
	}

	return (matrixType)sqrt(norm);
}

//matrixB = matrix(:,:,height)即拷贝三维矩阵的某层，若matrix为二维矩阵，需将height设置为0
Bool CopyMatrix(Matrix* matrixB, Matrix *matrix, unsigned height)
{
	unsigned size, i;
	Matrix matrixA;

	//判断height值是否正确
	if (height < 0 || height >= matrix->height)
	{
		printf("ERROR: CopyMatrix() parameter error！\n");
		return False;
	}

	//将matrix(:,:,height) 转换为二维矩阵matrixA
	matrixA.row = matrix->row;
	matrixA.column = matrix->column;
	matrixA.height = 1;
	matrixA.array = matrix->array + height * matrix->row * matrix->column;

	//判断两矩阵指向的内存是否相等
	if (matrixA.array == matrixB->array)
	{
		return True;
	}

	//计算matrixA的容量
	size = MatrixCapacity(&matrixA);
	//判断matrixB的容量与matrixA的容量是否相等
	if (MatrixCapacity(matrixB) != size)
	{
		DestroyMatrix(matrixB);
		SetMatrixSize(matrixB, matrixA.row, matrixA.column, matrixA.height);
	}
	else
	{
		matrixB->row = matrixA.row;
		matrixB->column = matrixA.column;
		matrixB->height = matrixA.height;
	}

	for (i = 0; i < size; ++i)
	{
		matrixB->array[i] = matrixA.array[i];
	}

	return True;
}

//matrixC = matrixA * matrixB
Bool MatrixMulMatrix(Matrix *matrixC, const Matrix* matrixA, const Matrix* matrixB)
{
	size_t row_i, column_i, i;
	size_t indexA, indexB, indexC;
	matrixType temp;
	Matrix tempC;

	if (IsNullMatrix(matrixA) || IsNullMatrix(matrixB))
	{
		return False;
	}

	if (matrixA->column != matrixB->row)
	{
		return False;
	}

	if (MatrixCapacity(matrixC) != matrixA->row * matrixB->column)
	{
		SetMatrixSize(&tempC, matrixA->row, matrixB->column, 1);
	}
	else
	{
		tempC.array = matrixC->array;
		tempC.row = matrixA->row;
		tempC.column = matrixB->column;
		tempC.height = 1;
	}

	for (row_i = 0; row_i < tempC.row; ++row_i)
	{
		for (column_i = 0; column_i < tempC.column; ++column_i)
		{
			temp = 0;
			for (i = 0; i < matrixA->column; ++i)
			{
				indexA = row_i * matrixA->column + i;
				indexB = i * matrixB->column + column_i;

				temp += matrixA->array[indexA] * matrixB->array[indexB];
			}
			indexC = row_i * tempC.column + column_i;

			tempC.array[indexC] = temp;
		}
	}


	if (tempC.array != matrixC->array)
	{
		DestroyMatrix(matrixC);

		matrixC->array = tempC.array;
	}

	matrixC->row = tempC.row;
	matrixC->column = tempC.column;
	matrixC->height = tempC.height;



	return True;
}

//对vector中所有元素排序，sign= 0 时为升序，其余为降序
void SortVector(Matrix *vector, int sign)
{
	matrixType mid;
	int midIndex;
	int size = MatrixCapacity(vector);
	int i, j;

	if (0 == sign)
	{
		for (i = 0; i < size; ++i)
		{
			mid = vector->array[i];
			midIndex = i;
			for (j = i + 1; j < size; ++j)
			{
				if (mid > vector->array[j])
				{
					mid = vector->array[j];
					midIndex = j;
				}
			}

			vector->array[midIndex] = vector->array[i];
			vector->array[i] = mid;
		}
	}
	else
	{
		for (i = 0; i < size; ++i)
		{
			mid = vector->array[i];
			midIndex = i;
			for (j = i + 1; j < size; ++j)
			{
				if (mid < vector->array[j])
				{
					mid = vector->array[j];
					midIndex = j;
				}
			}

			vector->array[midIndex] = vector->array[i];
			vector->array[i] = mid;
		}
	}
}

//打印矩阵
void PrintMatrix(const Matrix *matrix)
{
	size_t row_i, column_i, height_i, index;

	for (height_i = 0; height_i < matrix->height; ++height_i)
	{
		//(matrix->height == 1) ? printf("[:,:] = \n") : printf("[%d,:,:] = \n", height_i);
		cout << endl;
		for (row_i = 0; row_i < matrix->row; ++row_i)
		{
			for (column_i = 0; column_i < matrix->column; ++column_i)
			{
				index = height_i * matrix->row * matrix->column + row_i * matrix->column + column_i;
				printf("%12.4g", matrix->array[index]);
			}
			printf("\n");
		}
	}
}

//----------------------QR分解-------------------------------------------

//将A分解为Q和R
void QR(Matrix *A, Matrix *Q, Matrix *R)
{
	unsigned  i, j, k, m;
	unsigned size;
	const unsigned N = A->row;
	matrixType temp;

	Matrix a, b;

	//如果A不是一个二维方阵，则提示错误，函数计算结束
	if (A->row != A->column || 1 != A->height)
	{
		printf("ERROE: QR() parameter A is not a square matrix!\n");
		return;
	}

	size = MatrixCapacity(A);
	if (MatrixCapacity(Q) != size)
	{
		DestroyMatrix(Q);
		SetMatrixSize(Q, A->row, A->column, A->height);
		SetMatrixZero(Q);
	}
	else
	{
		Q->row = A->row;
		Q->column = A->column;
		Q->height = A->height;
	}

	if (MatrixCapacity(R) != size)
	{
		DestroyMatrix(R);
		SetMatrixSize(R, A->row, A->column, A->height);
		SetMatrixZero(R);
	}
	else
	{
		R->row = A->row;
		R->column = A->column;
		R->height = A->height;
	}

	SetMatrixSize(&a, N, 1, 1);
	SetMatrixSize(&b, N, 1, 1);

	for (j = 0; j < N; ++j)
	{
		for (i = 0; i < N; ++i)
		{
			a.array[i] = b.array[i] = A->array[i * A->column + j];
		}

		for (k = 0; k < j; ++k)
		{
			R->array[k * R->column + j] = 0;

			for (m = 0; m < N; ++m)
			{
				R->array[k * R->column + j] += a.array[m] * Q->array[m * Q->column + k];
			}

			for (m = 0; m < N; ++m)
			{
				b.array[m] -= R->array[k * R->column + j] * Q->array[m * Q->column + k];
			}
		}

		temp = MatrixNorm2(&b);
		R->array[j * R->column + j] = temp;

		for (i = 0; i < N; ++i)
		{
			Q->array[i * Q->column + j] = b.array[i] / temp;
		}
	}

	DestroyMatrix(&a);
	DestroyMatrix(&b);
}

//----------------------使用特征值计算矩阵特征向量-----------------
//eigenVector为计算结果即矩阵A的特征向量
//eigenValue为矩阵A的所有特征值，
//A为要计算特征向量的矩阵
void Eigenvectors(Matrix *eigenVector, Matrix *A, Matrix *eigenValue)
{
	unsigned i, j, q;
	unsigned count;
	int m;
	const unsigned NUM = A->column;
	matrixType eValue;
	matrixType sum, midSum, mid;
	Matrix temp;

	SetMatrixSize(&temp, A->row, A->column, A->height);

	for (count = 0; count < NUM; ++count)
	{
		//计算特征值为eValue，求解特征向量时的系数矩阵
		eValue = eigenValue->array[count];
		CopyMatrix(&temp, A, 0);
		for (i = 0; i < temp.column; ++i)
		{
			temp.array[i * temp.column + i] -= eValue;
		}

		//将temp化为阶梯型矩阵
		for (i = 0; i < temp.row - 1; ++i)
		{
			mid = temp.array[i * temp.column + i];
			for (j = i; j < temp.column; ++j)
			{
				temp.array[i * temp.column + j] /= mid;
			}

			for (j = i + 1; j < temp.row; ++j)
			{
				mid = temp.array[j * temp.column + i];
				for (q = i; q < temp.column; ++q)
				{
					temp.array[j * temp.column + q] -= mid * temp.array[i * temp.column + q];
				}
			}
		}
		midSum = eigenVector->array[(eigenVector->row - 1) * eigenVector->column + count] = 1;
		for (m = temp.row - 2; m >= 0; --m)
		{
			sum = 0;
			for (j = m + 1; j < temp.column; ++j)
			{
				sum += temp.array[m * temp.column + j] * eigenVector->array[j * eigenVector->column + count];
			}
			sum = -sum / temp.array[m * temp.column + m];
			midSum += sum * sum;
			eigenVector->array[m * eigenVector->column + count] = sum;
		}

		midSum = sqrt(midSum);
		for (i = 0; i < eigenVector->row; ++i)
		{
			eigenVector->array[i * eigenVector->column + count] /= midSum;
		}
	}
	DestroyMatrix(&temp);
}

void cal_eigenvalue()
{
	const unsigned NUM = 50; //最大迭代次数

	int N=3;
	unsigned k;

	Matrix A, Q, R, temp;
	Matrix eValue;


	//分配内存
	SetMatrixSize(&A, N, N, 1);
	SetMatrixSize(&Q, A.row, A.column, A.height);
	SetMatrixSize(&R, A.row, A.column, A.height);
	SetMatrixSize(&temp, A.row, A.column, A.height);
	SetMatrixSize(&eValue, A.row, 1, 1);

	cout << "请输入方阵的的阶数:" << endl;
	cin >> N;
		cout << "请输入矩阵：" << endl;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> A.array[i*3+j];
		}

	//A设置为一个简单矩阵
	/*A.array[0] = -1;
	A.array[1] = 2;
	A.array[2] = 1;
	A.array[3] = 2;
	A.array[4] = 4;
	A.array[5] = -1;
	A.array[6] = 1;
	A.array[7] = 1;
	A.array[8] = -6;*/


	//拷贝A矩阵元素至temp
	CopyMatrix(&temp, &A, 0);

	//初始化Q、R所有元素为0
	SetMatrixZero(&Q);
	SetMatrixZero(&R);
	//使用QR分解求矩阵特征值
	for (k = 0; k < NUM; ++k)
	{
		QR(&temp, &Q, &R);
		MatrixMulMatrix(&temp, &R, &Q);
	}
	//获取特征值，将之存储于eValue
	for (k = 0; k < temp.column; ++k)
	{
		eValue.array[k] = temp.array[k * temp.column + k];
	}

	//对特征值按照降序排序
	SortVector(&eValue, 1);

	//根据特征值eValue，原始矩阵求解矩阵特征向量Q
	Eigenvectors(&Q, &A, &eValue);

	//打印特征值
	printf("特征值：");
	PrintMatrix(&eValue);

	//打印特征向量
	/*printf("特征向量");
	PrintMatrix(&Q);
	DestroyMatrix(&A);
	DestroyMatrix(&R);
	DestroyMatrix(&Q);
	DestroyMatrix(&eValue);
	DestroyMatrix(&temp);*/

	return ;
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void cal_matrix()
{
	cout << "请输入你要进行的操作：" << endl;
	cout << "1.矩阵加法" << endl;
	cout << "2.矩阵减法" << endl;
	cout << "3.矩阵乘法" << endl;
	cout << "4.矩阵转置" << endl;
	cout << "5.求矩阵的特征值" << endl;
	cout << "6.求矩阵的行列式的值" << endl;
	int k;
	cin >> k;
	if (k == 1||k==2||k==3)
	{
		cout << "请先输入第一个矩阵的行数与列数然后初始化矩阵：" << endl;
		cin >> a.n >> a.m;
		for (int i = 0; i < a.n; i++)
			for (int j = 0; j < a.m; j++)
				cin >> a.v[i][j];
		cout << "请先输入第二个矩阵的行数与列数然后初始化矩阵：" << endl;
		cin >> b.n >> b.m;
		for (int i = 0; i < b.n; i++)
			for (int j = 0; j < b.m; j++)
				cin >> b.v[i][j];
		if (k == 1)
		{
			for (int i = 0; i < a.n; i++)
				for (int j = 0; j < a.m; j++)
					a.v[i][j] += b.v[i][j];
			cout << "结果为：" << endl;
			for (int i = 0; i < a.n; i++)
			{
				for (int j = 0; j < a.m; j++)
					cout << a.v[i][j] << ' ';
				cout << endl;
			}
		}
		else if (k == 2)
		{
			for (int i = 0; i < a.n; i++)
				for (int j = 0; j < a.m; j++)
					a.v[i][j] -= b.v[i][j];
			cout << "结果为：" << endl;
			for (int i = 0; i < a.n; i++)
			{
				for (int j = 0; j < a.m; j++)
					cout << a.v[i][j] << ' ';
				cout << endl;
			}
		}
		else
		{
			c.n = a.n;
			c.m = b.m;
			for(int i=0;i<a.n;i++)
				for (int j = 0; j < b.m; j++)
				{
					double sum = 0;
					for (int k = 0; k < a.m; k++)
						sum += a.v[i][k] * b.v[k][j];
					c.v[i][j] = sum;
				}
			cout << "结果为：" << endl;
			for (int i = 0; i < c.n; i++)
			{
				for (int j = 0; j < c.m; j++)
					cout << c.v[i][j] << ' ';
				cout << endl;
			}
		}
	}
	else if (k == 4)//矩阵的转置
	{
		cout << "请先输入矩阵的行数与列数然后初始化矩阵：" << endl;
		cin >> a.n >> a.m;
		for (int i = 0; i < a.n; i++)
			for (int j = 0; j < a.m; j++)
				cin >> a.v[i][j];
		if (k == 4)
		{
			b.n = a.m;
			b.m = a.n;
			for (int i = 0; i < b.n; i++)
				for (int j = 0; j < b.m; j++)
				{
					b.v[i][j] = a.v[j][i];
				}
			cout << "结果为：" << endl;
			for (int i = 0; i < b.n; i++)
			{
				for (int j = 0; j < b.m; j++)
					cout << b.v[i][j] << ' ';
				cout << endl;
			}
		}
	}
	else if (k == 5)//特征值
	{
		cal_eigenvalue();
	}
	else//行列式
	{
		cal_det();
	}
}

void choose(int k)
{
	switch (k)
	{
	case 1:
		cal_vector();
		system("pause");
		//(x2y+1)*(x2y+2.0)/x2y;
		//x2y=3;
		//(-18)*((-5.2)+(2*3-1))^3+8/2.3
		break;
	case 2:
		cal_poly_sequence();
		system("pause");
		break;
	case 3:
		cal_poly_list();
		system("pause");
		break;
	case 4:
		Evalua();
		system("pause");
		break;
	case 5:
		Evalua_x();
		system("pause");
		break;
	case 6:
		DEF();
		change();
		//cout_DEF();
		system("pause");
		/*
		DEF f(x)=(-18)*((-0.52e1)+(2*x-1))^x+8/2.3+2;
		DEF g(x)=(f(x)+2e1)^2;
		DEF h(x)=x+1;
		DEF p(x)=(h(x))^2;
		*/
		/*DEF f(X2)=3+4*X2;
		RUN f(5);*/
		break;
	case 7:
		//cout_DEF();
		run();
		/*
		RUN f(3)   
		RUN g(3)
		RUN p(2)
		*/
		system("pause");
		break;
	case 8:
		call_function();
		/*DEF f(X)=3+4*X;
		DEF g(x)=3+4*f(x);
		RUN g(5);*/
		system("pause");
		break;
	case 9:
		cal_matrix();
		system("pause");
		break;
	}
}

void print_menu()
{
	cout << "请选择你需要计算的操作的序号：" << endl;
	cout << "1.向量的加减、夹角余弦计算" << endl;
	cout << "2.一元多项式的加减乘、导数计算(sq)" << endl;
	cout << "3.一元多项式的加减乘、导数计算(list)" << endl;
	cout << "4.四则运算表达式求值" << endl;
	cout << "5.含单变量的表达式求值" << endl;
	cout << "6.定义并运行简单函数" << endl;
	cout << "7.查找历史函数" << endl;
	cout << "8.函数的调用" << endl;
	cout << "9.矩阵的运算" << endl;
}

int main()
{
	int k;
	while (true)
	{
		print_menu();
		cin >> k;
		choose(k);
		system("cls");
	}
	return 0;
}

