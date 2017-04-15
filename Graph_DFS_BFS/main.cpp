#include<iostream>
#include<string>
#include"ALGraph.h"
//#include"VertexNode.h"
//#include"EdgeNode.h"

using namespace std;

int main(){
	int n;
	cout<<"输入该图结点个数"<<endl;
	cin>>n;
	ALGraph<string> a(n);
	a.display();

	a.DFSTranverse();
	a.BFSTranverse();
	//a.vertices[1].edgeList;
	system("pause");
	return 0;
}