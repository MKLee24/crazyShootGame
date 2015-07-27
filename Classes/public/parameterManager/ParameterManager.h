#include"cocos2d.h"
USING_NS_CC;

struct ArcherParameter{
	cocos2d::Vec2 initialPosition;
	ArcherParameter();
	ArcherParameter(cocos2d::Vec2 _initialPosition);
	/*ArcherParameter operator = (ArcherParameter _archerParameter){
	this->initialPosition = _archerParameter.initialPosition;
	return *this;
	}*/
};

struct EnemyParameter {
	cocos2d::Vec2 initialPosition;
	int mode;
	int blood;
	EnemyParameter();
	EnemyParameter(cocos2d::Vec2 _initialPosition, int _blood, int _mode);
	/*EnemyParameter operator = (EnemyParameter _enemyParameter) {
	this->initialPosition = _enemyParameter.initialPosition;
	this->blood = _enemyParameter.blood;
	this->mode = _enemyParameter.mode;
	return *this;
	}*/
};

struct GameParameterForLevels{
	int levelNum;
	ArcherParameter* archerParameter;
	std::vector<EnemyParameter*> enemyParameter;
	GameParameterForLevels(int _levelNum, ArcherParameter* _archerParameter, std::vector<EnemyParameter*> _enemyParameter);
};

class ParameterManager {
public:

	//��ȡ���������ٶ�
	static float getArrow1MaxVelocity();

	//��ȡ�����ƶ����ʱ��
	//static float getEnemyMovingTime();

	//��ȡ�������������
	static Vec2 getGravity();

	//��ȡ��Ļ��С
	static Size getVisibleSize();

	//��ȡÿһ������
	static GameParameterForLevels* getLevelInstance(int levelNum);

	static void deleteAll();

	static int getCurrentLevel();
	static void setCurrentLevel(int);
	static int getUnlockedLevel();
	static void setUnlockedLevel(int);
private:
	//ȫ�ֲ���
	static Vec2 gravity;//����
	static Size visibleSize;//���ӷ�Χ�ĳߴ�
	static int unlockedLevel;//�Ѿ��������ڼ���
	static int currentLevel;//��������ڼ���

	//����
	static float arrow1MaxVelocity;//��һ�ֹ���������ٶ�

	//����
	//static float enemyMovingTime;

	static GameParameterForLevels* level1GameParameter;


};