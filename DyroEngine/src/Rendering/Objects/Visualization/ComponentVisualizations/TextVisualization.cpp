#include "Rendering\Objects\Visualization\ComponentVisualizations\TextVisualization.h"
#include "Rendering/Objects/Visualization/GameObjectVisualizations/GameObjectVisualization.h"
#include "Rendering\Objects\RenderItems\Text.h"

#include "SceneGraph\Objects\GameObjects\SceneObject.h"
#include "SceneGraph\Objects\Components\TextComponent.h"
#include "SceneGraph\Objects\Scenes\Scene.h"

#include "Core/Data/Objects/Descriptions/Text/TextDescription.h"

#include "Core/Defines/deletemacros.h"

TextVisualization::TextVisualization(Component* object, const std::tstring& name)
	:ConcreteComponentVisualization(object, name)
	, text(nullptr)
{
}
TextVisualization::~TextVisualization()
{
}

bool TextVisualization::initialize()
{
	TextComponent* component = dynamic_cast<TextComponent*>(getObject());
	if (component == nullptr)
		return false;

	this->text = new Text(component->getDescription());

	return true;
}
bool TextVisualization::shutdown()
{
	SafeDelete(this->text);

	return true;
}

Rect2D TextVisualization::getBoundingBox() const
{
	return this->text->getBounds();
}

void TextVisualization::generateRenderItems(std::vector<RenderItem*>& items)
{
	TextComponent* component = getConcreteComponent();
	if (this->text->getTextDescription()->getText() != component->getText())
		this->text->getTextDescription()->setText(component->getText());
	if (this->text->getTextDescription()->getFont() != component->getFont())
		this->text->getTextDescription()->setFont(component->getFont());

	GameObjectVisualization* parent = dynamic_cast<GameObjectVisualization*>(getParent());
	if (parent != nullptr)
	{
		SceneObject* parent_object = dynamic_cast<SceneObject*>(parent->getObject());

		Vector2D center = Vector2D((float)(this->text->getTextDescription()->getLayoutBox().getWidth()) / 2.0f, (float)(this->text->getTextDescription()->getLayoutBox().getHeight()) / 2.0f);

		this->text->setTransform(parent->getPosition() - center, parent->getScale(), parent->getRotation());
		this->text->setLayer(parent_object->getLayer());
	}

	items.push_back(this->text);
}