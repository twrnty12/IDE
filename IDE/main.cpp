#include <iostream>
#include <fstream>


int main()
{
	int count1;
	int count2;
	int num;


	std::ifstream fin("in.txt");

	if (fin.is_open()) {


		fin >> count1;
		const int size1 = count1;

		int* arr1 = new int[size1];

		for (int i = 0; i < size1; ++i) {
			fin >> num;
			arr1[i] = num;
		}

		fin >> count2;
		const int size2 = count2;

		int* arr2 = new int[size2];
		for (int i = 0; i < size2; ++i) {
			fin >> num;
			arr2[i] = num;
		}

		int* arr1_new = new int[size1];

		arr1_new[size1 - 1] = arr1[0];
		for (int i = 0; i < (size1 - 1); ++i) {
			arr1_new[i] = arr1[i + 1];
		}


		int* arr2_new = new int[size2];

		arr2_new[0] = arr2[size2 - 1];
		for (int i = 1; i < size2; ++i) {
			arr2_new[i] = arr2[i - 1];
		}

		std::ofstream fout;
		fout.open("out.txt");

		fout << size2 << '\n';

		for (int i = 0; i < size2; ++i) {
			fout << arr2_new[i] << " ";
		} fout << '\n';

		fout << size1 << '\n';

		for (int i = 0; i < size1; ++i) {
			fout << arr1_new[i] << " ";
		} fout << '\n';

		fin.close();
		fout.close();

		delete[] arr1;
		delete[] arr2;
		delete[] arr1_new;
		delete[] arr2_new;

	}
	else {

		std::cout << "File isn`t open!!!" << '\n';
	}


	return 0;
}