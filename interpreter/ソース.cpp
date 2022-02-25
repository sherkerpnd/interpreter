#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	struct stack {
		int i;
		float f;
		double d;
		char s[100];
		char hensu[10];
		char kata[10];
		stack* next;
	};
	int kcnt = 0, ktrace = 0, kc = 0;
	int kbuf = 0;
	char khai[20][10] = { "\0" };
	double ifa = 0, ifb = 0;
	stack* p = NULL, * start = NULL, * trace = NULL, * buffer = NULL, * buffer2 = NULL, * buffer3 = NULL, * buffer4 = NULL, * buffer5 = NULL;
	char buf[100] = { "\0" };
	char hantei = { '\0' };
	char semi[2] = { "\0" };
	char equal[10], per[5], h[10], decrement[3], h2[10];
	int len=0,n=0 ;
	bool flag = false,flag2 = true,dflag = false;

	printf("型作成時は初期化してください,型作成例^int n = 5 ;^\n");
	printf("scanf使用例 ^ scanf ％d n ; ^ \n");
	printf("printf使用例 ^ printf ％d n ; ^ \n");
	printf("if文使用例 ^ if a >= 10 (波かっこ)a = 10 + a; (波かっこ) ^ \n");
	printf("演算子使用例 ^ n = 30 * 40 + 20 / 5 ; ^ \n");
	printf("プログラム終了時 ^exit^\n");
	while (1)
	{
		scanf("%s", buf);
		/*ここからbufが型名だった時*/
		if (strncmp(buf,"int",3)==0 || strncmp(buf,"char",4)==0 || strncmp(buf,"float",5)==0 || strncmp(buf,"double",6)==0 /* || buf == "struct"*/)
		{
			if (flag == false)
			{
				p = (stack*)malloc(sizeof(stack));
			}
			if (flag == true)
			{
				p->next = (stack*)malloc(sizeof(stack));
				p = p->next;
			}
			if (flag == false)
			{
				start = p;
			}
			scanf("%s", p->hensu);
			scanf("%s", equal);
			if (strncmp(buf, "int", 3) == 0)//int型
			{
				scanf("%d", &p->i);
				strncpy(p->kata, buf, 3);
			}
			else if (strncmp(buf, "char", 4) == 0)//char型
			{
				scanf("%s", p->s);
				strncpy(p->kata, buf, 4);
			}
			else if (strncmp(buf, "float", 5) == 0)//float型
			{
				scanf("%f", &p->f);
				strncpy(p->kata, buf, 5);
			}
			else if (strncmp(buf, "double", 6) == 0)//double型
			{
				scanf("%lf", &p->d);
				strncpy(p->kata, buf, 6);
			}
			scanf("%s", semi);
			flag = true;
			p->next = NULL;
			printf("登録されました\n");
		}
		/*ここまでbufが型名だった時*/
		/*ここからbufがprintfだった時*/
		else if (strncmp(buf, "printf", 5) == 0)
		{
			scanf("%s", per);
			scanf("%s", h);
			len = strlen(h);
			if (flag == true)
			{
				for (trace = start; strncmp(h, trace->hensu, len) != 0; trace = trace->next)
				{
					if (trace->next == NULL)
					{
						flag2 = false;
						break;
					}
				}
			}
			if (flag2 == true)
			{
				if (strncmp(per, "%d", 2) == 0)
					printf("%d\n", trace->i);
				else if (strncmp(per, "%s", 2) == 0)
					printf("%s\n", trace->s);
				else if (strncmp(per, "%f", 2) == 0)
					printf("%f\n", p->f);
				else if (strncmp(per, "%lf", 3) == 0)
					printf("%lf\n", p->d);
			}
			else if (flag2 == false || flag == false)
			{
				printf("見つかりませんでした\n");
			}
			scanf("%s", semi);
		}
		/*ここまでbufがprintfだった時*/
		/*ここからbufがscanfだった時*/
		else if (strncmp(buf, "scanf", 5) == 0)
		{
			scanf("%s", per);
			scanf("%s", h);
			len = strlen(h);
			scanf("%s", semi);

			if (flag == true)
			{
				for (trace = start; strncmp(h, trace->hensu, len) != 0; trace = trace->next)
				{
					if (trace->next == NULL)
					{
						flag2 = false;
						break;
					}
				}
			}
			if (flag2 == true)
			{
				printf("入力してください\n");
				if (strncmp(per, "%d", 2) == 0)
					scanf("%d", &trace->i);
				else if (strncmp(per, "%s", 2) == 0)
					scanf("%s", trace->s);
				else if (strncmp(per, "%f", 2) == 0)
					scanf("%f", &p->f);
				else if (strncmp(per, "%lf", 3) == 0)
					scanf("%lf", &p->d);
				printf("登録されました\n");
			}
			else if (flag2 == false || flag == false)
			{
				printf("見つかりませんでした\n");
			}
		}
		/*ここまでbufがscanfだった時*/
		/*ここからbufがifだった時*/
		else if (strncmp(buf, "if", 2) == 0)
		{
			scanf("%s", h);
			scanf("%s", decrement);
			scanf("%s", h2);
			len = strlen(h);
			if (h[0] >= 0x30 && h[0] <= 0x39)
			{
				ifa = atoi(h);
			}
			else
			{
				for (trace = start; strncmp(h, trace->hensu, len) != 0; trace = trace->next)
				{
					if (trace->next == NULL)
					{
						flag2 = false;
						break;
					}
				}
				if (flag2 == true)
				{
					if (strncmp(trace->kata, "int", 3) == 0)
					{
						ifa = trace->i;
					}
					else if (strncmp(trace->kata, "double", 6) == 0)
					{
						ifa = trace->d;
					}
					else if (strncmp(trace->kata, "float", 5) == 0)
					{
						ifa = trace->f;
					}
				}
			}
			len = strlen(h2);
			if (h2[0] >= 0x30 && h2[0] <= 0x39)
			{
				ifb = atoi(h2);
			}
			else
			{
				for (trace = start; strncmp(h2, trace->hensu, len) != 0; trace = trace->next)
				{
					if (trace->next == NULL)
					{
						flag2 = false;
						break;
					}
				}
				if (flag2 == true)
				{
					if (strncmp(trace->kata, "int", 3) == 0)
					{
						ifb = trace->i;
					}
					else if (strncmp(trace->kata, "double", 6) == 0)
					{
						ifb = trace->d;
					}
					else if (strncmp(trace->kata, "float", 5) == 0)
					{
						ifb = trace->f;
					}
				}
			}
			if (strncmp(decrement, ">=",2 ) == 0)
			{
				if (ifa >= ifb)
					dflag = true;
			}
			else if (strncmp(decrement, "<=",2 ) == 0)
			{
				if (ifa <= ifb)
					dflag = true;
			}
			else if (strncmp(decrement, "==", 2) == 0)
			{
				if (buffer->i == buffer2->i)
					dflag = true;
			}
			if (dflag == false)
			{
				printf("false\n");
			}
			if (dflag == true)
			{
				printf("true\n");

				scanf("%s", buf);
				while (1)
				{
					scanf("%s", buf);
					if (strncmp(buf, "}", 1) == 0)
					{
						printf("if文終了\n");
						break;
					}
					len = strlen(buf);
					for (trace = start; strncmp(buf, trace->hensu, len) != 0; trace = trace->next)
					{
						if (trace->next == NULL)
						{
							flag2 = false;
							break;
						}
					}
					if (flag2 == true)
					{
						buffer = trace;
					}
					scanf("%s", equal);
					while (1)
					{
						scanf("%s", khai[kcnt]);
						if (strncmp(khai[kcnt], ";", 1) == 0)
						{
							kcnt++;
							break;
						}
						kcnt++;
					}
					for (ktrace = 0; ktrace < kcnt; ktrace++)
					{
						if (strncmp(khai[ktrace], "*", 1) == 0 || strncmp(khai[ktrace], "/", 1) == 0 || strncmp(khai[ktrace], "%", 1) == 0){
						}
						else if (khai[ktrace][0] >= 0x30 && khai[ktrace][0] <= 0x39){
						}
						else if (strncmp(khai[ktrace], "+", 1) == 0 || strncmp(khai[ktrace], "-", 1) == 0){
						}
						else if (strncmp(khai[ktrace], ";", 1) == 0) {
						}
						else
						{
							len = strlen(khai[ktrace]);
							for (trace = start; strncmp(khai[ktrace], trace->hensu, len) != 0; trace = trace->next)
							{
								if (trace->next == NULL)
								{
									flag2 = false;
									break;
								}
							}
							if (flag2 == true)
							{
								if (strncmp(trace->kata, "int", 3) == 0)
								{
									ifb = trace->i;
								}
								else if (strncmp(trace->kata, "double", 6) == 0)
								{
									ifb = trace->d;
								}
								else if (strncmp(trace->kata, "float", 5) == 0)
								{
									ifb = trace->f;
								}
							}
							_itoa(ifb, khai[ktrace], 10);
						}
					}
					for (ktrace = 0; ktrace < kcnt; ktrace++)
					{
						if (strncmp(khai[ktrace], "*", 1) == 0 || strncmp(khai[ktrace], "/", 1) == 0 || strncmp(khai[ktrace], "%", 1) == 0)
						{
							if (strncmp(khai[ktrace], "*", 1) == 0)
							{
								_itoa(atoi(khai[ktrace - 1]) * atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
								//ktrace+2からの値をktraceから順に埋めていく↓
								for (kc = ktrace; kc < kcnt - 2; kc++)
								{
									strcpy(khai[kc], khai[kc + 2]);
								}
							}
							else if (strncmp(khai[ktrace], "/", 1) == 0)
							{
								_itoa(atoi(khai[ktrace - 1]) / atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
								//ktrace+2からの値をktraceから順に埋めていく↓
								for (kc = ktrace; kc < kcnt - 2; kc++)
								{
									strcpy(khai[kc], khai[kc + 2]);
								}
							}
							else if (strncmp(khai[ktrace], "%", 1) == 0)
							{
								_itoa(atoi(khai[ktrace - 1]) % atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
								//ktrace+2からの値をktraceから順に埋めていく↓
								for (kc = ktrace; kc < kcnt - 2; kc++)
								{
									strcpy(khai[kc], khai[kc + 2]);
								}
							}
							ktrace--;
							kcnt -= 2;
						}
						
					}
					for (ktrace = 0; ktrace < kcnt; ktrace++)
					{
						if (strncmp(khai[ktrace], "+", 1) == 0 || strncmp(khai[ktrace], "-", 1) == 0)
						{
							if (strncmp(khai[ktrace], "+", 1) == 0)
							{
								_itoa(atoi(khai[ktrace - 1]) + atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
								//ktrace+2からの値をktraceから順に埋めていく↓
								for (kc = ktrace; kc < kcnt - 2; kc++)
								{
									strcpy(khai[kc], khai[kc + 2]);
								}
							}
							else if (strncmp(khai[ktrace], "-", 1) == 0)
							{
								_itoa(atoi(khai[ktrace - 1]) - atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
								//ktrace+2からの値をktraceから順に埋めていく↓
								for (kc = ktrace; kc < kcnt - 2; kc++)
								{
									strcpy(khai[kc], khai[kc + 2]);
								}
							}
							ktrace--;
							kcnt -= 2;
						}
					}
					if (strncmp(buffer->kata, "int", 3) == 0)
					{
						buffer->i = atoi(khai[0]);
					}
					else if (strncmp(buffer->kata, "double", 6) == 0)
					{
						buffer->d = atoi(khai[0]);
					}
					else if (strncmp(buffer->kata, "float", 5) == 0)
					{
						buffer->f = atoi(khai[0]);
					}
					kcnt = 0;
					printf("計算終了\n");
				}
			}
		}
		/*ここまでbufがifだった時*/
		/*ここからbufがexitだった時*/
		else if (strncmp(buf, "exit", 4) == 0)break;
		/*ここまでbufがexitだった時*/
		/*ここからbufが変数だった場合*/
		else
		{
			len = strlen(buf);
			for (trace = start; strncmp(buf, trace->hensu, len) != 0; trace = trace->next)
			{
				if (trace->next == NULL)
				{
					flag2 = false;
					break;
				}
			}
			if (flag2 == true)
			{
				buffer = trace;
			}
			scanf("%s", equal);
				while (1)
				{
					scanf("%s", khai[kcnt]);
					if (strncmp(khai[kcnt], ";", 1) == 0)
					{
						kcnt++;
						break;
					}
					kcnt++;
				}
				for (ktrace = 0; ktrace < kcnt; ktrace++)
				{
					if (strncmp(khai[ktrace], "*", 1) == 0 || strncmp(khai[ktrace], "/", 1) == 0 || strncmp(khai[ktrace], "%", 1) == 0){
					}
					else if (khai[ktrace][0] >= 0x30 && khai[ktrace][0] <= 0x39){
					}
					else if (strncmp(khai[ktrace], "+", 1) == 0 || strncmp(khai[ktrace], "-", 1) == 0){
					}
					else if (strncmp(khai[ktrace], ";", 1) == 0){
					}
					else
					{
						len = strlen(khai[ktrace]);
						for (trace = start; strncmp(khai[ktrace], trace->hensu, len) != 0; trace = trace->next)
						{
							if (trace->next == NULL)
							{
								flag2 = false;
								break;
							}
						}
						if (flag2 == true)
						{
							if (strncmp(trace->kata, "int", 3) == 0)
							{
								ifb = trace->i;
							}
							else if (strncmp(trace->kata, "double", 6) == 0)
							{
								ifb = trace->d;
							}
							else if (strncmp(trace->kata, "float", 5) == 0)
							{
								ifb = trace->f;
							}
						}
						_itoa(ifb, khai[ktrace], 10);
					}
				}
				for (ktrace = 0; ktrace < kcnt; ktrace++)
				{
					if (strncmp(khai[ktrace], "*", 1) == 0 || strncmp(khai[ktrace], "/", 1) == 0 || strncmp(khai[ktrace], "%", 1) == 0)
					{
						if (strncmp(khai[ktrace], "*", 1) == 0)
						{
							_itoa(atoi(khai[ktrace - 1]) * atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
							//ktrace+2からの値をktraceから順に埋めていく↓
							for (kc = ktrace; kc < kcnt - 2; kc++)
							{
								strcpy(khai[kc], khai[kc + 2]);
							}
						}
						else if (strncmp(khai[ktrace], "/", 1) == 0)
						{
							_itoa(atoi(khai[ktrace - 1]) / atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
							//ktrace+2からの値をktraceから順に埋めていく↓
							for (kc = ktrace; kc < kcnt - 2; kc++)
							{
								strcpy(khai[kc], khai[kc + 2]);
							}
						}
						else if (strncmp(khai[ktrace], "%", 1) == 0)
						{
							_itoa(atoi(khai[ktrace - 1]) % atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
							//ktrace+2からの値をktraceから順に埋めていく↓
							for (kc = ktrace; kc < kcnt - 2; kc++)
							{
								strcpy(khai[kc], khai[kc + 2]);
							}
						}
						ktrace--;
						kcnt -= 2;
					}
					
				}
				for (ktrace = 0; ktrace < kcnt; ktrace++)
				{
					if (strncmp(khai[ktrace], "+", 1) == 0 || strncmp(khai[ktrace], "-", 1) == 0)
					{
						if (strncmp(khai[ktrace], "+", 1) == 0)
						{
							_itoa(atoi(khai[ktrace - 1]) + atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
							//ktrace+2からの値をktraceから順に埋めていく↓
							for (kc = ktrace; kc < kcnt - 2; kc++)
							{
								strcpy(khai[kc], khai[kc + 2]);
							}
						}
						else if (strncmp(khai[ktrace], "-", 1) == 0)
						{
							_itoa(atoi(khai[ktrace - 1]) - atoi(khai[ktrace + 1]), khai[ktrace - 1], 10);
							//ktrace+2からの値をktraceから順に埋めていく↓
							for (kc = ktrace; kc < kcnt - 2; kc++)
							{
								strcpy(khai[kc], khai[kc + 2]);
							}
						}
						ktrace--;
						kcnt -= 2;
					}
				}
			if (strncmp(buffer->kata, "int", 3) == 0)
			{
				buffer->i = atoi(khai[0]);
			}
			else if (strncmp(buffer->kata, "double", 6) == 0)
			{
				buffer->d = atoi(khai[0]);
			}
			else if (strncmp(buffer->kata, "float", 5) == 0)
			{
				buffer->f = atoi(khai[0]);
			}
			kcnt = 0;
			printf("計算終了\n");
		}
		/*ここまでbufが変数だった場合*/
		/*ここから初期化*/
		ifa = 0;
		ifb = 0;
		flag2 = true;
		//memset(khai, 0, sizeof(khai));
		memset(per, 0, sizeof(per));
		memset(h, 0, sizeof(h));
		memset(buf, 0, sizeof(buf));
	}
	/*メモリ開放*/
	free(p);
}