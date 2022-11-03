#include "VEngine.hpp"

namespace Graphics
{

	VEngine::VEngine( const uint32_t p_w, const uint32_t p_h ) noexcept :
	_VDriver { std::make_unique<VDriver>(p_w,p_h) },
	_VRscManager { std::make_unique<VResourceManager>( _VDriver.get()->getVkDevice() ) }
	{
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	VEngine::~VEngine() noexcept
	{
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	GLFWwindow&
	VEngine::getWindow() const noexcept
	{
		assert(_VDriver.get());
		return *_VDriver.get()->getWindow();
	}

}