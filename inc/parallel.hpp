#pragma once

#include "surface.hpp"

namespace mt {
	class Parallel : public Function
	{
	public:
		Parallel();

		virtual ~Parallel();

		double ReturnA() override;

		double ReturnB() override;

		double ReturnC() override;

		double Definition(double x, double a, double b, double c) override;

		double UndIntExp(double x, double a, double b, double c) override;

		int VisualisationOfSurface(int m_size, double a, double b, double c, Point* m_points) override;

	};
}