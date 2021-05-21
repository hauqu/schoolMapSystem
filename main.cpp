#include<iostream>
#include"MGraph.h"
#include<graphics.h>//用于绘图
#include<conio.h>//用于获取输入
#include<cmath>

/*

基本功能：
点击选中地点，再次点击，生成路径（改变颜色）和距离，点击确定 ，位置移动到目标



*/
using namespace std;
const int WIN_L = 860;
const int WIN_B = 640;
const int NodeSize = 10;

vector<Pos>p = {
		Pos(526,572),
		Pos(526,513),
		Pos(745,513),
		Pos(786,600),
		Pos(745,376),

		Pos(745,267),
		Pos(745, 87),
		Pos(526, 87),
		Pos(526, 265),
		Pos(307, 87),

		Pos(306,265),
		Pos(105,278),
		Pos(105, 390),
		Pos(305, 390),
		Pos(105,529),

		Pos(305, 514),
		Pos(100, 200),
		Pos(100, 600),
		Pos(526, 400),
		Pos(100, 100),

		
};
MGraph AHUT(20);
void InitMapData(void);
void drawNode(void);
int startV=1;
int endV;
int main()
{
	MOUSEMSG ms;
	initgraph(WIN_L, WIN_B);
	setbkcolor(RGB(180, 200, 210));
	cleardevice();
	setlinestyle(PS_DASHDOTDOT, 3);
	InitMapData();
	drawNode();
	while (true)
	{
		
		ms = GetMouseMsg();
		if (ms.mkLButton)
		{
			ms = GetMouseMsg();
			int temp = -1;
			for (int i = 0; i < p.size(); i++)
			{
				if ((ms.x - p[i].x) * (ms.x - p[i].x) +
					(ms.y - p[i].y) * (ms.y - p[i].y)
					< NodeSize * NodeSize)
				{
					temp = i;
					break;
				}
			}
			if (temp!=-1)
			{
				endV = temp+1;
				//startV = endV;
				vector<int>way = AHUT.Dijkstra(startV, endV);

				for (int i = 0; i < way.size()-2; i++)
				{
					setlinecolor(GREEN);
					line(p[way[i]].x, p[way[i]].y, p[way[i + 1]].x, p[way[i + 1]].y);

				}
				int t = way.back();
				char dist[5];
				_itoa_s(t, dist, 10);//将一个数按照十进制形式存入字符串中
				outtextxy(100, 10, dist[0]);
				outtextxy(120, 10, dist[1]);
				outtextxy(140, 10, dist[2]);
				outtextxy(160, 10, dist[3]);
				outtextxy(180, 10, L"米");
				setlinecolor(RGB(255, 255, 255));
				if (_getch() == ' ')
				{
					startV = endV;
				}
				cleardevice();
				drawNode();
			}
			else
			{
				continue;
			}
			
			
		}
	}
	_getch();
	
	return 0;
}
void InitMapData(void)
{
	AHUT.addEdge(edge(1, 3,50));
	AHUT.addEdge(edge(3, 1,50));
	
	AHUT.addEdge(edge(1, 4,45));
	AHUT.addEdge(edge(4, 1,45));
	
	AHUT.addEdge(edge(4, 3,25));
	AHUT.addEdge(edge(3, 4,25));

	AHUT.addEdge(edge(1, 16,50));
	AHUT.addEdge(edge(16, 1,50));

	AHUT.addEdge(edge(16, 2,35));
	AHUT.addEdge(edge(2, 16,35));

	AHUT.addEdge(edge(2, 3,35));
	AHUT.addEdge(edge(3, 2,35));

	AHUT.addEdge(edge(3, 5,45));
	AHUT.addEdge(edge(5, 3,45));

	AHUT.addEdge(edge(5, 6,45));
	AHUT.addEdge(edge(6, 5,45));

	AHUT.addEdge(edge(9, 6,55));
	AHUT.addEdge(edge(6, 9,55));

	AHUT.addEdge(edge(7, 6,70));
	AHUT.addEdge(edge(6, 7,70));

	AHUT.addEdge(edge(8, 7,50));
	AHUT.addEdge(edge(7, 8,50));

	AHUT.addEdge(edge(9, 7, 80));
	AHUT.addEdge(edge(7, 9, 80));

	AHUT.addEdge(edge(8, 9,75));
	AHUT.addEdge(edge(9, 8,75));

	AHUT.addEdge(edge(8, 10,50));
	AHUT.addEdge(edge(10, 8,50));

	AHUT.addEdge(edge(11, 9,50));
	AHUT.addEdge(edge(9, 11,50));

	AHUT.addEdge(edge(11, 10,50));
	AHUT.addEdge(edge(10, 11,50));

	AHUT.addEdge(edge(11, 12,40));
	AHUT.addEdge(edge(12, 11,40));

	AHUT.addEdge(edge(11, 14,45));
	AHUT.addEdge(edge(14, 11,45));

	AHUT.addEdge(edge(13, 12,45));
	AHUT.addEdge(edge(12, 13,45));
	
	AHUT.addEdge(edge(13, 14,40));
	AHUT.addEdge(edge(14, 13,40));

	AHUT.addEdge(edge(13, 15, 20));
	AHUT.addEdge(edge(15, 13, 20));

	AHUT.addEdge(edge(16, 14,45));
	AHUT.addEdge(edge(14, 16,45));

	AHUT.addEdge(edge(16, 15,30));
	AHUT.addEdge(edge(15, 16,30));

	AHUT.addEdge(edge(19, 2, 15));
	AHUT.addEdge(edge(2, 19, 15));

	AHUT.addEdge(edge(17, 20, 30));
	AHUT.addEdge(edge(20, 17, 30));

	AHUT.addEdge(edge(11, 20, 60));
	AHUT.addEdge(edge(20, 11, 60));

	AHUT.addEdge(edge(18, 16, 70));
	AHUT.addEdge(edge(16, 18, 70));
	/*
	
	*/
}
void drawNode(void)
{

	outtextxy(500, 20, L"鼠标左键选择终点，空格键确定，其他键取消");
	for (int i = 0; i < AHUT.VerN(); i++)
	{
		fillcircle(p[i].x, p[i].y, 10);
	}
	for (int i = 0; i < AHUT.G.size(); i++)
	{
		for(int j=0;j<AHUT.G[i].size();j++)
		{
			if (AHUT.G[i][j]!=0)
			{
				line(p[i].x, p[i].y, p[j].x, p[j].y);
			}
		}
	}
	setfillcolor(RED);
	fillcircle(p[startV - 1].x, p[startV - 1].y, NodeSize);
	setfillcolor(RGB(255, 255, 255));


	outtextxy(p[2].x-15, p[2].y+10, L"学校体育场");
	outtextxy(p[3].x-15, p[3].y+10, L"研究生公寓");
	outtextxy(p[4].x-15, p[4].y+10, L"教学D楼");
	outtextxy(p[5].x-15, p[5].y+10, L"艺设楼");
	outtextxy(p[6].x-15, p[6].y+10, L"机械楼");
	outtextxy(p[7].x-15, p[7].y+10, L"中心花园");
	outtextxy(p[8].x-15, p[8].y+10, L"电气楼");
	outtextxy(p[9].x-15, p[9].y+10, L"逸夫楼");
	outtextxy(p[10].x-15, p[10].y+10, L"餐饮场所");
	outtextxy(p[11].x-15, p[11].y+10, L"AB篮球场");
	outtextxy(p[12].x-15, p[12].y+10, L"宿舍楼1");
	outtextxy(p[13].x-15, p[13].y+10, L"振华图书馆");
	outtextxy(p[14].x-15, p[14].y+10, L"宿舍楼2");

	outtextxy(p[1].x-15, p[1].y+10, L"南北教");

	outtextxy(p[0].x-15, p[0].y+10, L"学校正门");

	outtextxy(p[15].x-15, p[15].y+10, L"材料楼");
	outtextxy(p[16].x-15, p[16].y+10, L"冶金楼");
	outtextxy(p[17].x-15, p[17].y+10, L"鸟笼篮球场");
	outtextxy(p[18].x-15, p[18].y+10, L"阶梯教室");
	outtextxy(p[19].x-15, p[19].y+10, L"工创楼");
}

