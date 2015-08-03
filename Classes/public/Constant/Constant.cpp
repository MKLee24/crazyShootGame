﻿#include"Constant.h"

float Constant::timeLimit = 10.0;
float Constant::getTimeLimit() {
	return timeLimit;
}

//levelChosenScene
string Constant::levelChosenSceneBackgroundPath = "LevelChosenScene/bg.png";
string Constant::getLevelChosenSceneBackgroundPath() { return levelChosenSceneBackgroundPath; }

string Constant::levelChosenButton1Path = "LevelChosenScene/choose_btn_1.png";
string Constant::getLevelChosenButton1Path() { return levelChosenButton1Path; }

//gamePlayingScene
string Constant::level1MapCsdPath = "MapScene/Layer.csb";
string Constant::getLevel1MapCsdPath() { return level1MapCsdPath; }

string Constant::gameEndedPath = "GamePlayingScene/menuGameEnded.png";
string Constant::getGameEndedPath() { return gameEndedPath; }

string Constant::gameOverCsdPath = "GamePlayingScene/GameOverCsd/GameOver1.csb";
string Constant::getGameOverCsdPath() { return gameOverCsdPath; }
//arrow
string Constant::arrowPath = "GamePlayingScene/arrow/arrow.png";
string Constant::getArrowPath() { return arrowPath; }

int Constant::arrowTag = 3;//tag选择范围0-9
int Constant::getArrowTag() { return arrowTag; }

//processBar
string Constant::processBar1Path = "GamePlayingScene/processBar/processBar.png";
string Constant::getProcessBar1Path() { return processBar1Path; }

string Constant::processBar2Path = "GamePlayingScene/processBar/processBar2.png";
string Constant::getProcessBar2Path() { return processBar2Path; }

string Constant::futuraPath = "fonts/futura-48.fnt";
string Constant::getFuturaPath() { return futuraPath; }

//enemy
string Constant::enemyGoblinPath = "GamePlayingScene/enemy/Goblin/Goblin.plist";
string Constant::enemySoldierPath = "GamePlayingScene/enemy/Soldier/Soldier.plist";
string Constant::enemyArrowPath = "GamePlayingScene/enemy/EnemyArrow.png";
string Constant::enemyArrowEnemyPath = "GamePlayingScene/enemy/ArrowEnemy/ArrowEnemy.plist";
string Constant::enemyFrameName = "enemyFrameName";
string Constant::enemyAnimationName = "enemyAnimationName";
int Constant::enemyTag1 = 10;//tag选择范围10-19
int Constant::enemyTag2 = 11;
int Constant::enemyTag3 = 12;
int Constant::enemyArrowTag = 13;
string Constant::enemyBloodBackPath = "GamePlayingScene/enemy/blood_back.png";
string Constant::enemyBloodForePath = "GamePlayingScene/enemy/blood_fore.png";

string Constant::enemyArrowEnemyMove = "enemyArrowEnemyMove";
string Constant::enemyArrowEnemyAttack = "enemyArrowEnemyAttack";
string Constant::enemyArrowEnemyDeath = "enemyArrowEnemyDeath";
string Constant::enemySoldierAttack = "enemySoldierAttack";
string Constant::enemySoldierDeath = "enemySoldierDeath";
string Constant::enemySoldierMove = "enemySoldierMove";

string Constant::enemyGoblinMove = "enemyGoblinMove";
string Constant::enemyGoblinAttack = "enemyGoblinAttack";
string Constant::enemyGoblinDeath = "enemyGoblinDeath";

string Constant::getEnemyArrowEnemyMove() { return enemyArrowEnemyMove; }
string Constant::getEnemyArrowEnemyDeath() { return enemyArrowEnemyDeath; }
string Constant::getEnemyArrowEnemyAttack() { return enemyArrowEnemyAttack; }

string Constant::getEnemyGoblinMove() { return enemyGoblinMove; }
string Constant::getEnemyGoblinDeath() { return enemyGoblinDeath; }
string Constant::getEnemyGoblinAttack() { return enemyGoblinAttack; }

string Constant::getEnemySoldierMove() { return enemySoldierMove; }
string Constant::getEnemySoldierDeath() { return enemySoldierDeath; }
string Constant::getEnemySoldierAttack() { return enemySoldierAttack; }

string Constant::getEnemyGoblinPath() { return enemyGoblinPath; }
string Constant::getEnemySoldierPath() { return enemySoldierPath; }
string Constant::getEnemyArrowPath() { return enemyArrowPath; }
string Constant::getEnemyArrowEnemyPath(){ return enemyArrowEnemyPath; }
string Constant::getEnemyFrameName() { return enemyFrameName; }
string Constant::getEnemyAnimationName() { return enemyAnimationName; }
int Constant::getEnemyTag1() { return enemyTag1; }
int Constant::getEnemyTag2() { return enemyTag2; }
int Constant::getEnemyTag3() { return enemyTag3; }
int Constant::getEnemyArrowTag() { return enemyArrowTag; }
string Constant::getEnemyBloodBackPath() { return enemyBloodBackPath; }
string Constant::getEnemyBloodForePath() { return enemyBloodForePath; }

//archer
string Constant::archerbodyPath = "GamePlayingScene/archer/body.png";
string Constant::archerheadPath = "GamePlayingScene/archer/head.png";
string Constant::archerhandPath = "GamePlayingScene/archer/hand.png";
string Constant::archerFrameName = "archerFrameName";
int Constant::archerTag = 20;//tag选择范围20-29
int Constant::archerhandTag = 21;
int Constant::archerheadTag = 22;
string Constant::bloodBackPath = "GamePlayingScene/archer/blood_back.png";
string Constant::bloodForePath = "GamePlayingScene/archer/blood_fore.png";

string Constant::getArcherbodyPath() { return archerbodyPath; }
string Constant::getArcherheadPath() { return archerheadPath; }
string Constant::getArcherhandPath() { return archerhandPath; }
string Constant::getArcherFrameName() { return archerFrameName; }
int Constant::getArcherTag() { return archerTag; }
int Constant::getArcherheadTag() { return archerheadTag; }
int Constant::getArcherhandTag() { return archerhandTag; }
string Constant::getBloodBackPath() { return bloodBackPath; }
string Constant::getBloodForePath() { return bloodForePath; }

//ground
int Constant::bottomGroundTag = 30;//tag选择范围30-39
int Constant::getBottomGroundTag() { return bottomGroundTag; }

int Constant::leftGroundTag = 31;
int Constant::getLeftGroundTag() { return leftGroundTag; }