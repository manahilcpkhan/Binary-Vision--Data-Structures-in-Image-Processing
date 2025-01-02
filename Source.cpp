#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "Image.cpp"
using namespace std;

int main()
{

	int check=2;
	string file;

	/////////////USE THIS FOR DEFAULT RUN/////////////////
	/*Image<int> S;
	S.read("apple-18.pgm");*/
	
	////S.save();
	////S.Print();
	
	//////////////////////////////////////////////////////
	cout << "enter the pgm file name you want to read:" << endl;
	cin >> file;
	Image<int> S;
	S.read(file);
	while (check != 0) {
		cout << endl << "Q1: press 1 to run solution of Q1\n" << "Q2: press 2 to run the solution of Q2\n" << "Q3: press 3 to run the solution of Q3\n" << "Q4: press 4 to run the solution of Q4\n" << "Q5: press 5 to run the solution of Q5\n" << "Q6: press 6 to run the solution of Q6\n" << "EXIT: press 0 to exit program\n" << endl;
		cin >> check;

		if (check == 1)
		{
			int x = S.mean();
			cout << "mean: " << x << endl;
			S.on_off();
			float y = 0;
			y = S.average_black();

			cout << endl << "average blacks in the pic: " << y << endl << endl;

			S.ConvertToNegative();
		}
		if (check == 2) {

			S.queue_cce(100, 100);
			cout << endl;
		}
		if (check == 3) {

			S.stack_cce(100, 100);
			cout << endl;
		}
		if (check == 4) {
			S.RLC();
			S.saveRLC();
			S.readRLC();
			S.blackRLC();
			S.ConvertToNegativeRLC();
		}

		if (check == 6) {


			string f;
			string a;
			string b;
			string c;
			string e;
			string d;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					for (int k = 0; k < 10; k++)
					{
						f = "image";
						a = to_string(i);
						b = to_string(j);
						c = to_string(k);
						e = ".pgm";
						//d = a + b + c;
						d = f + a + b + c + e;
						if (d != "image000.pgm") {

							cout << d << endl;
							S.read(d);
							S.hashTable();
						}
					}
				}
			}
			f = "image";
			a = to_string(5);
			b = to_string(0);
			c = to_string(0);
			e = ".pgm";
			d = f + a + b + c + e;
			cout << d << endl;
			S.read(d);
			S.hashTable();


			S.displayHashTable();
		}
		if (check == 5) {
			//S.quadTree();


		}
	}
	return 0;
}