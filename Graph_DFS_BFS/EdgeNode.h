#include<iostream>
#ifndef EdgeNode_Class_
#define EdgeNode_Class_
//�����ڽӱ�ı���
class EdgeNode{
public:
	EdgeNode(int a , int w){//:adjVertex(a),weight(w), next(NULL);
		adjVertex = a;
		weight = w;
		next = NULL;
	}
	int adjVertex; //�ñ����ڽ������
	int weight;   //�ñߵ�Ȩ��
	EdgeNode *next; //ָ����һ���ߵ�ָ��
};
#endif

