#pragma once

template <class T>
class ContainerBase
{
protected:
	std::vector<std::shared_ptr<T>> _items{};
	std::shared_ptr<ILogger> _logger;

	virtual bool Predicate(std::shared_ptr<T> item)
	{
		return false;
	}

	// called when the item is to be purged
	virtual void OnPurge(std::shared_ptr<T> item)
	{
	}

public:
	virtual ~ContainerBase() = default;


	ContainerBase(const std::shared_ptr<ILogger>& logger)
		: _logger(logger)
	{
	}

	void Add(const std::shared_ptr<T>& item)
	{
		_items.push_back(item);
	}

	std::vector<std::shared_ptr<T>>& All()
	{
		return _items;
	}

	template <class TObject>
	std::shared_ptr<T> FirstOf()
	{
		return _items | first_or_default([&](std::shared_ptr<T> item)
		{
			return typeid(*item) == typeid(TObject);
		});
	}

	template <class TBase>
	std::vector<std::shared_ptr<TBase>> AllOfBase()
	{
		return _items | select([&](std::shared_ptr<T> item)
		{
			return std::dynamic_pointer_cast<TBase>(item);
		}) | where([&](std::shared_ptr<T> item)
		{
			return item != nullptr;
		}) | to_vector();
	}

	// remove all objects from the container that satisfy certain criteria
	void Purge()
	{
		_items.erase(
			std::remove_if(_items.begin(), _items.end(), [&](std::shared_ptr<T> item)
			{
				const bool result = Predicate(item);
				if (result)
				{
					OnPurge(item);
				}
				return result;
			}), _items.end()
		);
	}

	void Clear()
	{
		_items.clear();
	}

	// find by type
	// find by id
	// find by canDelete
};
