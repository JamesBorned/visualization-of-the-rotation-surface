#include "../inc/factory.hpp"

namespace mt {

	Function* FunctionFactory(const std::string& funcName)
	{
		Function* function = nullptr;

		if (funcName == "Line")
		{
			function = new Line();
			return function;
			/*double a = 0, b = 0, c = 0;

			std::cout << "������� ������� ����������� k: ";
			std::cin >> a;
			std::cout << '\n';
			std::cout << "������� �������� �������� ������ ������������ ��� x: ";
			std::cin >> b;
			std::cout << '\n';

			Line f;

			f.SurfaceArea(a, b, c);*/
			//f.VisualisationOfSurface(0, a, b, c, m_points);
		}
		else if (funcName == "Parallel")
		{
			function = new Parallel();
			return function;
			//double a = 0, b = 0, c = 0;

			//std::cout << "������� �����: ";
			//std::cin >> a;
			//std::cout << '\n';

			//Parallel f;

			//f.SurfaceArea(a, b, c);
			//f.VisualisationOfSurface(0, a, b, c, m_points);
		}
		else if (funcName == "Parabola")
		{
			function = new Parabola();
			return function;
			/*double a = 0, b = 0, c = 0;

			std::cout << "������� �������� a: ";
			std::cin >> a;
			std::cout << '\n';
			std::cout << "������� �������� b: ";
			std::cin >> b;
			std::cout << '\n';
			std::cout << "������� �������� c: ";
			std::cin >> c;
			std::cout << '\n';

			Parabola f;*/

			//f.SurfaceArea(a, b, c);
			//f.VisualisationOfSurface(0, a, b, c, m_points);
		}
		else {
			std::cout << "ERROR" << '\n';
			return nullptr;
		}

		return function;
	}
}