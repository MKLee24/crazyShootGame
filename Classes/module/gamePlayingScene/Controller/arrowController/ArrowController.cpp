#include"ArrowController.h"
USING_NS_CC;
#include"../../../../public/parameterManager/ParameterManager.h"
#include"../../Model/Constant/Constant.h"
#include"../progressTimeController/ProgressTimeController.h"

#define pi 3.141592654

ArrowController::ArrowController() {}

ArrowController* ArrowController::createAnArrow(float xEnd, float yEnd) {
	Size visibleSize = ParameterManager::getVisibleSize();
	Size archerSize = Size(100, 100);//���д��

	float xBegin = 0;
	float yBegin = 0;

	//auto arrowSprite = (ArrowController*)Sprite::create(Constant::getArrowPath());
	auto arrowSprite = new ArrowController();
	arrowSprite->initWithFile(Constant::getArrowPath());
	arrowSprite->autorelease();

	auto arrowBody = PhysicsBody::createBox(arrowSprite->getContentSize());
	arrowBody->getFirstShape()->setTag(Constant::getArrowTag());
	arrowSprite->setPhysicsBody(arrowBody);

	float angle = -atan((yBegin - yEnd) / (xBegin - xEnd)) / pi * 180;
	if (xBegin >= xEnd) {
		angle += 180;
	}
	arrowSprite->setRotation(angle);

	arrowSprite->setPosition(50,50);
	float a = ParameterManager::getArrowMaxVelocity();
	float arrowVelocityX = ProgressTimeController::getInstance()->getProgressTimer()->getPercentage() / 100 * ParameterManager::getArrowMaxVelocity() * cos(angle / 180 * pi) + 10;
	float arrowVelocityY = ProgressTimeController::getInstance()->getProgressTimer()->getPercentage() / 100 * ParameterManager::getArrowMaxVelocity() * sin(angle / 180 * pi) + 10;
	arrowBody->setVelocity(Vec2(arrowVelocityX, -arrowVelocityY));

	arrowSprite->getPhysicsBody()->setContactTestBitmask(0x0000F0F0);
	arrowSprite->getPhysicsBody()->setCategoryBitmask(0x0000F0F0);

	return arrowSprite;
}