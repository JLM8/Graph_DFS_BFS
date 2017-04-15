#include<iostream>
#ifndef EdgeNode_Class_
#define EdgeNode_Class_
//定义邻接表的表结点
class EdgeNode{
public:
	EdgeNode(int a , int w){//:adjVertex(a),weight(w), next(NULL);
		adjVertex = a;
		weight = w;
		next = NULL;
	}
	int adjVertex; //该边相邻结点的序号
	int weight;   //该边的权重
	EdgeNode *next; //指向下一条边的指针
};
#endif

