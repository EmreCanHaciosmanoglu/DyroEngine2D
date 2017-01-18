#include "SceneGraph\Objects\GameObjects\CrazyEmitter.h"
#include "SceneGraph\Objects\Components\EmitterComponent.h"

#include "Core/Data//Objects/Descriptions/Particles/EmitterComponentDescription.h"

#include "Rendering\Manager\TextureManager.h"
#include "Rendering\Objects\RenderItems\Texture.h"

namespace
{
	unsigned int PARTICLE_AMOUNT = 100;

	unsigned int TEXTURE_0 = 0;
	unsigned int TEXTURE_1 = 1;
	unsigned int TEXTURE_2 = 2;
}

CrazyEmitter::CrazyEmitter()
	:emitter(nullptr)
{
	EmitterComponentDescription* description = new EmitterComponentDescription(PARTICLE_AMOUNT);
	
	description->addTexture(TextureManager::getInstance().getTexture(TEXTURE_0));
	description->addTexture(TextureManager::getInstance().getTexture(TEXTURE_1));
	description->addTexture(TextureManager::getInstance().getTexture(TEXTURE_2));

	emitter = new EmitterComponent(description);
}
CrazyEmitter::~CrazyEmitter()
{}

bool CrazyEmitter::initialize()
{
	return true;
}
void CrazyEmitter::update()
{

}
bool CrazyEmitter::shutdown()
{
	return true;
}

void CrazyEmitter::setupInput(Input* input)
{

}