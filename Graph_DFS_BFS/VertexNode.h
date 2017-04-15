#include<iostream>
#include"EdgeNode.h"
#ifndef VertexNode_Class_
#define VertexNode_Class_

//定义邻接表的头结点
template <class VertexType>
class VertexNode{
public:
	//VertexNode(VertexType &);

	void ClearEdgeList();  //删除这个顶点的邻接表
	bool AppendEdge(int, int=0);  //在这个顶点的邻接表中加入一条边
	//bool RemoveEdge(int);   //在这个顶点的邻接表中删除一条边
	VertexType data;  //顶点的数据信息
	EdgeNode *edgeList ;  //指向第一条依附该顶点的边的指针
};
#endif

template<class VertexType>
void VertexNode<VertexType>::ClearEdgeList(){
	EdgeNode *p, *q;
	p = edgeList;
	while(p != NULL){ //逐个删除相邻边的信息
		q = p->next;
		delete p;
		p=q;
	}
	edgeList = NULL;
}

//参数v为加入边中邻接顶点序号，wgh为加入边的权值
template<class VertexType>
bool VertexNode<VertexType>::AppendEdge(int v, int wgh){
	EdgeNode *p = edgeList;
	EdgeNode *q = NULL;
	//找到链接表中的末结点，末结点的指针赋值给q 。如果发现有一个结点的adjVex的值与v相同，返回false
	while(p!=NULL){
		if(p->adjVertex == v){
			cout<<"Your input have wrong!!!"<<endl;
			return false;
		}
		q=p;
		p=p->next;
	}
	//在邻接表的最后加上一条边
	p = new EdgeNode(v,wgh);
	if(q==NULL){
		edgeList = p;
	}else{
		q->next = p;
	}
	return true;
}