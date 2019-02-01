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

	// todo: remove those marked as delete
};
