// 1.һ�����
int num = 0;
// int i = 0; 

// 2.��������
// int i = 0; 
int j = 0;
// int i = 0; 
int j = 0;

// 3.ƥ������
//int i = 0;/*xxxxx

// 4.����ע������
//
//int i=0;
//int j = 0;
//int k = 0;
//
int k = 0;

// 5.����ע������
//
//

// 6.������**/����
//*

// 7.C++ע������
// /*xxxxxxxxxxxx*/


2/3                     //��������������ֻ����һ��/�����


//����һ�δ���
//  ��δ���ֻ��������
//  ע��Ϊ��ӵĸ������
//
int Fib(int n)         
{
	int ret = 0;   ////retΪ����ֵ//
int i = 0;
	int count0 = 1;  //**count0Ϊ��n-2��fib��ֵ**
	int count1 = 0;  //**count0Ϊ:**
 //��n-2��fib��ֵ**
	for (i = 0; i < n; i++)   //  /*�ӵ�һ����ʼ����*/
	{
		//�ӵ�һ��
		//��ʼ
		//����ret��ֵ��
ret = count0 + count1;
		count0 = count1;    //��count0����i�仯/*
		count1 = ret;
	}
	return ret;       //������õĵ�n��fib��ֵ   /**/
}



