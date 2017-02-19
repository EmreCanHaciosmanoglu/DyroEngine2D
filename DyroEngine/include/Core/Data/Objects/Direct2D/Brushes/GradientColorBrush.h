#ifndef _GRADIENTCOLORBRUSH_H
#define _GRADIENTCOLORBRUSH_H

#include "Core/Data/Objects/Direct2D/Brushes/ColorBrush.h"

#ifndef _COLOR_H
#include "Core/Defines/color.h"
#endif
#ifndef _VECTOR_
#include <vector>
#endif

class RenderTarget;

class GradientColorsCollection
{
public:
	GradientColorsCollection(RenderTarget* renderTarget);
	GradientColorsCollection(const GradientColorsCollection& collection);
	~GradientColorsCollection();

	void setGradientColorsCollectionGamma(const D2D1_GAMMA& gamma);
	void setGradientColorsCollectionExtendMode(const D2D1_EXTEND_MODE& mode);

	void addColor(const Color& color, float position);

	ID2D1GradientStopCollection* getCollection();

private:
	std::vector<D2D1_GRADIENT_STOP> stops;
	ID2D1GradientStopCollection* gradient_colors_collection;
	bool create_collection;
	RenderTarget* render_target;
	D2D1_GAMMA collection_gamma;
	D2D1_EXTEND_MODE collection_mode;
};

class GradientColorBrush : public ColorBrush
{
public:
	GradientColorBrush(RenderTarget* renderTarget, GradientColorsCollection& collection);
	virtual ~GradientColorBrush();

	virtual bool create() = 0;

protected:
	const GradientColorsCollection& getGradientColorsCollection() const;

private:
	GradientColorsCollection gradient_colors_collection;
};

#endif