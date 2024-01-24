#include <cstring>
#include <iostream>
#pragma warning(disable : 4996)

class Str
{
private:
	char* line;
	int size;
public:
	Str() : line{ nullptr }, size{ 0 }{}
	Str(const char* line_)
	{
		size = strlen(line_);
		line = new char[size + 1];
		strncpy(line, line_, size);
		line[size] = '\0';
	}
	~Str()
	{
		delete[] line;
	}
// pop back
	void pop_back()
	{
		if (size > 0)
		{
			char* linedel = new char[size];
			strncpy(linedel, line, size - 1);
			linedel[size - 1] = '\0';
			delete[] line;
			line = linedel;
			linedel = nullptr;
			size = size - 1;
		}
	}
	friend std::ostream& operator << (std::ostream& out, const Str& line_) // cout operator
	{
		out << line_.line;
		return out;
	}
	// operator +=
	Str& operator+=(const Str& add)
	{
		int sizeadd = size + add.size;
		char* lineadd = new char[sizeadd + 1];
		strncpy(lineadd, line, size);
		strncpy(lineadd + size, add.line, add.size);

		lineadd[sizeadd] = '\0';
		size = sizeadd;
		delete[] line;
		line = lineadd;
		lineadd = nullptr;
		return *this;

	}

};

int main()
{
	Str text1("Hi!");
	Str text2(" how are you?");
	text1.pop_back();
	std::cout << text1;
	std::cout << std::endl;
	text1 += text2;
	std::cout << text1;
}