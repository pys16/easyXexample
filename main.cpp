#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
int main()
{
	initgraph(640,480,NULL);//这一行是初始化绘图环境
	setbkcolor(WHITE);
	cleardevice();
	RECT r={0,0,640,480};//这一行定义了一个跟窗口一样大的矩形
	setlinecolor(RED);
	setfillcolor(RGB(252,252,10));
	fillroundrect(260,220,380,260,2,2);
	setbkcolor(RGB(252,252,10));
	settextcolor(BLACK);
	drawtext(_T("Hello World!"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);//格式化输出
	MOUSEMSG mouse;
	while(1)
	{
		mouse=GetMouseMsg();
		if(mouse.x>=260&&mouse.x<=380&&mouse.y>=220&&mouse.y<=260)
		{
			setfillcolor(RGB(252,10,252));
			fillroundrect(260,220,380,260,2,2);
			setbkcolor(RGB(252,10,252));
			drawtext(_T("Hello World!"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
			if(mouse.mkLButton==true)
			{
				BeginBatchDraw();
				setbkcolor(WHITE);
				cleardevice();
				for(int i=50; i<600; i++)
				{
					circle(i, 100, 40);
					floodfill(i, 100, WHITE);
					FlushBatchDraw();
					Sleep(10);
					cleardevice();
				}
				EndBatchDraw();
			}
		}
		else
		{
			setfillcolor(RGB(252,252,10));
			fillroundrect(260,220,380,260,2,2);
			setbkcolor(RGB(252,252,10));
			drawtext(_T("Hello World!"),&r,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		}
	}
	_getch();//按任意键退出
	closegraph();//关闭
	return 0;
}