#include "irrlicht.h"
#include "TypeBehaviour.h"

using namespace irr;
using namespace core;

class TypeBehaviour;



class TypeInterface
{
	public:
		enum ElementalType
		{
			Fire, Ice, Wind
		};
		TypeInterface()
		{
			typebehave_ = NULL;
		}
		void setType(int type);
		void setWeakness(array<stringw> weakness);
		void setStrengths(array<stringw> weakness);
		stringw getType();
		int getMultiplyer(stringw bulletType);
	private:
		TypeBehaviour *typebehave_;
};

class TypeBehaviour
{
	public:
		TypeBehaviour(stringw type) : type_(type){}
		stringw getType()
		{
			return type_;
		}

		void addWeakness(array<stringw> weakness)
		{	
			for (int a = 0; a < weakness.size(); a++)
			{
				weaknessElements.push_back(weakness[a]);
			}
		}

		void addStrengths(array<stringw> strengths)
		{
			for (int a = 0; a < strengths.size(); a++)
			{
				strengthsElements.push_back(strengths[a]);
			}
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
		
	protected:
		stringw type_;

	private:
		array<stringw> weaknessElements;
		array<stringw> strengthsElements;
		
};