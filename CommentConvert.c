#define _CRT_SECURE_NO_WARNINGS 1

#include"CommentConvert.h"



void CommentConvert(FILE *PRead, FILE *PWrite)
{
	//״̬��  ���״̬
	//   ��״̬  cע��״̬   c++״̬   eof״̬
	State state = NUL_State;
	while (state != END_State)         //���ļ�δ����ʱ
	{
		switch (state)
		{
			case NUL_State:
				DO_NUL_State(PRead, PWrite, &state);
				break;
			case C_State:
				DO_C_State(PRead, PWrite, &state);
				break;
			case CPP_State:
				DO_CPP_State(PRead, PWrite, &state);
				break;	
		}
	}	
}


void DO_NUL_State(FILE *PRead, FILE *PWrite, State *PState)
{
	int first = fgetc(PRead);
	switch (first)
	{
		case '/':                  //ע�͵Ŀ�ʼ
		{
			int second = fgetc(PRead);
			switch (second)
			{
				//      // /* 
				case'*':                          //cע�Ϳ�ʼ
				{
					fputc('/', PWrite);
					fputc('/', PWrite);
					*PState = C_State;
				}
					break;
				case'/':						//c++ע�Ϳ�ʼ
				{
					fputc(first, PWrite);
					fputc(second, PWrite);
					*PState = CPP_State;
				}
					break;
				default:                      //������������
				{
					fputc(first, PWrite);
					ungetc(second, PRead);
				}
					break;
			}
		}
			break;
		case EOF:                  //�ļ��Ľ���
			*PState = END_State;
			break;
		default:                    //��������
		{
			fputc(first, PWrite);
		}
			break;
	}
}


void DO_C_State(FILE *PRead, FILE *PWrite, State *Pstate)       //cע�͵Ĵ���
{
	int first = fgetc(PRead);
	//        a   */   **/    */i
	switch (first)
	{
		case '*':
		{
			int second = fgetc(PRead);
			switch (second)
			{
				case '/':                          //cע�ͽ���
				{
					int third = fgetc(PRead);
					if (third == '\n')
					{
						fputc(third, PWrite);
					}
					else                        //���ǵ���������cע�͵����� ����  /* int a = 1; */  /* int b = 1;*/   �����Ƿ�������
					{
						fputc('\n', PWrite);
						ungetc(third, PRead);
					}
					*Pstate = NUL_State;
				}
					break;
				case '*':                      //   **/  ******/   ������
				{
					fputc(first, PWrite);
					ungetc(second, PRead);
				}
					break;
				default:                      //������������
				{
					fputc(first, PWrite);
					ungetc(second, PRead);
				}
					break;
			}
		}
			break;
		case '\n':             //����ע��
		{
			fputc(first, PWrite);
			fputc('/', PWrite);
			fputc('/', PWrite);
		}
			break;
		default:
		{
			fputc(first, PWrite);
		}
			break;
	}
}


void DO_CPP_State(FILE *PRead, FILE *PWrite, State *PState)
{
	int first = fgetc(PRead);
	switch (first)
	{
		case '\n':                       //c++ע�ͽ���
		{
			fputc(first, PWrite);
			*PState = NUL_State;
		}
			break; 
		case EOF:                 //�ļ�β
			*PState = END_State;
			break;
		default:                         //������������
			fputc(first, PWrite);
			break;

	}
}
