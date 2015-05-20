#include "irrlicht.h"
#include "TypeBehaviour.h"

using namespace irr;
using namespace core;

class TypeBehaviour;



class TypeBehaviour
{
public:
	TypeBehaviour(stringw type) : type_(type){}
	stringw getType()
	{
		return type_;
	}

	void addWeakness(stringw weakness)
	{
		weaknessElements.push_back(weakness);
	}

	void addStrengths(stringw strengths)
	{
		strengthsElements.push_back(strengths);
	}

	int multiplyer(stringw bullettype)
	{
		int base = 1;

		s32 weakness = weaknessElements.linear_search(bullettype);
		if (weakness >= 0)
		{
			base += 1;
		}
		s32 strength = strengthsElements.linear_search(bullettype);
		if (strength >= 0)
		{
			base -= 1;
		}


		return base;
	}

	void initializer()
	{
		initialize();
	}

protected:
	stringw type_;

private:
	array<stringw> weaknessElements;
	array<stringw> strengthsElements;
	virtual void initialize() = 0;
};

class FireType : public TypeBehaviour
{
	public:
		FireType(stringw type) : TypeBehaviour(type){};
	private:
		void initialize()
		{
			addWeakness("Ice");
			addStrengths("Wind");
		}
};
