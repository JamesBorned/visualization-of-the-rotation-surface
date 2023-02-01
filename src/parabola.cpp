#include "../inc/parabola.hpp"

namespace mt {
		Parabola::Parabola() : Function()
		{
			std::cout << "Parabola class : constructor" << std::endl;
		}

		Parabola::~Parabola()
		{
			std::cout << "Parabola class: destructor" << std::endl;
		}

		double Parabola::ReturnA() {
			double a;
			std::cout << "¬ведите параметр a: ";
			std::cin >> a;
			std::cout << '\n';

			return a;
		}

		double Parabola::ReturnB() {
			double b;
			std::cout << "¬ведите параметр b: ";
			std::cin >> b;
			std::cout << '\n';

			return b;
		}

		double Parabola::ReturnC() {
			double c;
			std::cout << "¬ведите параметр c: ";
			std::cin >> c;
			std::cout << '\n';

			return c;
		}

		double Parabola::Definition(double x, double a, double b, double c) {
			return a * pow(x, 2) + b * x + c;
		}

		double Parabola::UndIntExp(double x, double a, double b, double c)
		{
			return 2 * pi * Definition(x, a, b, c) * pow(1 + pow(2 * a * x + b, 2), static_cast<double>(1) / 2);
		}

		int Parabola::VisualisationOfSurface(int m_size, const double a1, const double b1, const double c1, Point* m_points) {
			for (int x = 0; x < 150; ++x) {
				for (double a = 0; a < 6.28; a += 0.01) {
					m_points[m_size].z = x * cos(a);
					m_points[m_size].x = x * sin(a);
					m_points[m_size].y = (Definition(x, a1, b1, c1)) / 100;
					//m_points[m_size].y = pow(x,2) / 16;
					m_size++;
					/*Camera k;
					k.dZ(-0.5);*/
				}
				/*for (int i = 0; i < m_size; i++)
					m_camera->ProjectPoint(m_points[i], { 255, 0, 0, 255 });*/
				//m_size++;
				/*do {
					m_camera->dZ(-0.009);
				} while (() > 500);*/
				/*m_camera->dX(-0.0009);
				m_camera->dZ(-0.009);
				m_camera->dZ(-0.2);*/

			}
			//Pixel pixel = Color();
			/*for (int i = 0; i < m_size; i++)
				m_camera->ProjectPoint(m_points[i], {255,0,255,225});*/
			//std::cout << m_size << '\n';
			return m_size;
		}

}