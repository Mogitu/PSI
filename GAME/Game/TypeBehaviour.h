#ifndef TypeBehaviour_H
#define TypeBehaviour_H

#include <irrlicht.h>
#include <iostream>
#include <string>


class TypeBehaviour
{
	public:
		TypeBehaviour(stringw type);
		stringw getType();
		void addWeakness(stringw weakness);
		void addStrengths(stringw strengths);
		int multiplyer(stringw bullettype);
		void initializer();
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
		FireType(stringw type);
	private:
		void initialize();
};
class IceType;
class WindType;

#endif TypeBehaviour_H