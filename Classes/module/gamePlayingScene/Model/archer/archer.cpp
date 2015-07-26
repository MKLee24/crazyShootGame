#include"archer.h"
#include"../../Model/Constant/Constant.h"
archer* archer::archer_ = NULL;

archer::archer() {}

archer::~archer() {
	archer_ = NULL;
}

/**
archer* archerController::getInstance(){
	//auto poolManager = PoolManager::getInstance();
	//if (!poolManager->getCurrentPool()->isClearing() || !poolManager->isObjectInPools(archer)) {
	if (archer == NULL){
		archer = new archerController();

		archer->autorelease();
		//archer = (archerController*)Sprite::createWithSpriteFrameName(Constant::getArcherFrameName());
		archer->init();
	}
	return archer;
}
*/

bool archer::init(){
	bool a = Layer::init();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	float times = 1.5;//ͼ�ηŴ���

	body = Sprite::create(Constant::getArcherbodyPath());
	body->setPosition(0,0);
	body->setScale(times);
	this->addChild(body, 1);
	
	//auto bodyBody = PhysicsBody::createBox(body->getContentSize());
	//bodyBody->getFirstShape()->setTag(Constant::getArcherTag());
	//body->setPhysicsBody(bodyBody);
	//body->getPhysicsBody()->setContactTestBitmask(0x0000000F);
	//body->getPhysicsBody()->setCollisionBitmask(0x0000000F);
	

	hand = Sprite::create(Constant::getArcherhandPath());
	hand->setPosition(body->getPositionX() - (4 * times), body->getPositionY() - (3 * times));
	hand->setScale(times);
	this->addChild(hand, 3);
	
	//auto handBody = PhysicsBody::createBox(hand->getContentSize());
	//handBody->getFirstShape()->setTag(Constant::getArcherhandTag());
	//hand->setPhysicsBody(handBody);
	//hand->getPhysicsBody()->setContactTestBitmask(0x0000000F);
	//hand->getPhysicsBody()->setCollisionBitmask(0x0000000F);
	
	head = Sprite::create(Constant::getArcherheadPath());
	head->setPosition(body->getPositionX() - (1 * times), body->getPositionY() + (2 * times));
	head->setScale(times);
	this->addChild(head, 2);
	
	//auto headBody = PhysicsBody::createBox(head->getContentSize());
	//headBody->getFirstShape()->setTag(Constant::getArcherheadTag());
	//head->setPhysicsBody(headBody);
	//head->getPhysicsBody()->setContactTestBitmask(0x0000000F);
	//head->getPhysicsBody()->setCollisionBitmask(0x0000000F);
   
	//Ѫ��
	hpBar_back = Sprite::create("image/GamePlayingScene/xue_back.png");
	hpBar_back->setPosition(Vec2(body->getContentSize().width / 2, body->getContentSize().height + 30));
	body->addChild(hpBar_back);

	hpBar = ProgressTimer::create(Sprite::create("image/GamePlayingScene/xue_fore.png"));
	hpBar->setType(ProgressTimer::Type::BAR); // ���ý�������ʽ�����λ��Σ�
	hpBar->setMidpoint(Vec2(0, 0.5f));        // ���ý���������ʼ�㣬��0��y����ʾ����ߣ���1��y����ʾ���ұߣ���x��1����ʾ�����棬��x��0����ʾ�����档
	hpBar->setBarChangeRate(Vec2(1, 0));      // ���ý������仯���򣬣�1,0����ʾ�᷽�򣬣�0,1����ʾ�ݷ���
	hpBar->setPercentage(100);                // ���õ�ǰ�������Ľ���
	hpBar->setPosition(Vec2(hpBar_back->getContentSize().width / 2, hpBar_back->getContentSize().height / 2));
	hpBar_back->addChild(hpBar);
	hpBar_back->setVisible(true);   // ��������Ѫ���ɼ������ǽ���Player ���ܹ�����ʱ������ʾѪ����



	/*
	hpBar_back = Sprite::create("image/xue_back.png");
	hpBar_back->setPosition(head->getPositionX(), head->getPositionY()+20);
	this->addChild(hpBar_back, 2);

	hpBar_fore = Sprite::create("image/xue_fore.png");
	hpBar = ProgressTimer::create(hpBar_fore);
	hpBar->setPosition(head->getPositionX(), head->getPositionY()+20);
	hpBar->setType(ProgressTimer::Type::BAR);
	hpBar->setMidpoint(Point(0, 0));
	hpBar->setBarChangeRate(Point(1, 0));
	this->addChild(hpBar, 1);

	this->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	this->setPosition(0, 0);

	*/
	
	//add touch listener
	EventListenerTouchOneByOne* screenListener = EventListenerTouchOneByOne::create();
	screenListener->setSwallowTouches(false);// true�����´������򵥵���˵������������sprite ,A�� B��A����B���£�λ���ص���
	screenListener->onTouchBegan = CC_CALLBACK_2(archer::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(screenListener, this);
	/**
	body->getPhysicsBody()->setContactTestBitmask(0x0000000F);
	//archerSprite->getPhysicsBody()->setCollisionBitmask(0x0000000F);
	body->getPhysicsBody()->setCategoryBitmask(0x0000000F);
	body->getPhysicsBody()->getFirstShape()->setTag(Constant::getArcherTag());
	**/

	//����
	
	this->setPosition(visibleSize.width / 10, 200);
	auto bodyBody = PhysicsBody::createBox(Size(body->getContentSize().width * 0.8,body->getContentSize().height));
	bodyBody->getFirstShape()->setTag(Constant::getArcherTag());
	this->setPhysicsBody(bodyBody);

	this->getPhysicsBody()->setContactTestBitmask(1);
	this->getPhysicsBody()->setCategoryBitmask(2); //����

	//arrowSprite->getPhysicsBody()->setContactTestBitmask(0x0000F0F0);
	//arrowSprite->getPhysicsBody()->setCategoryBitmask(0x0000F0F0);
	
	return a;
}

bool archer::onTouchBegan(Touch *touch, Event *unused_event) {
	archerCenter = this->getPosition();
	auto touchPoint = touch->getLocation();
	if (touchPoint.x >= archerCenter.x) {
		body->setFlippedX(false);//����ת
		head->setFlippedX(false);
		hand->setFlippedX(false);
		double angle;
		if (fabs(touchPoint.x - archerCenter.x) < 1e-6) {
			angle = 135;
		}
		else {
			//����������archer��������ŵ��ӷ����˳ʱ��нǡ�
			angle = -atan((touchPoint.y - archerCenter.y) / (touchPoint.x - archerCenter.x)) / 3.141592654 * 180;
			angle += 180;
			if (angle < 135) angle = 135;//���ƽǵķ�Χ����Ȼ���Ҫͷ�����Ϸ����Ļ���ͼ����ѿ�
			else if (angle > 225) angle = 225;
		}
		head->setRotation(angle - 180);
		hand->setRotation(angle + 90);
	}
	else {
		double angle = -atan((touchPoint.y - archerCenter.y) / (touchPoint.x - archerCenter.x)) / 3.141592654 * 180;
		body->setFlippedX(true);
		head->setFlippedX(true);
		hand->setFlippedX(true);
		if (angle > 45) angle = 45;
		else if (angle < -45) angle = -45;
		head->setRotation(angle);
		hand->setRotation(angle + 90);
	}
	return true;
}

/*
archerController* archerController::getInstance(){
//auto poolManager = PoolManager::getInstance();
//if (!poolManager->getCurrentPool()->isClearing() || !poolManager->isObjectInPools(archer)) {
if (archer == NULL){
archer = new archerController();
archer->initWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(Constant::getArcherFrameName()));
archer->autorelease();
//archer = (archerController*)Sprite::createWithSpriteFrameName(Constant::getArcherFrameName());
archer->initial();
}
return archer;
}

void archerController::initial() {
auto aBody = PhysicsBody::createCircle(archer->getContentSize().height / 2);
aBody->setRotationEnable(false);
archer->setPhysicsBody(aBody);
archer->setPosition(20, 100);
archer->setAnchorPoint(Vec2(0.5, 0.5));
archer->getPhysicsBody()->setContactTestBitmask(0x0000000F);
//archerSprite->getPhysicsBody()->setCollisionBitmask(0x0000000F);
archer->getPhysicsBody()->setCategoryBitmask(0x0000000F);
archer->getPhysicsBody()->getFirstShape()->setTag(Constant::getArcherTag());
}
*/



