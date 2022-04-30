#include <iostream>
#include<fstream>
#include <cstdlib>
#include<vector>
#include<algorithm>
#include <bitset>
#include <string>
using namespace std;
int main() {
	ifstream indata;
	ofstream outData;
	string data;
	string d;
	indata.open("data.txt");
	vector<string> v;
	vector<string> vectornotSorted;
	while (!indata.eof()) {
		indata >> data;
		v.push_back(data);

	}
	indata.close();
	vectornotSorted = v;
	std::sort(v.begin(), v.end());
	outData.open("OutData.txt");
	for (int i = 0;i < v.size();i++)
	{
		outData << v[i]+"\n";
	}
	outData.close();
	outData.open("BinaryOutData.txt");
	for (int i = 0;i < v.size();i++)
	{
		for (int j = 0;j < v[i].size();j++)
		{
			outData << bitset<8>(v[i].c_str()[j]);
			outData << "\n";
		}
	
	}
	outData.close();
	outData.open("indecs.txt");
	char a[50];
	for (int i = 0;i < v.size();i++)
	{
		for (int j = 0;j < vectornotSorted.size();j++)
		{
			if (strcmp(v[i].c_str(), vectornotSorted[j].c_str()) ==0)
			{
				outData << "new index is ::  " + to_string(i) + "  old index is : " + to_string(j) + "  the line is " + v[i].c_str() + "\n";
				break;
			}
		}
	}
	outData.close();
	
	system("pause");
}


