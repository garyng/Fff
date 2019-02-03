#pragma once
#include "IGui.h"
#include "logger/ILogger.h"
#include "objects/IObject.h"
#include "objects/ObjectFactory.h"


class ObjectsDebugGui : public IGui
{
private:
	std::vector<Hypodermic::TypeAliasKey> _objectTypes;
	std::shared_ptr<ILogger> _logger;
	std::shared_ptr<ObjectFactory> _objectFactory;

public:

	ObjectsDebugGui(const std::shared_ptr<ObjectFactory>& objectFactory,
	              const std::shared_ptr<ILogger>& _logger) : _logger(_logger), _objectFactory(objectFactory)
	{
	}


	void Render() override;

	template <class TObject, class = IsBaseOf<TObject, IObject>>
	void RenderButton()
	{
		std::string name = boost::core::demangle(typeid(TObject).name());
		if (ImGui::Button(("Spawn new " + name).c_str()))
		{
			_objectFactory->Make<TObject>();
			_logger->Debug("Spawned new %1%", {name});
		}
	}
};
