#include<iostream>
#include<queue>
#ifndef ALGraph_Class_
#define ALGraph_Class_
#include"VertexNode.h"
using namespace std;

template<class VertexType>
class ALGraph{
public:
	VertexNode<VertexType> * vertices;               //顶点表

	ALGraph(int s):numVertices(0),numEdges(0){ //构造函数
		numVertices = s;
		if(s>0)
			vertices = new VertexNode<VertexType>[s];

		for(int i=0; i<s; i++){
			VertexType j;
			cout<<"输入第"<<i<<"个"<<endl;
			cin>>j;
			vertices[i].data = j;
			vertices[i].edgeList = NULL;
		}

		int n;
		cout<<"输入边的个数"<<endl;
		cin>>n;
		numEdges = n;
		int v1, v2, wgh;
		for(int j=0; j<n; j++){
			cout<<"输入第"<<j<<"条边的两顶点及其权重"<<endl;
			cin>>v1>>v2>>wgh;
			vertices[v1].AppendEdge(v2,wgh);  //为两点的相邻边分别赋值
			vertices[v2].AppendEdge(v1,wgh);
		}
		cout<<endl;
	}
	
	~ALGraph(){  //析构函数
		for(int i=0; i<numVertices; i++)//逐个删除顶点的链表
			vertices[i].ClearEdgeList();
		if(numVertices !=0) //删除顶点表
			delete []vertices;
	}

	void display(); //邻接表的展示 
	void DFSTranverse(); //深度优先遍历
	void BFSTranverse(); //广度优先遍历

private:
	void DFS(int); //深度优先递归函数
	int numVertices;                                            //顶点个数
	int numEdges;                                               //边数
	//int maxVertices;                                             //最多可存放的顶点个数
	bool *visited;                                                 //在遍历时存放是否访问过的标志
};
#endif

template<class VertexType>
void ALGraph<VertexType>::display(){
	EdgeNode *p;
	cout<<"该图的邻接表为"<<endl;
	for(int i=0; i<numVertices; i++){
		cout<<vertices[i].data;
		p = vertices[i].edgeList;
		while(p != NULL){
			cout<<"-->";
			cout<<p->adjVertex<<"("<<p->weight<<")";
			p = p->next;
		}
		cout<<endl; 
	}
	cout<<endl;
}

template<class VertexType>
void ALGraph<VertexType>::DFSTranverse(){
	int v;
	//每个顶点的访问标志置为false
	visited = new bool[numVertices];
	for(v=0; v<numVertices; v++)
		visited[v] = false;

	//用户输入指点遍历开始的顶点
	VertexType d;
	cout<<"请输入您想深度优先遍历开始的顶点名称"<<endl;
	cin>>d;

	//寻找到指定顶点开始遍历	
	cout<<"由"<<d<<"开始的该图的深度优先遍历顺序为"<<endl;
	for(v=0; v<numVertices; v++){
		if(vertices[v].data == d){
			DFS(v);
			break;
		}
	}

	//以顶点中的每个未访问过的顶点出发进行遍历
	for(v=0; v<numVertices; v++)
		if(!visited[v])
			DFS(v);
	
	cout<<endl;
	cout<<endl;
	delete[] visited;
}

template <class VertexType>
void ALGraph<VertexType>::DFS(int v){
	//设置序号为v的顶点的访问标志
	visited[v] = true;
	cout<<vertices[v].data;

	//查找序号为v的顶点的所有邻接顶点，该邻接顶点的序号为w，对w递归调用DFS
	EdgeNode *p = vertices[v].edgeList;
	while(p != NULL){
		int  w = p->adjVertex;
		if(!visited[w]){
			cout<<"-->";
			DFS(w);
		}
		p = p->next;
	}
}

template<class VertexType>
void ALGraph<VertexType>::BFSTranverse(){
	int v;
	queue<int> vertexQueue;  //辅助队列
	EdgeNode *p;

	//每一顶点的访问标志置为false
	visited = new bool [numVertices];
	for(v=0; v<numVertices; v++)
		visited[v] = false;

	//用户输入指点遍历开始的顶点
	VertexType d;
	cout<<"请输入您想广度优先遍历开始的顶点名称"<<endl;
	cin>>d;

	//寻找到指定顶点开始遍历	
	cout<<"由"<<d<<"开始的该图的广度优先遍历顺序为"<<endl;
	for(v=0; v<numVertices; v++){
		if(vertices[v].data == d){
			visited[v] = true;
			
			vertexQueue.push(v);
			
			int counter = 1;
			while(!vertexQueue.empty()){
				int u = vertexQueue.front();
			    cout<<vertices[u].data;
				if(counter != numVertices)
					cout<<"-->";
			    vertexQueue.pop();

			    p = vertices[u].edgeList;
			    while(p!=NULL){
				    int w = p->adjVertex;
				    if(!visited[w]){
					    visited[w] = true;
					    vertexQueue.push(w);
				    }
				    p=p->next;
			    }
				counter++;
		    }
		}
	}

	//以顶点表中的每个未访问过的顶点出发进行遍历
	/*
	for(v=0; v<numVertices; v++){
		if(visited[v])
			continue;

		visited[v] = true;
		//visit
		vertexQueue.push(v);

		while(!vertexQueue.empty()){
			int u = vertexQueue.front();
			cout<<vertices[u].data;
			vertexQueue.pop();
			p = vertices[u].edgeList;
			while(p!=NULL){
				int w = p->adjVertex;
				if(!visited[w]){
					visited[w] = true;
					vertexQueue.push(w);
				}
				p=p->next;
			}
		}
	}
	*/
	cout<<endl;
	cout<<endl;
	delete[] visited;
}