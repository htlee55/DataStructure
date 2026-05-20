// 스레드 이진트리(Threaded Binary Tree)를 위한 노드 클래스
#include <cstdio>
class ThreadedBinNode {
	int			data;
	ThreadedBinNode	*left;
	ThreadedBinNode	*right;
public:
	bool		bThread;
	ThreadedBinNode( int val=0, ThreadedBinNode *l=NULL, ThreadedBinNode *r=NULL, bool bTh=false)
			: data(val), left(l), right(r), bThread(bTh) { }
	int	 getData ()				{ return data; }	
	void setRight(ThreadedBinNode *r)	{ right= r; }
	ThreadedBinNode* getLeft ()			{ return left; }	
	ThreadedBinNode* getRight()			{ return right; }	
};

