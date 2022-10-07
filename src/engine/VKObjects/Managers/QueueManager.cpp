#include "QueueManager.hpp"

namespace Graphics::Manager
{

	bool
	QueueManager::checkQueuesSuitability( VkPhysicalDevice& p_device, VkSurfaceKHR& p_surface ) noexcept
	{
		std::vector<VkQueueFamilyProperties> queueProp {};
		getPhysicalDeviceQueueProperties( p_device , queueProp );

		_queueIndexInfo.pickBestPhysicalDeviceQueues(queueProp, p_surface, p_device);

		return _queueIndexInfo.isComplete();
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void
	QueueManager::initQueueCreateInfo() noexcept
	{
		std::set<uint32_t> queueIndex {};
		_queueIndexInfo.getSetIndex(queueIndex);

		_queueInfo.resize( queueIndex.size() );

		int i = 0;
		for(auto queueID : queueIndex)
		{
			_queueInfo[i].sType = {VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO};
			_queueInfo[i].pNext = {nullptr};
			_queueInfo[i].queueCount = {1};
			_queueInfo[i].flags = {0};
			_queueInfo[i].pQueuePriorities = &_queueIndexInfo._priorityValue;
			_queueInfo[i].queueFamilyIndex = queueID;
			++i;
		}
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void
	QueueManager::getGraphicHandler( VkDevice& p_device, VkQueue& p_queueHandler) const noexcept
	{
		vkGetDeviceQueue( p_device, _queueIndexInfo._graphicsFamilyQueueIndex.value(), 0, &p_queueHandler);
	}

	//-------------------------------------------------------------------------
	//-------------------------------------------------------------------------

	void
	QueueManager::getPresentHandler( VkDevice& p_device, VkQueue& p_queueHandler) const noexcept
	{
		vkGetDeviceQueue( p_device, _queueIndexInfo._presentFamilyQueueIndex.value(), 0, &p_queueHandler);
	}

}