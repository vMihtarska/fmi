#pragma once
template <typename T>
class Vector
{
private:
	T*arr;
	size_t size;
	size_t capacity;
public:
	Vector() :arr(nullptr), size(0), capacity(0) {};
	Vector(size_t size)
	{
		this->size = size;
		this->capacity = size;
		arr = new T[size];
	}
	Vector(const Vector& o)
	{
		this->size = o.getSize();
		this->capacity = o.capacity;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = o.getAt(i);
	}
	
	T getAt(size_t index) const
	{
		return this->arr[index];
	}
	void setAt(size_t index,T value)
	{
		this->arr[index]=value;
	}
	void add(T value)
	{
		if (this->capacity <= this->size)
		{
			this->capacity == 0 ? this->capacity = 2 : this->capacity *= 2;
			if (this->size == 0)
			{
				arr = new T[this->capacity];
				arr[this->size++] = value;
			}
			else
			{
				T* temp = new T[this->capacity];
				for (int i = 0; i < size; i++)
					temp[i] = this->arr[i];
				temp[this->size++] = value;
				delete[] this->arr;
				arr = temp;
			}
		}
		else
		{
			this->arr[this->size++] = value;
		}
		
	}
	bool isEmpty() const
	{
		return size == 0;
	}
	size_t getSize() const
	{
		return this->size;
	}
	void clear()
	{
		delete[] arr;
		arr = nullptr;
	}
	~Vector()
	{
		clear();
	}
};

