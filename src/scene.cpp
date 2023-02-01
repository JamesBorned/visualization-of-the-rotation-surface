#include "../inc/scene.hpp"
#include "../inc/factory.hpp"
#include <cmath>

namespace mt
{
	Scene::Scene(int width, int height)
	{
		m_width = width;
		m_height = height;
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "3D Engine");
		m_texture = std::make_unique<sf::Texture>();
		m_texture->create(m_width, m_height);
		m_sprite = std::make_unique<sf::Sprite>(*m_texture); // разыменование указателя

		Intrinsic intrinsic = { 960.0, 540.0, 960.0, 540.0 };
		Point position = { 0.0, 0.0, 0.0 };
		Angles angles = { 0.0,0.0,0.0 };
		m_camera = std::make_unique<Camera>(m_width, m_height, intrinsic, position, angles);

		m_points = new Point[20000000];
	}

	Scene::~Scene()
	{
		if (m_points != nullptr)
			delete[] m_points;
	}

	void Scene::LifeCycle()
	{
		std::string funcName;
		std::cout << "Введите название объекта (Parabola, Parallel, Line): ";
		std::cin >> funcName;

		Function* f = FunctionFactory(funcName);

		if (f == nullptr){
			return;
		}

		double a = f->ReturnA();
		double b = f->ReturnB();
		double c = f->ReturnC();

		f->SurfaceArea(a, b, c);
		
		std::cout << "Enter the number of the surface color you selected from all the colors of the rainbow" << '\n';
		std::cout << "(red - 1, orange - 2, yellow - 3, green - 4, cyan - 5, blue - 6, purple - 7): ";

		int Colorofs = 0;
		std::cin >> Colorofs;
		Pixel pixel = f->Color({ 0,0,0,0 }, Colorofs);

		while (m_window->isOpen()) {
			sf::Event event;
			while (m_window->pollEvent(event))
				if (event.type == sf::Event::Closed)
					m_window->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				m_camera->dZ(10);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				m_camera->dZ(-10);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				m_camera->dX(-5);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				m_camera->dX(5);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				m_camera->dPitch(-0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				m_camera->dPitch(0.3);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				m_camera->dRoll(-0.02);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				m_camera->dRoll(0.02);
			}

			f->VisualisationOfSurface(0,a,b,c, m_points);
			int m = f->VisualisationOfSurface(0, a, b, c, m_points);
			//std::cout << m << '\n';

			for (int i = 0; i < 50; ++i) {
				m_camera->dX(-0.009);
				m_camera->dZ(-0.09);
			}

			for (int i = 0; i < m; i++) {
				m_camera->ProjectPoint(m_points[i], pixel);
			}

			m_texture->update((uint8_t*)m_camera->Picture(), 1920, 1080, 0, 0);
			m_camera->Clear();


			m_window->clear();
			m_window->draw(*m_sprite);

			m_window->display();

		}

		f->~Function();
	}
}

