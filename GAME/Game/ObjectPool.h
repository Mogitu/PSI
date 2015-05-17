#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

#include <vector>

template <class T>
class ObjectPool{	
public:	
	ObjectPool();
	~ObjectPool();	
	struct Object{
		bool available;
		T data;
		Object *next;
	};
	T *create();
	Object pool[3];	
	Object *firstAvailable;
	void returnToPool(Object *obj);
private:			

	
};




template <typename T>
ObjectPool<T>::ObjectPool(){	
	firstAvailable = &pool[0];
	for (int i = 0; i < 3; i++)
	{
		pool[i].available = true;
		pool[i].next = &pool[i + 1];
	}	
	pool[3 - 1].next = NULL;
}

template <typename T>
ObjectPool<T>::~ObjectPool(){

}
template<typename T>
T *ObjectPool<T>::create(){
	T *obj = &firstAvailable->data;
	if (obj && firstAvailable->available)
	{
		firstAvailable->available = false;
		if (firstAvailable->next)
		{
			firstAvailable = firstAvailable->next;
		}		
		return obj;
	}
	return NULL;	
}

template<typename T>
void ObjectPool<T>::returnToPool(Object *obj)
{
	obj->available = true;
	obj->next = firstAvailable;
	firstAvailable = obj;
}
#endif