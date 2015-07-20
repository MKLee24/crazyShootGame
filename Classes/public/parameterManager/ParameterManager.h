#include"cocos2d.h"
USING_NS_CC;

class ParameterManager {
public:
	/*
	��ȡ���������ٶ�
	*/
	static float getArrowMaxVelocity();

	/*
	��ȡ�����ƶ����ʱ��
	*/
	static float getEnemyMovingTime();

	/*
	��ȡ�������������
	*/
	static Vec2 getGravity();

	/*
	��ȡ��Ļ��С
	*/
	static Size getVisibleSize();
private:
	static ParameterManager* parameterManager;

	static float arrowMaxVelocity;
	static float enemyMovingTime;
	static Vec2 gravity;

	static Size visibleSize;
};