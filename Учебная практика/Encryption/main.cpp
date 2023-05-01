#include <iostream>
#include <string>
#include <vector>

class Encryption
{
	std::vector<std::string> words;
	unsigned int* key;
	size_t Max_Len;

public:

	void in() {
		std::string message, word;
		unsigned int quantity = 0, count, beg = 0, end;
		Max_Len = 0;

		std::getline(std::cin, message);

		for (size_t i = 0; i < message.size(); i++) {
			if (message[i] == ' ') {
				end = i;
				for (size_t j = beg; j < end; j++) {
					word += message[j];
				}
				if ((int)Max_Len < word.size())
					Max_Len = word.size();

				words.push_back(word);
				quantity++;
				beg = i + 1;
				word.clear();
			}
		} 
			
		key = new unsigned int[Max_Len];
		key[0] = 0;
		key[1] = 1;
		for (size_t i = 2; i < Max_Len; i++)
			key[i] = key[i - 1] + key[i - 2];

		try {
			if ((int)quantity > 30)
				throw "The number of words should not exceed 30";
		}
		catch (const char* msg) {
			std::cerr << "The number of words should not exceed 30" << std::endl;
		}
	}

	void encrypt() {
		for (size_t i = 0; i < words.size(); i++) {
			for (size_t j = 0; j < words[i].size(); j++)
				words[i][j] = (words[i][j] + key[j]);
		}
	}

	void print()
	{
		std::cout << std::endl;
		for (size_t i = 0; i < words.size(); i++) {
			for (size_t j = 0; j < words[i].size(); j++)
			{
				std::cout << words[i][j];
			}
			std::cout << std::endl;
		}
	}

	void decrypt() {
		for (size_t i = 0; i < words.size(); i++) {
			for (size_t j = 0; j < words[i].size(); j++)
				words[i][j] = (words[i][j] - key[j]);
		}
	}
	
	~Encryption()
	{
		delete key;
	}
	
};

int main()
{
	Encryption a;
	a.in();
	a.encrypt();
	a.print();
	a.decrypt();
	a.print();
}