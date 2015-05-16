#ifndef OBJECTPOOL_H
#define OBJECTPOOL_H

template <class T>
class ObjectPool{
public:	
	ObjectPool();
	~ObjectPool();	
	T *create();
	T pool[3];
	bool inUse[3];
private:		
	
	
};

template <typename T>
ObjectPool<T>::ObjectPool(){	
		for (int i = 0; i < 3; i++)
		{
			inUse[i] = false;
		}
}

template <typename T>
ObjectPool<T>::~ObjectPool(){

}
template<typename T>
T *ObjectPool<T>::create(){
	//Find an available particle.	
	for (int i = 0; i < 3; i++)
	{
		if (!inUse[i])
		{
			inUse[i] = true;
			return &pool[i];
		}
	}
	return NULL;
	
}
#endif