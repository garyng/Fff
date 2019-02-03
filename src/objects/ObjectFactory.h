#pragma once
#include "ObjectContainer.h"
#include "gui/GuiContainer.h"
#include "IdGenerator.h"
#include "ObjectGuiBase.h"


class ObjectFactory
{
private:
	std::shared_ptr<Hypodermic::Container> _container;
	std::shared_ptr<ObjectContainer> _objectContainer;
	std::shared_ptr<GuiContainer> _guiContainer;
	std::shared_ptr<IdGenerator> _idGenerator;
public:
	ObjectFactory(const std::shared_ptr<Hypodermic::Container>& container,
	              const std::shared_ptr<ObjectContainer>& objectContainers,
	              const std::shared_ptr<GuiContainer>& guiContainer,
	              const std::shared_ptr<IdGenerator>& idGenerator)
		: _container(container),
		  _objectContainer(objectContainers),
		  _guiContainer(guiContainer), _idGenerator(idGenerator)
	{
	}

	template <class TObject, class = IsBaseOf<TObject, IObject>>
	std::shared_ptr<IObject> Make()
	{
		// todo: now object is TObject instead of IObject, no intellisense here...
		// todo: cast this object to IObject?

		std::shared_ptr<TObject> object = _container->resolve<TObject>();
		object->Id(_idGenerator->Next());

		std::shared_ptr<ObjectGuiBase<TObject>> gui = _container->resolve<ObjectGuiBase<TObject>>();
		gui->Object(object);

		_objectContainer->Add(object);
		_guiContainer->Add(gui);

		return object;
	}
};
