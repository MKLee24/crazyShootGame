#include "cocos2d.h"
#include <sstream>

USING_NS_CC;

struct rankStore{
	int rankScore;
	std :: string name;
};

class TopRankScene :public cocos2d::Scene{
	
public:
	cocos2d::Vector <cocos2d::LabelTTF*>RankList;
	static cocos2d::Scene* createScene();
	CREATE_FUNC(TopRankScene);

	virtual bool init();

	rankStore getStore(int n);

	Node* createRow(int rank, int score, std::string name);//�������а��һ��
	Node* createDefaultRow(int rank);
	Node*createFirstRow();//����Row0Ϊ������
	void Return(Ref* sender);
};