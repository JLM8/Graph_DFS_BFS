#include<iostream>
#include<queue>
#ifndef ALGraph_Class_
#define ALGraph_Class_
#include"VertexNode.h"
using namespace std;

template<class VertexType>
class ALGraph{
public:
	VertexNode<VertexType> * vertices;               //�����

	ALGraph(int s):numVertices(0),numEdges(0){ //���캯��
		numVertices = s;
		if(s>0)
			vertices = new VertexNode<VertexType>[s];

		for(int i=0; i<s; i++){
			VertexType j;
			cout<<"�����"<<i<<"��"<<endl;
			cin>>j;
			vertices[i].data = j;
			vertices[i].edgeList = NULL;
		}

		int n;
		cout<<"����ߵĸ���"<<endl;
		cin>>n;
		numEdges = n;
		int v1, v2, wgh;
		for(int j=0; j<n; j++){
			cout<<"�����"<<j<<"���ߵ������㼰��Ȩ��"<<endl;
			cin>>v1>>v2>>wgh;
			vertices[v1].AppendEdge(v2,wgh);  //Ϊ��������ڱ߷ֱ�ֵ
			vertices[v2].AppendEdge(v1,wgh);
		}
		cout<<endl;
	}
	
	~ALGraph(){  //��������
		for(int i=0; i<numVertices; i++)//���ɾ�����������
			vertices[i].ClearEdgeList();
		if(numVertices !=0) //ɾ�������
			delete []vertices;
	}

	void display(); //�ڽӱ��չʾ 
	void DFSTranverse(); //������ȱ���
	void BFSTranverse(); //������ȱ���

private:
	void DFS(int); //������ȵݹ麯��
	int numVertices;                                            //�������
	int numEdges;                                               //����
	//int maxVertices;                                             //���ɴ�ŵĶ������
	bool *visited;                                                 //�ڱ���ʱ����Ƿ���ʹ��ı�־
};
#endif

template<class VertexType>
void ALGraph<VertexType>::display(){
	EdgeNode *p;
	cout<<"��ͼ���ڽӱ�Ϊ"<<endl;
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
	//ÿ������ķ��ʱ�־��Ϊfalse
	visited = new bool[numVertices];
	for(v=0; v<numVertices; v++)
		visited[v] = false;

	//�û�����ָ�������ʼ�Ķ���
	VertexType d;
	cout<<"����������������ȱ�����ʼ�Ķ�������"<<endl;
	cin>>d;

	//Ѱ�ҵ�ָ�����㿪ʼ����	
	cout<<"��"<<d<<"��ʼ�ĸ�ͼ��������ȱ���˳��Ϊ"<<endl;
	for(v=0; v<numVertices; v++){
		if(vertices[v].data == d){
			DFS(v);
			break;
		}
	}

	//�Զ����е�ÿ��δ���ʹ��Ķ���������б���
	for(v=0; v<numVertices; v++)
		if(!visited[v])
			DFS(v);
	
	cout<<endl;
	cout<<endl;
	delete[] visited;
}

template <class VertexType>
void ALGraph<VertexType>::DFS(int v){
	//�������Ϊv�Ķ���ķ��ʱ�־
	visited[v] = true;
	cout<<vertices[v].data;

	//�������Ϊv�Ķ���������ڽӶ��㣬���ڽӶ�������Ϊw����w�ݹ����DFS
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
	queue<int> vertexQueue;  //��������
	EdgeNode *p;

	//ÿһ����ķ��ʱ�־��Ϊfalse
	visited = new bool [numVertices];
	for(v=0; v<numVertices; v++)
		visited[v] = false;

	//�û�����ָ�������ʼ�Ķ���
	VertexType d;
	cout<<"���������������ȱ�����ʼ�Ķ�������"<<endl;
	cin>>d;

	//Ѱ�ҵ�ָ�����㿪ʼ����	
	cout<<"��"<<d<<"��ʼ�ĸ�ͼ�Ĺ�����ȱ���˳��Ϊ"<<endl;
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

	//�Զ�����е�ÿ��δ���ʹ��Ķ���������б���
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