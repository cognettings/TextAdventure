#pragma once
#include "LimitedUseItem.hpp"
#include "EquipItem.hpp"

class LimitedUseEquipItem :
	public LimitedUseItem,
	public EquipItem
{
public:
	LimitedUseEquipItem(void);
	virtual ~LimitedUseEquipItem(void);
};

