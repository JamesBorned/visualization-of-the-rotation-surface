#include "../inc/parallel.hpp"

namespace mt {

		Parallel::Parallel() : Function()
		{
			std::cout << "Parallel class : constructor" << std::endl;
		}

		Parallel::~Parallel()
		{
			std::cout << "Parallel class: destructor" << std::endl;
		}

		double Parallel::ReturnA() {
			double a;
			std::cout << "¬ведите число: ";
			std::cin >> a;
			std::cout << '\n';

			return a;
		}

		double Parallel::ReturnB() {
			return 0;
		}

		double Parallel::ReturnC() {
			return 0;
		}

		double Parallel::Definition(double x, double a, double b, double c) {
			return a;
		}

		double Parallel::UndIntExp(double x, double a, double b, double c)
		{
			return 2 * pi * Definition(x, a, b, c) * pow(1, static_cast<double>(1) / 2);
		}

		int Parallel::VisualisationOfSurface(int m_size, double a, double b, double c, Point* m_points) {
			for (int x = 0; x < 100; ++x) {
				//m_points[m_size].x = x;
				//m_points[m_size].y = x;
				for (double t = 0; t < 6.28; t += 0.01) {
					m_points[m_size].z = Definition(x, a, b, c) * cos(t);
					m_points[m_size].x = Definition(x, a, b, c) * sin(t);
					m_points[m_size].y = x;
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