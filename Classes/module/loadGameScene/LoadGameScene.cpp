#include"LoadGameScene.h"


bool LoadGameScene::init() {
	//init numOfCells
	numOfCells = getNumOfRecord();

	auto backgroundSprite = Sprite :: create("image/background.png");
	backgroundSprite->setPosition(0, 0);
	backgroundSprite->setAnchorPoint(Vec2(0, 0));
	this->addChild(backgroundSprite, 0);

	TableView *listOfRecord = TableView::create(this, Size(300,300));

	return true;
}

int LoadGameScene::getNumOfRecord(){
	int number;//number Ҫ�����ݿ��ȡ
	
	number = 10;//testʹ��
	
	return number;
}

/*TableViewCell* LoadGameScene::tableCellAtIndex(TableView *table, ssize_t idx){

	Size visibleSize = Director::getInstance()->getVisibleSize();//��õ�ǰ�ɼ�����

	TableViewCell* cell = table->dequeueCell();
	auto del= MenuItemImage::create(
		"CloseNormal.png",
		"CloseNormal.png",
		CC_CALLBACK_1(LoadGameScene::deleteIterm, this));
	Menu* deleteButton = Menu::create(del, NULL);
	deleteButton->setAnchorPoint(Point(1, 0));//��ê���������
//	deleteButton->setPosition(visibleSize.width,cell->getS)
	if (cell == NULL){
		cell = TableViewCell::create();
		cell->addChild(deleteButton);
	}
}*/

ssize_t LoadGameScene:: numberOfCellsInTableView(TableView *table){
	return numOfCells;;
}

void LoadGameScene::deleteIterm(){

}