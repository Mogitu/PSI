#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H


/*
*Author: Maikel van Munsteren
*Desc: Easy to use object pool that can be used for pooling objects of any type.
*      Features fast (de-)allocation in O(1) by using a free list.
*/

template <class T>
class ObjectPool{
private:
	//nested class to keep track of each objects status in a decoupled way.
	struct Object{
		bool available;
		T data;
		Object *next;
	};
	Object *firstAvailable;
	Object *objects;
	int size;
public:
	ObjectPool(int size);
	~ObjectPool();
	T *create();
	Object *getObjects();
	int getSize();
	void returnToPool(Object *obj);
};

template <typename T>
typename ObjectPool<T>::Object *ObjectPool<T>::getObjects()
{
	return objects;
}

template <typename T>
int ObjectPool<T>::getSize()
{
	return size;
}


template <typename T>
ObjectPool<T>::ObjectPool(int s){
	size = s;
	//create an array of objects.
	objects = new Object[size];
	//first object created is immediatly available.
	firstAvailable = &objects[0];
	//make all objects available by default and give them a reference to the next object.
	for (int i = 0; i < size; i++)
	{
		objects[i].available = true;
		objects[i].next = &objects[i + 1];
	}
	//the last object in the list has no next, list will terminate here.
	objects[size - 1].next = NULL;
}

template <typename T>
ObjectPool<T>::~ObjectPool(){
	delete objects;
	delete firstAvailable;
}
template<typename T>
T *ObjectPool<T>::create(){
	//get a pointer to the first object of T from the Object.
	T *obj = &firstAvailable->data;
	//if succesfull it is no longer available 
	if (obj && firstAvailable->available)
	{
		firstAvailable->available = false;
		//change the next firstavailable object of T
		if (firstAvailable->next)
		{
			firstAvailable = firstAvailable->next;
		}
		return obj;
	}
	//if creation fails.
	return NULL;
}

template<typename T>
void ObjectPool<T>::returnToPool(Object *obj)
{
	//object is available again and we set the references to the next and firstavailable objects again.
	obj->available = true;
	obj->next = firstAvailable;
	firstAvailable = obj;
}
#endif