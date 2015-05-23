#include "TypeBehaviour.h"

	ElementalType TypeBehaviour::getType()
	{
		return type_;
	}

	void TypeBehaviour::addWeakness(ElementalType weakness, int value)
	{
		weaknessElements.insert(weakness, value);
	}

	void TypeBehaviour::addStrengths(ElementalType strengths, int value)
	{
		strengthsElements.insert(strengths, value);
	}

	int TypeBehaviour::multiplyer(ElementalType bullettype)
	{
		int base = 1;

		map<ElementalType, int>::Node* weakness = weaknessElements.find(bullettype);
		if (weakness)
		{
			base += weakness->getValue();
		}
		map<ElementalType, int>::Node* strengths = strengthsElements.find(bullettype);
		if (strengths)
		{
			base -= strengths->getValue();
		}


		return base;
	}

	void TypeBehaviour::initializer()
	{
		initialize();
	}