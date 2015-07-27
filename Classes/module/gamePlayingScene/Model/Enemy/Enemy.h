#include "cocos2d.h"
USING_NS_CC;

#define pi 3.141592654

class Enemy :public cocos2d::Node{
public :
	/*
	Ĭ����ͼ�����Ͻ�������һ��ģʽΪ2�ĵ���
	*/
	virtual bool init();
	CREATE_FUNC(Enemy);

	/*
	�ڣ�_locX, _locY����������һ��Ѫ����_blood��ģʽΪ_mode�ĵ���
	*/
	Enemy* setParameter(float _locX, float locY, int _blood, int _mode);

	/*
	����һ���粼�֣�������Ϊ5��������������һ֧��ͨ�����ɻ�ɱ��
	*/
	void createEnemyOne();

	/*
	����һ��սʿսʿ����ս������������Ϊ10���������������������ܻ�ɱ��
	*/
	void createEnemyTwo();

	/*
	�����֣������ƶ�������Զ�̹�����������Ϊ10���������������������ܻ�ɱ��
	*/
	void createEnemyArrow();

	/*
	ħ��ʦ��Զ�̹�����ÿ3��˲ʱ�ƶ�һ������λ�ã������ѻ�ɱ��һ����
	������Ϊ15���������������������ܻ�ɱ��
	*/
	void createEnemyMagic(Enemy* _enemy);

	void updateTimeToArrowAttack(float dt);

	void setBlood(int _blood);

	Sprite* createDispearSprite(int _mode,Vec2);

	int attack(Sprite* s, int _mode);

	int getPower();
	int getBlood();
	int getMode();

private:
	//��ʼ��X����
	float locX;

	//��ʼ��Y����
	float locY;

	//	Ѫ��
	int blood;

	/*����ģʽ
	mode 0   Undefined
	mode 1   Move enemy
	mode 2   Arrow enemy
	*/
	int mode;
	int power;
};