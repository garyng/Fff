#pragma once
#include "objects/ObjectFactory.h"
#include "logger/ILogger.h"
#include "objects/ObjectContainer.h"

class MutatorFactory
{
private:
	std::shared_ptr<ObjectFactory> _objectFactory;
	std::shared_ptr<ObjectContainer> _objectContainer;
	std::shared_ptr<Hypodermic::Container> _container;
	std::shared_ptr<ILogger> _logger;
public:


	MutatorFactory(const std::shared_ptr<ObjectFactory>& objectFactory,
		const std::shared_ptr<ObjectContainer>& objectContainer,
		const std::shared_ptr<Hypodermic::Container>& container,
		const std::shared_ptr<ILogger>& _logger)
		:
		_objectFactory(objectFactory),
		_objectContainer(objectContainer), _container(container), _logger(_logger)
	{
	}

	template <class TMutator, class TObject, class = IsBaseOf<TMutator, IMutator>, class = IsBaseOf<TObject, IObject>>
	void Attach()
	{
		std::shared_ptr<IObject> object = std::static_pointer_cast<IObject>(_objectContainer->First<TObject>());
		if (object == nullptr)
		{
			// todo: create a new object or do nothing?
			object = _objectFactory->Make<TObject>();
		}
		std::shared_ptr<IMutator> mutator = _container->resolve<TMutator>();
		object->Attach(mutator);
		mutator->Target(object); // todo: circular reference...
		_logger->Debug("Attached %1% to %2% [#%3%]",
			{ nameof(*mutator), nameof(*object), std::to_string(object->Id()) });
	}

	// todo: attachall
};
