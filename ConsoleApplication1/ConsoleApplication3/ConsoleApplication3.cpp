#include <iostream>
#include <Windows.h>

using namespace std;

//------------------Заполнение массива рандомными значениями------------------
void FillArrayRandom(int a, int* array) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < a; i++) {
        array[i] = rand() % 100;
    }
}

//------------------Вывод массива в консоль------------------
void PrintArray(int a, int* array) {
    cout << std::endl;
    for (int i = 0; i < a; i++)
    {
        cout << array[i] << " ";
    }
}

void FillArrayRandom(int a, int b, int** array) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < a; i++)
    {
        for (int i1 = 0; i1 < b; i1++) {
            array[i][i1] = rand() % 100;
        }
    }
}

void PrintArray(int a, int b, int** array) {
    cout << std::endl;
    for (int i = 0; i < a; i++)
    {
        cout << std::endl;
        for (int i1 = 0; i1 < b; i1++) {
            cout << array[i][i1] << " ";
        }
    }
}

void Task1() {
    cout << "\nЗадание 1\n";
    int n = 0, k = 0, l = 0;
    while (k >= l || l >= n || n <= 1) // ввод пока не введен корректно
    {
        cout << "N= ";
        cin >> n;
        cout << "K= ";
        cin >> k;
        cout << "L= ";
        cin >> l;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10, '\n');          
            cout << "\nПопробуйте еще раз: ";
        }
    }
    int* array = new int[n];
    FillArrayRandom(n, array);
    cout << "Массив:\n";
    PrintArray(n, array);
    int summ = 0;
    for (int i = k; i <= l; i++) {
        summ += array[i];
    }
    cout << "\nСумма от" << k <<" до "<< l <<" = " << summ;
}

void Task2() {
    cout << "\nЗадание 2\n";
    int n = 0;
    while (n <= 0) // ввод пока не введен корректно
    {
        cout << "N= ";
        cin >> n;      
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "\nПопробуйте еще раз: ";
        }
    }
    int* array = new int[n];
    FillArrayRandom(n, array);
    cout << "Массив:\n";
    PrintArray(n, array);

    cout << endl;
    for (int i = 1; i < n-1; i++) {
        if (array[i] > array[i-1] && array[i] > array[i+1]) {
            cout << array[i] << "; ";
        }
    }
}

void Task3() {
    cout << "\nЗадание 3\n";
    int n = 0, m = 0;
    while (n <= 0 || m <= 0) // ввод пока не введен корректно
    {
        cout << "N= ";
        cin >> n;
        cout << "M= ";
        cin >> m;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "\nПопробуйте еще раз: ";
        }
    }
    int** array = new int* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }
    FillArrayRandom(n,m, array);
    PrintArray(n, m, array);

    cout << std::endl;
    for (int i = 0; i < n; i++) {
        cout << std::endl;
        for (int i1 = 0; i1 < m; i1++) {
            if (i % 2 == 0) {
                cout << array[i][i1] << " ";
            }
            else
            {
                cout << array[i][m-i1 - 1] << " ";
            }
        }
    }
}

void DeleteColumn(int a, int b, int** array, int col);

void Task4() {
    cout << "\nЗадание 4\n";
    int n = 0, m = 0;
    while (n <= 0 || m <= 0) // ввод пока не введен корректно
    {
        cout << "N= ";
        cin >> n;
        cout << "M= ";
        cin >> m;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10, '\n');
            cout << "\nПопробуйте еще раз: ";
        }
    }
    int** array = new int* [n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }
    FillArrayRandom(n, m, array);
    PrintArray(n, m, array);
    int row = 0;
    while (row <= 0 || row > m)
    {
        cout << "\nВведите номер столбца:\n";
        cin >> row;
    }
    DeleteColumn(n,m,array,row-1);
    PrintArray(n,m-1,array);
}

void DeleteColumn(int a, int b, int** array, int col) {
    for (int i1 = col; i1 < b; i1++) {
        for (int i = 0; i < a; i++) {
            array[i][i1] = array[i][i1 + 1];
        }
    }
}

void Task5() {
    string s = "";
    string s0 = "";
    string c = "";
    cout << "Введите строку s= ";
    cin >> s;
    cout << "Введите строку s0= ";
    cin >> s0;
    cout << "Если введете строку, будет использоваться только первый символ!\n";
    cout << "Введите символ c= ";
    cin >> c;
    
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c[0]) {
            s.insert(i+1, s0);
        }
    }
    cout << s;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Task1();
    Task2();
    //Task3();
    //Task4();
    //Task5();
}