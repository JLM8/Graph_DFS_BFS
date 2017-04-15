#include<iostream>
#include"EdgeNode.h"
#ifndef VertexNode_Class_
#define VertexNode_Class_

//�����ڽӱ��ͷ���
template <class VertexType>
class VertexNode{
public:
	//VertexNode(VertexType &);

	void ClearEdgeList();  //ɾ�����������ڽӱ�
	bool AppendEdge(int, int=0);  //�����������ڽӱ��м���һ����
	//bool RemoveEdge(int);   //�����������ڽӱ���ɾ��һ����
	VertexType data;  //�����������Ϣ
	EdgeNode *edgeList ;  //ָ���һ�������ö���ıߵ�ָ��
};
#endif

template<class VertexType>
void VertexNode<VertexType>::ClearEdgeList(){
	EdgeNode *p, *q;
	p = edgeList;
	while(p != NULL){ //���ɾ�����ڱߵ���Ϣ
		q = p->next;
		delete p;
		p=q;
	}
	edgeList = NULL;
}

//����vΪ��������ڽӶ�����ţ�wghΪ����ߵ�Ȩֵ
template<class VertexType>
bool VertexNode<VertexType>::AppendEdge(int v, int wgh){
	EdgeNode *p = edgeList;
	EdgeNode *q = NULL;
	//�ҵ����ӱ��е�ĩ��㣬ĩ����ָ�븳ֵ��q �����������һ������adjVex��ֵ��v��ͬ������false
	while(p!=NULL){
		if(p->adjVertex == v){
			cout<<"Your input have wrong!!!"<<endl;
			return false;
		}
		q=p;
		p=p->next;
	}
	//���ڽӱ��������һ����
	p = new EdgeNode(v,wgh);
	if(q==NULL){
		edgeList = p;
	}else{
		q->next = p;
	}
	return true;
}