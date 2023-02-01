#include <iostream>
#include <cmath>
#include <vector>
#include "../inc/scene.hpp"
#include <string>
#include "../inc/surface.hpp"

namespace mt {

		Function::Function() {
			std::cout << "Function constructor" << '\n';
			m_points = new Point[20000000];
			m_width = 1920;
			m_height = 1080;

			Intrinsic intrinsic = { 960.0, 540.0, 960.0, 540.0 };
			Point position = { 0.0, 0.0, 0.0 };
			Angles angles = { 0.0,0.0,0.0 };
			m_camera = std::make_unique<Camera>(m_width, m_height, intrinsic, position, angles);
		}

		Function::~Function() {
			std::cout << "Function destructor" << '\n';
			if (m_points != nullptr)
				delete[] m_points;
		}

		double Function::SimpsonMethod(double a, double b, int n, double a1, double b1, double c1) {
			const double h = (b - a) / n;
			double k1 = 0, k2 = 0;

			for (int i = 1; i < n; i += 2) {
				k1 += UndIntExp(a + i * h, a1, b1, c1);
				k2 += UndIntExp(a + (i + 1) * h, a1, b1, c1);
			}

			return h / 3 * (UndIntExp(a, a1, b1, c1) + 4 * k1 + 2 * k2);
		}

		void Function::SurfaceArea(double a1, double b1, double c1) {
			double a, b, eps;
			double s1, s = 0;
			int n = 1; //начальное число шагов

			std::cout << "¬ведите левую границу интегрировани€ a = ";
			std::cin >> a;
			std::cout << "\n¬ведите правую границу интегрировани€ b = ";
			std::cin >> b;
			std::cout << "\n¬ведите требуемую точность eps = ";
			std::cin >> eps;

			s1 = SimpsonMethod(a, b, n, a1, b1, c1); //первое приближение дл€ интеграла
			do {
				s = s1; //второе приближение
				n = 2 * n; //увеличение числа шагов в два раза,
						   //т.t. уменьшение значени€ шага в два раза
				s1 = SimpsonMethod(a, b, n, a1, b1, c1);
			} while (fabs(s1 - s) > eps); // сравнение приближений с заданной точностью

			std::cout << "\n»нтеграл = " << s1 << '\n';
		}

		Pixel Function::Color(Pixel pixel, int ColorOfSurface) {
			enum AllColors {
				Red = 1,
				Orange,
				Yellow,
				Green,
				Cyan,
				Blue,
				Purple,
			};

			switch (ColorOfSurface) {
			case Red:
				pixel = { 255, 0, 0, 255 };
				return pixel;
				break;
			case Orange:
				pixel = { 247, 136, 0, 255 };
				return pixel;
				break;
			case Yellow:
				pixel = { 247, 234, 0, 255 };
				return pixel;
				break;
			case Green:
				pixel = { 0, 255, 0, 255 };
				return pixel;
				break;
			case Cyan:
				pixel = { 40, 167, 215, 255 };
				return pixel;
				break;
			case Blue:
				pixel = { 0, 0, 255, 255 };
				return pixel;
				break;
			case Purple:
				pixel = { 115, 32, 183, 255 };
				return pixel;
				break;
			default:
				std::cout << "ERROR" << '\n';
				pixel = { 255, 255, 255, 255 };
				return pixel;
				break;
			}
		}
}


	//Line::Line();
	//	{
	//		std::cout << "Line class : constructor" << std::endl;
	//	}

	//	virtual Function::~Line()
	//	{
	//		std::cout << "Line class: destructor" << std::endl;
	//	}
	//	
	//	double Line::ReturnA() {
	//		double a;
	//		std::cout << "¬ведите угловой коэффициент k: ";
	//		std::cin >> a;
	//		std::cout << '\n';

	//		return a;
	//	}

	//	double ReturnB() {
	//		double b;
	//		std::cout << "¬ведите значение смещени€ пр€мой относительно оси x: ";
	//		std::cin >> b;
	//		std::cout << '\n';

	//		return b;
	//	}

	//	double ReturnC() {
	//		return 0;
	//	}

	//	double Definition(double x, double a, double b, double c) override {
	//		return a * x + b;
	//	}

	//	double UndIntExp(double x, double a, double b, double c) override {
	//		return 2 * pi * Definition(x, a, b, c) * pow(1 + pow(a, 2), static_cast<double>(1) / 2);
	//	}

	//	void VisualisationOfSurface(int m_size, double a, double b, double c, Point* m_points) override {
	//		for (int x = 0; x < 600; ++x) {
	//			//m_points[m_size].x = x;
	//			//m_points[m_size].y = x;
	//			for (double t = 0; t < 6.28; t += 0.01) {
	//				m_points[m_size].z = x * cos(t);
	//				m_points[m_size].x = x * sin(t);
	//				m_points[m_size].y = Definition(x, a, b, c);
	//				m_size++;
	//				//m_camera->dZ(-0.1);
	//			}
	//			//m_size++;
	//			/*do {
	//				m_camera->dZ(-0.009);
	//			} while (() > 500);*/
	//			//m_camera->dZ(-0.009);

	//		}
	//	}

	//};

	//class Parallel : public Function
	//{
	//public:
	//	Parallel() : Function()
	//	{
	//		std::cout << "Parallel class : constructor" << std::endl;
	//	}

	//	virtual ~Parallel()
	//	{
	//		std::cout << "Parallel class: destructor" << std::endl;
	//	}

	//	double ReturnA() {
	//		double a;
	//		std::cout << "¬ведите число: ";
	//		std::cin >> a;
	//		std::cout << '\n';

	//		return a;
	//	}

	//	double ReturnB() {
	//		return 0;
	//	}

	//	double ReturnC() {
	//		return 0;
	//	}

	//	double Definition(double x, double a, double b, double c) override {
	//		return a;
	//	}

	//	double UndIntExp(double x, double a, double b, double c) override
	//	{
	//		return 2 * pi * Definition(x, a, b, c) * pow(1, static_cast<double>(1) / 2);
	//	}

	//	void VisualisationOfSurface(int m_size, double a, double b, double c, Point* m_points) override {

	//	}

	//};

	//class Parabola : public Function
	//{
	//public:
	//	Parabola() : Function()
	//	{
	//		std::cout << "Parabola class : constructor" << std::endl;
	//	}

	//	virtual ~Parabola()
	//	{
	//		std::cout << "Parabola class: destructor" << std::endl;
	//	}

	//	double ReturnA() {
	//		double a;
	//		std::cout << "¬ведите параметр a: ";
	//		std::cin >> a;
	//		std::cout << '\n';

	//		return a;
	//	}

	//	double ReturnB() {
	//		double b;
	//		std::cout << "¬ведите параметр b: ";
	//		std::cin >> b;
	//		std::cout << '\n';

	//		return b;
	//	}

	//	double ReturnC() {
	//		double c;
	//		std::cout << "¬ведите параметр c: ";
	//		std::cin >> c;
	//		std::cout << '\n';

	//		return c;
	//	}

	//	double Definition(double x, double a, double b, double c) override {
	//		return a * pow(x, 2) + b * x + c;
	//	}

	//	double UndIntExp(double x, double a, double b, double c) override
	//	{
	//		return 2 * pi * Definition(x, a, b, c) * pow(1 + pow(2 * a * x + b, 2), static_cast<double>(1) / 2);
	//	}

	//	void VisualisationOfSurface(int m_size, const double a1, const double b1, const double c1, Point* m_points) override {
	//		for (int x = 0; x < 50; ++x) {
	//			for (double a = 0; a < 6.28; a += 0.01) {
	//				m_points[m_size].z = x * cos(a);
	//				m_points[m_size].x = x * sin(a);
	//				m_points[m_size].y = (Definition(x, a1, b1, c1)) / 16;
	//				//m_points[m_size].y = pow(x,2) / 16;
	//				m_size++;
	//				/*Camera k;
	//				k.dZ(-0.5);*/
	//			}
	//			/*for (int i = 0; i < m_size; i++)
	//				m_camera->ProjectPoint(m_points[i], { 255, 0, 0, 255 });*/
	//			//m_size++;
	//			/*do {
	//				m_camera->dZ(-0.009);
	//			} while (() > 500);*/
	//			/*m_camera->dX(-0.0009);
	//			m_camera->dZ(-0.009);
	//			m_camera->dZ(-0.2);*/

	//		}
	//		//Pixel pixel = Color();
	//		/*for (int i = 0; i < m_size; i++)
	//			m_camera->ProjectPoint(m_points[i], {255,0,255,225});*/
	//		//std::cout << m_size << '\n';
	//		//return m_size;
	//	}
	//};

	////Function* FunctionFactory(const std::string& funcName)
	////{
	////	Function* function = nullptr;

	////	if (funcName == "Line")
	////	{
	////		function = new Line();

	////		/*double a = 0, b = 0, c = 0;

	////		std::cout << "¬ведите угловой коэффициент k: ";
	////		std::cin >> a;
	////		std::cout << '\n';
	////		std::cout << "¬ведите значение смещени€ пр€мой относительно оси x: ";
	////		std::cin >> b;
	////		std::cout << '\n';

	////		Line f;

	////		f.SurfaceArea(a, b, c);*/
	////		//f.VisualisationOfSurface(0, a, b, c, m_points);
	////	}
	////	else if (funcName == "Parallel")
	////	{
	////		function = new Parallel();

	////		//double a = 0, b = 0, c = 0;

	////		//std::cout << "¬ведите число: ";
	////		//std::cin >> a;
	////		//std::cout << '\n';

	////		//Parallel f;

	////		//f.SurfaceArea(a, b, c);
	////		//f.VisualisationOfSurface(0, a, b, c, m_points);
	////	}
	////	else if (funcName == "Parabola")
	////	{
	////		function = new Parabola();
	////		
	////		/*double a = 0, b = 0, c = 0;

	////		std::cout << "¬ведите параметр a: ";
	////		std::cin >> a;
	////		std::cout << '\n';
	////		std::cout << "¬ведите параметр b: ";
	////		std::cin >> b;
	////		std::cout << '\n';
	////		std::cout << "¬ведите параметр c: ";
	////		std::cin >> c;
	////		std::cout << '\n';

	////		Parabola f;*/

	////		//f.SurfaceArea(a, b, c);
	////		//f.VisualisationOfSurface(0, a, b, c, m_points);
	////	}
	////	else {
	////		std::cout << "ERROR" << '\n';
	////	}

	////	return function;
	////}
