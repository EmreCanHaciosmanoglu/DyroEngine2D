#include "Core/Data/Objects/Direct2D/Text/TextLayout.h"
#include "Core/Data/Objects/Direct2D/Text/TextFormat.h"

#include "Core/Defines/deletemacros.h"

TextLayout::TextLayout()
	:layout(nullptr)
{}
TextLayout::~TextLayout()
{
	SafeRelease(this->layout);
}

bool TextLayout::create(IDWriteFactory* factory, const std::tstring& text, TextFormat* format, const Rect2D& layoutBox)
{
	HRESULT hr = factory->CreateTextLayout(text.c_str(), (UINT32)text.size(), format->getFormat(), (float)layoutBox.getWidth(), (float)layoutBox.getHeight(), &layout);

	return hr == S_OK;
}

float TextLayout::getMaxWidth() const
{
	return this->layout->GetMaxWidth();
}
float TextLayout::getMaxHeight() const
{
	return this->layout->GetMaxHeight();
}

Rect2D TextLayout::getTextBounds(bool includeWhitespace) const
{
	Rect2D metrics;

	DWRITE_TEXT_METRICS dw_metrics;
	this->layout->GetMetrics(&dw_metrics);

	metrics.left = dw_metrics.left;
	metrics.top = dw_metrics.top;
	metrics.right = metrics.left + includeWhitespace ? dw_metrics.widthIncludingTrailingWhitespace : dw_metrics.width;
	metrics.bottom = metrics.top + dw_metrics.height;

	return metrics;
}
Rect2D TextLayout::getLayoutBounds() const
{
	Rect2D metrics;

	DWRITE_TEXT_METRICS dw_metrics;
	this->layout->GetMetrics(&dw_metrics);

	metrics.left = dw_metrics.left;
	metrics.top = dw_metrics.top;
	metrics.right = metrics.left + dw_metrics.layoutWidth;
	metrics.bottom = metrics.top + dw_metrics.layoutHeight;

	return metrics;
}

UINT32 TextLayout::getNumberOfLines() const
{
	DWRITE_TEXT_METRICS dw_metrics;
	this->layout->GetMetrics(&dw_metrics);

	return dw_metrics.lineCount;
}

IDWriteTextLayout* TextLayout::getLayout() const
{
	return this->layout;
}