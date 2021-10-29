#include <iostream>
#include <string>
#include <vector>

void obzac()
{
	std::cout << "\n\n//============================================================================//\n\n";
};

//task1
template <typename T>
class Pair1
{
private:
	T m_first;
	T m_second;
public:
	Pair1(const T& first, const T& second) : m_first(first), m_second(second) { }

	const T& first() const;
	const T& second() const;
};

template <typename T>
const T& Pair1<T>::first() const
{
	return m_first;
}

template <typename T>
const T& Pair1<T>::second() const
{
	return m_second;
}

//task2
template <typename T1, typename T2>
class Pair
{
private:
	T1 m_first;
	T2 m_second;
public:
	Pair(const T1& first, const T2& second) : m_first(first), m_second(second) { }

	const T1& first() const;
	const T2& second() const;
};

template <typename T1, typename T2>
const T1& Pair<T1, T2>::first() const
{
	return m_first;
}

template <typename T1, typename T2>
const T2& Pair<T1, T2>::second() const
{
	return m_second;
}

//task3
template <typename T2>
class StringValuePair : public Pair<std::string, T2>
{
public:
	StringValuePair(const std::string& first, const T2& second) :
		Pair<std::string, T2>(first, second) {}
};


int main()
{
	{
		obzac();
		//task1
		Pair1<int> p1(6, 9);
		std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

		const Pair1<double> p2(3.4, 7.8);
		std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
		obzac();		
	};
	{
		obzac();
		//task2
		Pair<int, double> p1(6, 7.8);
		std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

		const Pair<double, int> p2(3.4, 5);
		std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
		obzac();
	};
	{
		obzac();
		//task3
		StringValuePair<int> svp("Amazing", 7);
		std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
		obzac();	
	};
};