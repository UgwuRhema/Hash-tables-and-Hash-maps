#include <iostream>
#include <format>
#include <map>

int main(void)
{
	std::string name = "Rhema Ugwu";
	std::cout << std::format("Hash Maps in C++, {}\n", name);
	/*let's make the map*/
	std::map<std::string, int> mymap = {
		{"Frank", 13},
		{"Rhema", 17}
	};
	int v = mymap["Rhema"];
	std::cout << std::format("The value from the name Rhema is: {}\n", v);
	/*well iterate through the entries*/
	for (auto e : mymap)
	{
		std::cout << std::format("{}-> {}\n", e.first, e.second);
	}
	return 0;
}
