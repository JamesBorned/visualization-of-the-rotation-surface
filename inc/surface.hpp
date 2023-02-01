#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "scene.hpp"
#include <string>

namespace mt {

	//Базовый класс
	class Function {
	public:
		Function();
		virtual ~Function();

		double SimpsonMethod(double a, double b, int n, double a1, double b1, double c1);

		virtual double Definition(double x, double a, double b, double c) = 0;
		virtual int VisualisationOfSurface(int m_size, double a, double b, double c, Point* m_points) = 0;
		virtual double UndIntExp(double x, double a, double b, double c) = 0;
		virtual double ReturnA() = 0;
		virtual double ReturnB() = 0;
		virtual double ReturnC() = 0;

		void SurfaceArea(double a1, double b1, double c1);

		Pixel Color(Pixel pixel, int ColorOfSurface);

	protected:
		const double pi = 3.14;
		Point* m_points = nullptr;
		std::unique_ptr<Camera> m_camera; // умный указатель

	private:
		int m_width;
		int m_height;
	};
}


//	// Потомок
//	class Line : public Function
//	{
//	public:
//
//		Line() : Function() {};
//
//		virtual ~Line() {
//
//			std::cout << "Line class: destructor" << std::endl;
//		}
//
//		double ReturnA();
//
//		double ReturnB();
//
//		double ReturnC();
//
//		double Definition(double x, double a, double b, double c) override;
//
//		double UndIntExp(double x, double a, double b, double c) override;
//
//		void VisualisationOfSurface(int m_size, double a, double b, double c, Point* m_points) override;
//
//	};
//
//	class Parallel : public Function
//	{
//	public:
//		Parallel();
//		virtual ~Parallel();
//
//		double ReturnA();
//
//		double ReturnB();
//
//		double ReturnC();
//
//		double Definition(double x, double a, double b, double c) override;
//
//		double UndIntExp(double x, double a, double b, double c) override;
//
//		void VisualisationOfSurface(int m_size, double a, double b, double c, Point* m_points) override;
//	};
//
//	class Parabola : public Function
//	{
//	public:
//		Parabola() : Function() {};
//
//		virtual ~Parabola();
//
//		double ReturnA();
//
//		double ReturnB();
//
//		double ReturnC();
//
//		double Definition(double x, double a, double b, double c) override;
//
//		double UndIntExp(double x, double a, double b, double c) override;
//
//		void VisualisationOfSurface(int m_size, const double a1, const double b1, const double c1, Point* m_points) override;
//	};
//
//	Function* FunctionFactory(const std::string& funcName)
//	{
//		Function* function = nullptr;
//
//		if (funcName == "Line")
//		{
//			function = new Line();
//
//			/*double a = 0, b = 0, c = 0;
//
//			std::cout << "Введите угловой коэффициент k: ";
//			std::cin >> a;
//			std::cout << '\n';
//			std::cout << "Введите значение смещения прямой относительно оси x: ";
//			std::cin >> b;
//			std::cout << '\n';
//
//			Line f;
//
//			f.SurfaceArea(a, b, c);*/
//			//f.VisualisationOfSurface(0, a, b, c, m_points);
//		}
//		else if (funcName == "Parallel")
//		{
//			function = new Parallel();
//
//			//double a = 0, b = 0, c = 0;
//
//			//std::cout << "Введите число: ";
//			//std::cin >> a;
//			//std::cout << '\n';
//
//			//Parallel f;
//
//			//f.SurfaceArea(a, b, c);
//			//f.VisualisationOfSurface(0, a, b, c, m_points);
//		}
//		else if (funcName == "Parabola")
//		{
//			function = new Parabola();
//
//			/*double a = 0, b = 0, c = 0;
//
//			std::cout << "Введите параметр a: ";
//			std::cin >> a;
//			std::cout << '\n';
//			std::cout << "Введите параметр b: ";
//			std::cin >> b;
//			std::cout << '\n';
//			std::cout << "Введите параметр c: ";
//			std::cin >> c;
//			std::cout << '\n';
//
//			Parabola f;*/
//
//			//f.SurfaceArea(a, b, c);
//			//f.VisualisationOfSurface(0, a, b, c, m_points);
//		}
//		else {
//			std::cout << "ERROR" << '\n';
//		}
//
//		return function;
//	}
//}