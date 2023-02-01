#include "../inc/line.hpp"

namespace mt {

		Line::Line() : Function() {
			
			std::cout << "Line class : constructor" << std::endl;
		}

		Line::~Line()
		{
			std::cout << "Line class: destructor" << std::endl;
		}

		double Line::ReturnA() {
			double a;
			std::cout << "¬ведите угловой коэффициент k: ";
			std::cin >> a;
			std::cout << '\n';

			return a;
		}

		double Line::ReturnB() {
			double b;
			std::cout << "¬ведите значение смещени€ пр€мой относительно оси x: ";
			std::cin >> b;
			std::cout << '\n';

			return b;
		}

		double Line::ReturnC() {
			return 0;
		}

		double Line::Definition(double x, double a, double b, double c){
			return a * x + b;
		}

		double Line::UndIntExp(double x, double a, double b, double c){
			return 2 * pi * Definition(x, a, b, c) * pow(1 + pow(a, 2), static_cast<double>(1) / 2);
		}

		int Line::VisualisationOfSurface(int m_size, double a, double b, double c, Point* m_points){
			for (int x = 0; x < 1000; ++x) {
				//m_points[m_size].x = x;
				//m_points[m_size].y = x;
				for (double t = 0; t < 6.28; t += 0.01) {
					m_points[m_size].z = x * cos(t);
					m_points[m_size].x = x * sin(t);
					m_points[m_size].y = Definition(x, a, b, c);
					//m_points[m_size].y = x / 50;
					m_size++;
					//m_camera->dZ(-0.1);
				}
				//m_size++;
				/*do {
					m_camera->dZ(-0.009);
				} while (() > 500);*/
				//m_camera->dZ(-0.009);
				//std::cout << m_size << '\n';
			}
			//std::cout << m_size << '\n';
			return m_size;
		}
}
