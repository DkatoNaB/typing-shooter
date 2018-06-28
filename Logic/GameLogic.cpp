#include "GameLogic.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream> // DEBUG

GameLogic::GameLogic()
{
<<<<<<< HEAD
    srand(time(NULL));
    this->resolution = resolution;
    PLAYER_VERTICAL_POSITION = resolution.getY() - 30;
    playerPosition = Position((resolution.getX() / 2), PLAYER_VERTICAL_POSITION);
    target = 0;
    vocabulary = new Vocabulary("en");
=======
	srand((int)time(NULL));
	playerPosition = Position(PLAYER_HORIZONTAL_POSITION, PLAYER_VERTICAL_POSITION);
	target = 0;
	vocabulary = new Vocabulary("Words/en");
	currentSpawnRange = SPAWN_RANGE;
>>>>>>> 3deaa0db76294099f9348e200563f3b00641fb6b
}



void GameLogic::newGame()
{
<<<<<<< HEAD
    gameOver = false;
    score = 0;
    waveCount = 0;
    nextWave();
=======
	gameOver = false;
	score = 0;
	waveCount = 0;
	nextWave();
	easyChance = 70;
	mediumChance = 22;
	hardChance = 8;
    remainingEnemyCount = 0;
	currentSpawnRange = SPAWN_RANGE;
>>>>>>> 3deaa0db76294099f9348e200563f3b00641fb6b
}

//Updates all enemies
void GameLogic::update(float deltaTime)
{
<<<<<<< HEAD
    for (int i = 0; i < missles.size(); i++)
    {
        if(missles[i].updateWithHitTest(deltaTime))
        {
            if(target != 0){
                // TODO: lehet a missle targetje alapján kellene nézni
                //Did we hit the target?
                if (target->getText()[shotIndex] == missles[i].c)
                {	//Is it dead?
                    if (shotIndex+1 == (int)(target->getText().length()))
                    {
                        shotIndex = 0;
                        target->kill();
                        score += target->getDifficulty() * KILL_SCORE;
                        target = 0;
                        remainingEnemyCount--;
                    }
                    shotIndex++;
                    return true;
                }
                std::cout << "HIT";
            }
            missles.erase(missles.begin()+i);
        }
    }
    if (remainingEnemyCount != 0)
        for (std::vector<Enemy>::iterator iterator = enemies.begin(), end = enemies.end(); iterator != end; ++iterator)
        {
            if (!iterator->isDead()){
                iterator->update(deltaTime);
                if (iterator->getPosition().distance(playerPosition) < 5) gameOver = true;
            }
        }
    else waveOver = true;
=======
	if (remainingEnemyCount != 0)
	{
		for (std::vector<Enemy>::iterator iterator = enemies.begin(), end = enemies.end(); iterator != end; ++iterator)
		{
			if (!iterator->isExploded())
			{
				iterator->update(deltaTime);
				if (iterator->getPosition().distance(playerPosition) < 1) gameOver = true;
			}
		}

		for (std::vector<Missile>::iterator iterator = missiles.begin(), end = missiles.end(); iterator != end; ++iterator)
		{
			if (!iterator->isDead())
			{
				iterator->update(deltaTime);
			}
		}
		
	}
	else waveOver = true;
>>>>>>> 3deaa0db76294099f9348e200563f3b00641fb6b
}

//Looks for a target
bool GameLogic::aim(char c)
{
<<<<<<< HEAD
    for (std::vector<Enemy>::iterator iterator = enemies.begin(), end = enemies.end(); iterator != end; ++iterator)
    {
        //e.g: input:'c'  Enemy text: "clever"
        if (iterator->getText()[0] == c && !iterator->isDead())
        {
            target = &(*iterator);
            shootAt(c);
            return true;
        }
    }
    return false;
=======
	std::vector<std::vector<Enemy>::iterator> possibleTargets;
	for (std::vector<Enemy>::iterator iterator = enemies.begin(), end = enemies.end(); iterator != end; ++iterator)
	{
		//e.g: input:'c'  Enemy text: "clever"
		if (iterator->canShoot(c))
		{	
			possibleTargets.push_back(iterator);
		}
	}
	//Choosing best target
	if (possibleTargets.size() > 0)
	{
		int choice;
		if (possibleTargets.size() == 1)
		{
			choice = 0;
		}
		else
		{
			int minDistance = 100; //Screen size is 100
			for (int i = 0; i < possibleTargets.size(); i++)
			{
				int d = possibleTargets[i]->getPosition().distance(playerPosition);
				if (d < minDistance)
				{
					minDistance = d;
					choice = i;
				}
			}
		}
		target = &(*possibleTargets[choice]);
		shootAt(c);
		return true;
	}
	return false;
>>>>>>> 3deaa0db76294099f9348e200563f3b00641fb6b
}

//Tries to shoot something
bool GameLogic::shoot(char c)
{
    //Do we have a target?
    if (target == 0){
        //Look for a target
        return aim(c);
    }
    else{
        //Try to shoot at target
        return shootAt(c);
    }
}

//Tries to shoot at a given enemy
bool GameLogic::shootAt(char c){
<<<<<<< HEAD
    missles.push_back(Missle(Position(playerPosition.getX(),playerPosition.getY()),target,c));
    return false;
=======
	//Did we hit the target?
	if (target->canShoot(c))
	{	//Is it dead?
			//target->hit(5);
			missiles.push_back(Missile(playerPosition,target));
			target->shoot();
			if (target->isDead())
			{
				score += KILL_SCORE+(target->getText().size()/2) + waveCount;
				target = 0;
				remainingEnemyCount--;
			}
			return true;
	}
	return false;
>>>>>>> 3deaa0db76294099f9348e200563f3b00641fb6b
}

//Spawns enemies
void GameLogic::createEnemies()
{
<<<<<<< HEAD
    enemies.clear();
    enemyCount = BASE_ENEMY_COUNT + (waveCount - 1)  * BONUS_ENEMY_PER_WAVE;
    for (int i = 0; i < enemyCount; ++i)
    {
        std::string text = vocabulary->getRandomWord();
        std::cout << text << std::endl;
        Position p(rand() % ((int)resolution.getX()+1),-1* rand() % (SPAWN_RANGE));
        enemies.push_back(Enemy(text, p, playerPosition, 30));
        remainingEnemyCount++;
    }
=======
	enemies.clear();
	enemyCount = BASE_ENEMY_COUNT + (waveCount - 1)  * BONUS_ENEMY_PER_WAVE ;
	for (int i = 0; i < enemyCount; ++i)
	{
		int enemyDiff = rand() % 100;
		std::string text;

		if (enemyDiff < hardChance)
		{
			text = vocabulary->getRandomWord(Difficulty::Hard);
		}else
		if (enemyDiff < mediumChance + hardChance)
		{
			text = vocabulary->getRandomWord(Difficulty::Medium);
		}
		else
		text = vocabulary->getRandomWord(Difficulty::Easy);

		Position p(rand() % 100,-1*( 5 + i * currentSpawnRange));
		enemies.push_back(Enemy(text, p, playerPosition, 10,20));
		remainingEnemyCount++;
	}

	int easy_t = easyChance;
	easyChance *= 0.9f;
	mediumChance += 100 / (easy_t - easyChance) * 0.7f;
	hardChance = 100 - mediumChance - easyChance;

	currentSpawnRange *= 0.95f;

>>>>>>> 3deaa0db76294099f9348e200563f3b00641fb6b
}

void GameLogic::nextWave()
{
<<<<<<< HEAD
    waveOver = false;
    waveCount++;
    createEnemies();
=======
	missiles.clear();
	waveOver = false;
	waveCount++;
	createEnemies();
>>>>>>> 3deaa0db76294099f9348e200563f3b00641fb6b
}
