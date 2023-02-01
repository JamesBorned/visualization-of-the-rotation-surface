#include <SFML/Graphics.hpp>
#include "inc/scene.hpp"

int main()
{
	setlocale(LC_ALL, "Russian");

	mt::Scene scene(1920, 1080);
	scene.LifeCycle();

	return 0;
}