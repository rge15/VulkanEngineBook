#include <vulkan/vulkan.h>
#include "../../../utilities/config.hpp"

namespace Graphics
{
	namespace Logger
	{
		void PrintPhysicalDeviceProperties( VkPhysicalDevice const & device) noexcept;

		void PrintPhysicalDeviceMemoryProperties( VkPhysicalDevice const & device) noexcept;

		void PrintPhysicalDeviceQueues( VkPhysicalDevice const & device) noexcept;
	
		void PrintDevicesMemoAndProperties( std::vector<VkPhysicalDevice>& devices ) noexcept;
	}
}