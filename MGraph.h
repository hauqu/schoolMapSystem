#pragma once
#pragma once
#include<vector>
#include<iostream>//输出放到类内，方便操作
#include<stack>
#include<string>
using namespace std;
/*
邻接矩阵的图结构(有权)
不含顶点信息(无数据，所以不能DFS，BFS)
*/
typedef int Weight;
struct edge
{
	int v1;
	int v2;
	Weight w;
	edge(int a, int b) :v1(a), v2(b), w(1) {}
	edge(int a, int b, Weight _w) :v1(a), v2(b), w(_w) {}
};
struct Pos
{
	int x;
	int y;
	Pos(int _x,int _y):x(_x),y(_y){}
};
class MGraph
{
public:
	vector<vector<Weight>>G;
	MGraph(int VN);//初始化一个无边图
	void addEdge(edge e);
	MGraph& operator+(edge e);
	int zeroOutDegree(void);
	void clearEdge(void);
	vector<int> Dijkstra(int v, int endv);//返回最短距离，以及路径
	~MGraph() {}
	int VerN(void) { return VN; }
	int VerE(void) { return VE; }
private:
	int GetV(vector<int>& dis, vector<bool>& vis);
	int VN;
	int VE;
};
MGraph::MGraph(int vertexN)
{
	G.resize(vertexN);
	for (int i = 0; i < vertexN; i++)
	{
		G[i].resize(vertexN, 0);
	}
	VN = vertexN;
	VE = 0;
}
inline void MGraph::addEdge(edge e)
{
	e.v1--; e.v2--;
	if (this->G[e.v1][e.v2] == 0)VE++;
	this->G[e.v1][e.v2] = e.w;
	if (e.w == 0)
		VE--;

}
inline MGraph& MGraph::operator+(edge e)
{
	if (this->G[e.v1 - 1][e.v2 - 1] == 0)VE++;
	this->G[e.v1 - 1][e.v2 - 1] = e.w;
	if (e.w == 0)
		VE--;

	return *this;
}
inline int MGraph::zeroOutDegree(void)
{
	int count = 0;
	for (int i = 0; i < VN; i++)
	{
		int temp = 0;
		for (int j = 0; j < VN; j++)
		{
			if (G[i][j] == 0)
				temp++;
			else
				break;
		}
		if (temp == VN) count++;
	}
	return count;
}
inline void MGraph::clearEdge(void)
{
	for (int i = 0; i < VN; i++)
		for (int j = 0; j < VN; j++)
			G[i][j] = 0;
}
inline vector<int> MGraph::Dijkstra(int v, int endv)
{
	v--; endv--;
	vector<int>dist(VN, 9999);
	vector<int>path(VN, -1);
	vector<bool>visit(VN, false);
	vector<int>res;
	visit[v] = true;
	dist[v] = 0;

	for (int i = 0; i < VN; i++)
	{
		if (G[v][i] != 0)
		{
			dist[i] = G[v][i];
			path[i] = v;
		}
	}

	while (true)
	{
		int tempV = GetV(dist, visit);//未收录顶点的最距离最小点
		if (tempV == -1)//全部的点都已经收录
			break;
		visit[tempV] = true;//收录
		for (int i = 0; i < VN; i++)
		{
			if (G[tempV][i] != 0)//有连接
			{
				if (visit[i] == false)//对于未收录进的邻接点
				{
					if (dist[tempV] + G[tempV][i] < dist[i])//原先的路径距离比现在的大，于是更新路径
					{
						dist[i] = dist[tempV] + G[tempV][i];
						path[i] = tempV;//更新前驱
					}
				}
			}
		}
	}
	stack<int> s;
	int pathDis = 0;
	while (endv != -1)
	{
		s.push(endv);
		pathDis += dist[endv];
		endv = path[endv];
	}

	while (!s.empty())
	{
		res.push_back(s.top());
		s.pop();
	}
	res.push_back(pathDis);

	return res;
}
inline int MGraph::GetV(vector<int>& dis, vector<bool>& vis)
{

	int minV = -1;
	for (int i = 0; i < vis.size(); i++)
	{
		if (vis[i] == false)
		{
			minV = i;
			break;
		}
	}
	for (int i = minV + 1; i < vis.size(); i++)
	{
		if (vis[i] == false)
		{
			if (dis[minV] > dis[i])
				minV = i;
		}
	}

	return minV;
}


/*

  ~Graph( ) { }                                          //析构函数
	void Dijkstra(int v,int endv);                       //求最小距离
	void PutOutVexInfo();                                 //取顶点信息
	void PutOutArcInfo();                                 //输出路径
	void SetArc(int v1,int v2,int arclength);             //修改路径
	void ChangeVex(int pos);                            //修改顶点信息
private:
	string vertex[MaxSize];                   //存放图中顶点的数组
	int arc[MaxSize][MaxSize];                 //存放图中边的数组
	int vertexNum, arcNum;                     //图的顶点数和边数


*/