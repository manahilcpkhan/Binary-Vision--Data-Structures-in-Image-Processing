#include "Image.h"
template <class T>
Image<T>::Image() {
	on = 0;
	off = 0;
	pixel = 0;
	row = 0;
	col = 0;
	arr = nullptr;
	name = "";
	//h(401);
	//rlc = nullptr;
	logout.open("log.txt"); //this is to not overwrite in file -->>  ios::out | std::ios_base::app);
	logout<< "main execute " << "\n";
	logout << "Image Constructor " << "\n";
}
template <class T>
Image<T>::Image(string filename) {
	//file = filename;
	on = 0;
	off = 0;
	pixel = 0;
	row =0;
	col =0;
	arr = nullptr;
	name = filename;
	//rlc = nullptr;
	logout.open("log.txt", ios::out);
	logout << "main execute " << "\n";
	logout << "Image class Constructor " << "\n";
	read(filename);
}
template <class T>
Image<T>::~Image() {
	logout << "Image Destructor\n";
	logout << "main Destructor" << endl;
}

template <class T>
void Image<T>::read(string filename) {
	logout << "Image class read(" <<filename<< ")" << "\n";
	name = filename;
	ifstream fin(filename);
	int size = 0;
	
	string num = "";
	fin >> num;
	//cout << num;
	if (num == "P5") {
		for (int i = 1; i < 8; i++)
		{
			fin >> num;
			if (i == 5) {
				row = stoi(num);
			}
			if (i == 6) {
				col = stoi(num);
			}
			if (i == 7) {
				pixel = stoi(num);
			}
		}
		char n;
		this->arr = new T * [row];
		for (int i = 0; i < row; i++)
		{
			arr[i] = new T[col];
			for (int j = 0; j < col; j++)
			{

				fin >> n;

				if (n == NULL || int(n) == 48) {
					arr[i][j] = 0;
					off += 1;
				}
				else {
					arr[i][j] = 1;
					size++;
					on += 1;
				}
			}
		}
	}
	if(num=="P2") {
		for (int i = 1; i <7 ; i++)
		{
			fin >> num;
			if (i == 4) {
				//cout << num;
				row = stoi(num);
			}
			if (i == 5) {
				//cout << num;
				col = stoi(num);
			}
			if (i == 6) {
				//cout << num;
				pixel = stoi(num);
			}
		}
		char n;
		this->arr = new T * [row];
		for (int i = 0; i < row; i++)
		{
			arr[i] = new T[col];
			for (int j = 0; j < col; j++)
			{

				fin >> n;

				if (n == NULL || int(n)==48) {
					arr[i][j] = 0;
					off += 1;
				}
				else {
					arr[i][j] = 1;
					size++;
					on += 1;
				}
			}
		}
		/*cout << endl;
		for (int i = 1; i < row; i++)
		{
			for (int j = 1; j < col; j++)
			{
				cout<< arr[i][j] << " ";
			}
		}*/
	}
	else {
		cout << "system only for P2 and P5 files" << endl;
	}
}

template<class T>
void Image<T>::Print()
{
	logout << "Image class Print() " << "\n";
	for (int i = 0; i < row; ++i) {
	  for (int y = 0; y < col; ++y) 
	  {
		  cout << this->arr[i][y];
	  }
		cout << endl;
			}
}


template <class T>
void  Image<T>::save() {
	logout << "Image class save() " << "\n";
	fstream fout;
	fout.open("Input.pgm");
	fout<< "P5\n";
	fout <<"#" << "Input.pgm" <<"\n";
	fout << "#converted pgm file\n";
	fout << row<< ' '<< col << "\n";
	fout << pixel << '\n';

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			fout << arr[x][y];
		}
		fout<<endl;
		
	}
	fout.close();
	cout << "done. Go check Input.pgm"<<endl;
}
template <class T>
T  Image<T>::getPixel(int r, int c) {
	logout << "Image class getPixel() " << "\n";
	if (r >= row || c >= col) {
		cout << "invaldi location" << endl;
		return -1;
	};

	return arr[r][c];
}
template <class T>
void  Image<T>::setPixel(int r, int c, T p) {
	logout << "Image class setPixel("<<r<<","<<c<<","<<pixel<<") " << "\n";
	if (r >= row || c >= col) {
		cout << "invaldi location" << endl;
	}
	else
		this->arr[r][c] = p;
	
}
template <class T>
int  Image<T>::getSize() {
	logout << "Image class getSize() " << "\n";
	int size = 0;
	size = row * col;
	return size;
}
template <class T>
void Image<T>::ConvertToNegative() {
	logout << "Image class ConvertToNegative() " << "\n";

	int i = 0;
	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			if (arr[x][y] == 0) {
				arr[x][y] = 1;
			}
			else {
				arr[x][y] = 0;
			}
		}

	}
	save();
}
template <class T>
int Image<T>::mean() {
	logout << "Image class mean() " << "\n";
	int mean=0;
	for (int i = 0; i < row ; i++) {
		for (int j = 0; j < col; j++)
		{
		 if (arr[i][j]>0)
			mean += pixel;
		}
		
	}
	mean = mean / getSize();
	return mean;
}
template <class T>
void Image<T>::on_off() {
	logout << "Image class on_off() " << "\n";
	cout << endl<< "number of on:" << endl;
	cout << on<<endl;
	cout << "number of off:" << endl;
	cout << off << endl;
	cout << endl;
}
template <class T>
float Image<T>::average_black() {
	logout << "Image class average_black() " << "\n";
	float blacck=0;
	float avgblack=0.0 ;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
		{
			if (this->arr[i][j] == 0) {
				blacck++;
			}
		}
	}

	 avgblack = (blacck/row)/col;

	return avgblack;
}
template <class T>
void Image<T>:: queue_cce(int r, int c) {
	logout << "Image class queue_cce(" << r << "," << c << ") " << "\n";
	queue<int> temp1;
	queue<int> temp2;
	T **array = new T * [row];
	for (int i = 0; i < row; i++)
	{
		array[i] = new T[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array[i][j] = 1;
		}
	}

 array[r][c] = 0;
	temp1.enqueue(r);
	temp2.enqueue(c);
	long int ss=0;
	while (temp1.isEmpty() == false ) 
	{
		ss++;
		r = temp1.dequeue();
		c = temp2.dequeue();
		if ((arr[r][c] == arr[r - 1][c]) && (r - 1 > 0) && (array[r-1][c] == 1)) {
			array[r - 1][c] = 0;
			temp1.enqueue(r - 1);
			temp2.enqueue(c);

		}
		if ((arr[r][c] == arr[r + 1][c]) && (r + 1 < row - 1) && (array[r+1][c] == 1)) {
			array[r + 1][c] = 0;
			temp1.enqueue(r + 1);
			temp2.enqueue(c);

		}
		if ((arr[r][c] == arr[r][c - 1]) && (c - 1 > 0) && (array[r][c - 1] == 1)) {
			array[r][c - 1] = 0;
			temp1.enqueue(r);
			temp2.enqueue(c - 1);

		}
		if ((arr[r][c] == arr[r][c + 1]) && (c + 1 < col - 1)&&(array[r][c + 1] ==1)) {
			array[r][c+1] = 0;
			temp1.enqueue(r);
			temp2.enqueue(c + 1);

		}
		if ((arr[r][c] == arr[r - 1][c + 1]) && (r - 1 > 0) && (c + 1 < col - 1) && (array[r-1][c + 1] == 1)) {
			array[r - 1][c + 1] = 0;
			temp1.enqueue(r - 1);
			temp2.enqueue(c + 1);

		}
		if ((arr[r][c] == arr[r - 1][c - 1]) && (r - 1 > 0) && (c - 1 > 0) && (array[r-1][c - 1] == 1)) {
			array[r - 1][c-1] = 0;
			temp1.enqueue(r - 1);
			temp2.enqueue(c-1);

		}
		if ((arr[r][c] == arr[r + 1][c + 1]) && (r + 1 < row - 1) && (c + 1 < col - 1) && (array[r+1][c + 1] == 1)) {
			array[r + 1][c + 1] = 0;
			temp1.enqueue(r+1);
			temp2.enqueue(c + 1);

		}
		if ((arr[r][c] == arr[r + 1][c - 1]) && (r + 1 < row - 1) && (c - 1 > 0) && (array[r+1][c - 1] == 1)) {
			array[r + 1][c-1] = 0;
			temp1.enqueue(r + 1);
			temp2.enqueue(c-1);

		}

		
	}
	cout << ss;
	fstream fout;
	fout.open("queueImage.pgm");
	fout << "P5\n";
	fout << "#" << "queueImage.pgm" << "\n";
	fout << "#converted pgm file\n";
	fout << row << ' ' << col << "\n";
	fout << pixel << '\n';

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			fout << array[x][y];
		}
		fout << endl;

	}
	fout.close();
	cout <<endl<< "done. Go check queueImage.pgm"<<endl;
}
template <class T>
void Image<T>::stack_cce(int r, int c) {
	logout << "Image class stack_cce(" << r << "," << c << ") " << "\n";
	stackArray<int> temp1(row*col);
	stackArray<int> temp2(row * col);
	T** array = new T * [row];
	for (int i = 0; i < row; i++)
	{
		array[i] = new T[col];
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			array[i][j] = 1;
		}
	}

	array[r][c] = 0;
	temp1.push(r);
	temp2.push(c);
	long int ss = 0;
	while (temp1.isEmpty() == false)
	{
		ss++;
		r = temp1.pop();
		c = temp2.pop();
		if ((arr[r][c] == arr[r - 1][c]) && (r - 1 > 0) && (array[r - 1][c] == 1)) {
			array[r - 1][c] = 0;
			temp1.push(r - 1);
			temp2.push(c);

		}
		if ((arr[r][c] == arr[r + 1][c]) && (r + 1 < row - 1) && (array[r + 1][c] == 1)) {
			array[r + 1][c] = 0;
			temp1.push(r + 1);
			temp2.push(c);

		}
		if ((arr[r][c] == arr[r][c - 1]) && (c - 1 > 0) && (array[r][c - 1] == 1)) {
			array[r][c - 1] = 0;
			temp1.push(r);
			temp2.push(c - 1);

		}
		if ((arr[r][c] == arr[r][c + 1]) && (c + 1 < col - 1) && (array[r][c + 1] == 1)) {
			array[r][c + 1] = 0;
			temp1.push(r);
			temp2.push(c + 1);

		}
		if ((arr[r][c] == arr[r - 1][c + 1]) && (r - 1 > 0) && (c + 1 < col - 1) && (array[r - 1][c + 1] == 1)) {
			array[r - 1][c + 1] = 0;
			temp1.push(r - 1);
			temp2.push(c + 1);

		}
		if ((arr[r][c] == arr[r - 1][c - 1]) && (r - 1 > 0) && (c - 1 > 0) && (array[r - 1][c - 1] == 1)) {
			array[r - 1][c - 1] = 0;
			temp1.push(r - 1);
			temp2.push(c - 1);

		}
		if ((arr[r][c] == arr[r + 1][c + 1]) && (r + 1 < row - 1) && (c + 1 < col - 1) && (array[r + 1][c + 1] == 1)) {
			array[r + 1][c + 1] = 0;
			temp1.push(r + 1);
			temp2.push(c + 1);

		}
		if ((arr[r][c] == arr[r + 1][c - 1]) && (r + 1 < row - 1) && (c - 1 > 0) && (array[r + 1][c - 1] == 1)) {
			array[r + 1][c - 1] = 0;
			temp1.push(r + 1);
			temp2.push(c - 1);

		}


	}
	cout << ss;
	fstream fout;
	fout.open("stackimage.pgm");
	fout << "P5\n";
	fout << "#" << "stackimage.pgm" << "\n";
	fout << "#binary pgm file\n";
	fout << row << ' ' << col << "\n";
	fout << pixel << '\n';

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
			fout << array[x][y];
		}
		fout << endl;

	}
	fout.close();
	cout <<endl<< "done. Go check stackImage.pgm" << endl;
}


template <class T>
void Image<T>:: RLC() {
	//List<int> rlc;
	logout << "Image class RLC() " << "\n";
	rlc.add(row);
	rlc.add(col);

	for (int x = 0; x < row; x++) {
		for (int y = 0; y < col; y++) {
		
			if (arr[x][y] == 0 && arr[x][y - 1] != 0 && arr[x][y + 1] == 0) {
				rlc.add(y+1);

			}
			else if (arr[x][y] == 0 && arr[x][y +1] != 0 && arr[x][y - 1] == 0) {
				rlc.add(y+1);

			}
			else if (arr[x][y] == 0 && arr[x][y - 1] != 0 && arr[x][y + 1] != 0) {
				rlc.add(y+1);
				rlc.add(y+1);
			}
			
		}
		rlc.add(-1);
	}
	rlc.displayRLCList();
}
template <class T>
void  Image<T>::saveRLC() {
	logout << "Image class saveRLC() " << "\n";
	fstream fout;
	fout.open("RLC.rlc");

	Node<T>* iterator = rlc.getHead();
	//int i = 0 ;
	fout << iterator->getData()<<" ";
	iterator = iterator->getNext();
	//fout << " -> ";
	fout <<iterator->getData();
	iterator = iterator->getNext();
	fout << endl;
	while (iterator != nullptr) {
		//System.out.printf("|%d:%d|",++i,iterator.getData());
		if (iterator->getData() == -1) {
			fout <<iterator->getData();
			iterator = iterator->getNext();
			fout << endl;
		}
		else {
			fout<< iterator->getData();
			iterator = iterator->getNext();
			if (iterator != nullptr || iterator->getData() != -1)
				fout << " ";
		}
	}
	fout <<endl;
	fout.close();
	cout << "done. Go check RLC.rlc" << endl << endl;
}
template <class T>
void  Image<T> ::readRLC() {
	logout << "Image class readRLC( )" << "\n";
	ifstream fin("RLC.rlc");
	int size = 0;
	List<int> New;
	string num = "";
	int a = 0;
	for (int i = 0; i < 3; i++)
	{
		fin >> num;
		//cout << num;

		a = stoi(num);
		New.add(a);
	}
	string n;

	while (!fin.eof()) {

		fin >> n;
		//cout << n;

		a = stoi(n);
		New.add(a);

	}

	//cout << endl << endl;
	//New.displayList();
	int rr = 0;
	int cc = 0;
	Node<T>* iterator = New.getHead();
	rr = iterator->getData();
	iterator = iterator->getNext();
	cc = iterator->getData();
	iterator = iterator->getNext();
	
	T** array = new T * [rr];
	for (int i = 0; i < rr; i++)
	{
		array[i] = new T[cc];
	}

	for (int i = 0; i < rr; i++)
	{
		for (int j = 0; j < cc; j++)
		{
			array[i][j] = 1;
		}
	}

	//while (iterator != nullptr) {
		for (int j = 0; j < rr; j++) {
			if (iterator != nullptr) {
				while (iterator->getData() != -1) {
					int start = iterator->getData();
					iterator = iterator->getNext();
					int stop = iterator->getData();
					
					for (int i = start - 1; i <= stop - 1; i++) {
						array[j][i] = 0;
					}
					iterator = iterator->getNext();
				}
				iterator = iterator->getNext();
			}
		}
	//}

	/*for (int i = 0; i < rr; i++)
	{
		for (int j = 0; j < cc; j++)
		{
			cout<<array[i][j];
		}
		cout << endl;
	}*/
		fstream fout;
		fout.open("RLCImage.pgm");
		fout << "P5\n";
		fout << "#" << "RLCImage.pgm" << "\n";
		fout << "#converted rlc to pgm file\n";
		fout << rr << ' ' << cc << "\n";
		fout << pixel << '\n';

		for (int x = 0; x < rr; x++){
			for (int y = 0; y < cc; y++) {
				fout << array[x][y];
			}
			fout << endl;

		}
		fout.close();
		cout << endl << "done. Go check RLCImage.pgm" << endl<<endl;
}
template <class T>
int Image<T> ::blackRLC() {
	logout << "Image class blackRLC( )" << "\n";
	Node<T>* iterator = rlc.getHead();
	int black = 0;
	int rr = iterator->getData();
	iterator = iterator->getNext();
	int cc = iterator->getData();
	iterator = iterator->getNext();
	
	for (int j = 0; j < rr; j++) {
		if (iterator != nullptr) {
			while (iterator->getData() != -1) {
				int start = iterator->getData();
				iterator = iterator->getNext();
				int stop = iterator->getData();

				for (int i = start - 1; i <= stop - 1; i++) {
					black++;
				}
				iterator = iterator->getNext();
			}
			iterator = iterator->getNext();
		}
	}
	cout << "No. of black pixel using rlc link list: " << black << endl << endl;
	return black;
}

template <class T>
void  Image<T> ::ConvertToNegativeRLC() {
	logout << "Image class ConvertToNegativeRLC( )" << "\n";
	int rr = 0;
	int cc = 0;
	Node<T>* iterator = rlc.getHead();
	rr = iterator->getData();
	iterator = iterator->getNext();
	cc = iterator->getData();
	iterator = iterator->getNext();

	T** array = new T * [rr];
	for (int i = 0; i < rr; i++)
	{
		array[i] = new T[cc];
	}

	for (int i = 0; i < rr; i++)
	{
		for (int j = 0; j < cc; j++)
		{
			array[i][j] = 0;
		}
	}

	//while (iterator != nullptr) {
	for (int j = 0; j < rr; j++) {
		if (iterator != nullptr) {
			while (iterator->getData() != -1) {
				int start = iterator->getData();
				iterator = iterator->getNext();
				int stop = iterator->getData();

				for (int i = start - 1; i <= stop - 1; i++) {
					array[j][i] = 1;
				}
				iterator = iterator->getNext();
			}
			iterator = iterator->getNext();
		}
	}

	fstream fout;
	fout.open("NegativeRLCImage.pgm");
	fout << "P5\n";
	fout << "#" << "NegativeRLCImage.pgm" << "\n";
	fout << "#converted rlc to pgm file\n";
	fout << rr << ' ' << cc << "\n";
	fout << pixel << '\n';

	for (int x = 0; x < rr; x++) {
		for (int y = 0; y < cc; y++) {
			fout << array[x][y];
		}
		fout << endl;

	}
	fout.close();
	cout << endl << "done. Go check NegativeRLCImage.pgm" << endl << endl;
}

template <class T>
void  Image<T> ::hashTable() {
	logout << "Image class hashTable()" <<"for "<<name<< "\n";
	//string name = "apple-18.pgm";
	int Rsum = 0;
	int Csum = 0;
	int* array1 = new int[row];
	int* array2 = new int[col];
	int size = row + col;
	int* array = new int[size];
	

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0)
				Rsum++;
		}
	
		array1[i] = Rsum;
		array[i] = Rsum;
		Rsum = 0;
	
	}

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (arr[j][i] == 0)
				Csum++;
		}
		array2[i] = Csum;
		array[i + (row)] = Csum;
		Csum = 0;
	
	}

	string a;
	string str;
	for (int i = 0; i < size; i++) {
		a = to_string(array[i]);
		str = str + a;
	}

			int oldsize = str.size();
	
			if (oldsize % 4 == 1) {
				a = to_string(0);
				str = str + a;
				str = str + a;
				str = str + a;
			}
			else if (oldsize % 4 == 2) {
				a = to_string(0);
				str = str + a;
				str = str + a;	
			}
			else if (oldsize % 4 == 3) {
				a = to_string(0);
				str = str + a;
			}

			int Newsize = str.size();
			int Sum=0;
			int num = 0;
			int k = 0;
			for (int i = 0; i <Newsize; i+=4)
			{
				for (int j = 0; j < 4; j++) {
					string cht= " ";
					int n=0;
					cht = str[j + i];
					n= stoi(cht);
					n=  n* pow(10, (3 - j));
					num = num + n;	
				}
				
				Sum+= num;
				num = 0;
				k++;
			}
			//cout << Sum<<endl;
			h.add(Sum, name);
} 
template <class T>
void  Image<T> :: displayHashTable() {
	logout << "Image class displayHashTable()"<< "\n";
	cout << endl << "Hash table:" << endl;
	h.print();
}
template <class T>
void  Image<T> ::quadTree() {
	logout << "Image class quadTree() " << "\n";
	TreeNode<int>* root= new TreeNode<int>;
	root->setInfo(2);
	int size = row * col;
	int r1 = row;
	int c1 = col;
	bool w=false;
	bool b = false;
	bool g = false;

	int** n = new int*();
	n = new int * [r1];
	for (int i = 0; i < r1; i++)
	{
		n[i] = new T[c1];
		for (int j = 0; j < c1; j++)
		{
			n[i][j] = arr[i][j];
			
		}
	}
	int s1 = 0;
	int r = 0;
	
	int r1 = r1 / 2;
	int c1 = c1 / 2;
	int x = 4, y = r1, z = c1;
	
	int* a = new int[x * y * z];
	long long int l = 0, m = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {

				*(a + i * y * z + j * z + k) = n[l][m];
				l++;
				m++;
			}
		}
	}
	for (int k = 0; k < 4; k++) {
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c1; j++)
			{
				if (*(a + k * y * z + i * z + j) == 0) {
					w = true;
				}
				else if (*(a + k * y * z + i * z + j) == 1) {
					b = true;
				}
			}
				if (b == true && w == true) {
					g = true;
					b = false;
					w = false;
					break;
				}
		}
		if (g == true) {
			//a[]
			root->insert(root, 2);
		}
		else if (b == true) {
			root->insert(root, 1);
		}
		else {
			root->insert(root, 0);
		}
	}
	if (row != 0 || row != 1) {
		row = row / 2;
		col = col / 2;
		quadTree();
	}
}