#pragma once
template <typename T>
class Singleton
{
private:
	static T* s_instance;
public:
	Singleton() {}
	virtual ~Singleton() { delete s_instance; s_instance = nullptr; }
	static T* GetInstance()
	{
		if (!s_instance)
			s_instance = new T();
		return s_instance;
	}
};

template<typename T>
T* Singleton<T>::s_instance = nullptr;