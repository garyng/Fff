#pragma once

template <class T>
class ContainerBase
{
protected:
	std::vector<std::shared_ptr<T>> _items{};
public:
	void Add(const std::shared_ptr<T>& item)
	{
		_items.push_back(item);
	}

	std::vector<std::shared_ptr<T>>& All()
	{
		return _items;
	}

	template <class TObject>
	std::shared_ptr<T> First()
	{
		return _items | first_or_default([&](std::shared_ptr<T> item)
		{
			return typeid(*item) == typeid(TObject);
		});
	}

	// find by type
	// find by id
	// find by canDelete

	// todo: remove those marked as delete
};
