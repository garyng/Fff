#pragma once
#include "IObject.h"
#include "ContainerBase.h"
namespace bmi = boost::multi_index;

class ObjectContainer : public ContainerBase<IObject>
{

};
