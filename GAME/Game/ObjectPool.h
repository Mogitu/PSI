#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

template <class T>
class ObjectPool{
public:	
	ObjectPool();
	~ObjectPool();
	T *create();
	
private:		
	T pool[100];
	bool inUse[100];
};

template <typename T>
ObjectPool<T>::ObjectPool(){
	
}

template <typename T>
ObjectPool<T>::~ObjectPool(){

}
template<typename T>
T *ObjectPool<T>::create(){
	return &pool[0];
	/*
	// Find an available particle.	
	for (int i = 0; i < 100; i++)
	{
		if (!inUse[i])
		{
			return &pool[i];
		}
	}
	*/
}
#endif