#include "Core/Data/Objects/Direct2D/Brushes/GradientColorBrush.h"

#ifndef _RENDERTARGET_H
#include "Core/Data/Objects/Direct2D/RenderTarget.h"
#endif

#ifndef _ALGORITHM_
#include <algorithm>
#endif

GradientColorsCollection::GradientColorsCollection(RenderTarget* renderTarget)
	:gradient_colors_collection(nullptr)
	,create_collection(true)
	,render_target(renderTarget)
	,collection_gamma(D2D1_GAMMA_2_2)
	,collection_mode(D2D1_EXTEND_MODE_WRAP)
{
	stops = { D2D1_GRADIENT_STOP {D2D1::ColorF::Black, 0.0f}, D2D1_GRADIENT_STOP {D2D1::ColorF::White, 1.0f} };
}
GradientColorsCollection::GradientColorsCollection(const GradientColorsCollection& collection)
	: gradient_colors_collection(collection.gradient_colors_collection)
	, create_collection(collection.create_collection)
	, render_target(collection.render_target)
	, collection_gamma(collection.collection_gamma)
	, collection_mode(collection.collection_mode)
	, stops(collection.stops)
{}
GradientColorsCollection::~GradientColorsCollection()
{
	if(this->gradient_colors_collection)
		this->gradient_colors_collection->Release();
}

void GradientColorsCollection::setGradientColorsCollectionGamma(const D2D1_GAMMA& gamma)
{
	this->collection_gamma = gamma;
}
void GradientColorsCollection::setGradientColorsCollectionExtendMode(const D2D1_EXTEND_MODE& mode)
{
	this->collection_mode = mode;
}

void GradientColorsCollection::addColor(const Color& color, float position)
{
	std::vector<D2D1_GRADIENT_STOP>::const_iterator it = std::find_if(this->stops.begin(), this->stops.end(),
		[position](const D2D1_GRADIENT_STOP& stop) -> bool
	{
		return abs(stop.position - position) < FLT_EPSILON;
	});

	if (it == this->stops.end())
	{
		D2D1_GRADIENT_STOP new_stop;
		new_stop.color = D2D1::ColorF(color.red, color.green, color.blue, color.alpha);
		new_stop.position = position;

		this->stops.push_back(new_stop);

		create_collection = true;
	}
}

ID2D1GradientStopCollection* GradientColorsCollection::getCollection()
{
	if (this->create_collection && this->gradient_colors_collection)
	{
		this->gradient_colors_collection->Release();
		this->gradient_colors_collection = nullptr;

		render_target->getRenderTarget()->CreateGradientStopCollection(
			this->stops.data(),
			(unsigned int)this->stops.size(),
			this->collection_gamma,
			this->collection_mode,
			&this->gradient_colors_collection);

		this->create_collection = false;
	}

	return this->gradient_colors_collection;
}

GradientColorBrush::GradientColorBrush(RenderTarget* renderTarget, GradientColorsCollection& collection)
	:ColorBrush(renderTarget)
	,gradient_colors_collection(renderTarget)
{}
GradientColorBrush::~GradientColorBrush()
{}

const GradientColorsCollection& GradientColorBrush::getGradientColorsCollection() const
{
	return this->gradient_colors_collection;
}