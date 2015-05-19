#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

template <class T>
class ObjectPool{	
private:
	struct Object{
		bool available;
		T data;
		Object *next;
	};
public:	
	ObjectPool(int size);
	~ObjectPool();		
	T *create();	
	Object *getObjects();
	int getSize();
	void returnToPool(Object *obj);	
private:	
	Object *firstAvailable;
	Object *objects;
	int size;
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
	objects = new Object[size];
	firstAvailable = &objects[0];
	for (int i = 0; i < size; i++)
	{
		objects[i].available = true;
		objects[i].next = &objects[i + 1];
	}	
	objects[size - 1].next = NULL;
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