#include "scene.h"
//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>

void Scene::hoverSound(bool f)
{
	if (f)
	{
		hbuffer.loadFromFile("Resources/Sounds/ooa.wav");
		hsound.setBuffer(hbuffer);
		hsound.setVolume(50);
		hsound.play();
	}	
}

Scene::Scene() = default;
Scene::~Scene() = default;
