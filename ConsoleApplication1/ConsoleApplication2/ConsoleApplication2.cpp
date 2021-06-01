#include <iostream>
#include <limits>
#include <string>
using std::cout;
using std::cin;


//------------------Вывод матрицы в консоль------------------
//Функция принимает ссылку на массив и его ширину и высоту
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


//void SetSizeofArray(int a, int b, int** array) {
//    for (int i = 0; i < a; i++) {
//        array[i] = new int[b];
//    }
//}

//------------------Заполнение матрицы нулями------------------
void FillArrayEmpty(int a, int b, int** array) {
    for (int i = 0; i < a; i++)
    {
        for (int i1 = 0; i1 < b; i1++) {
            array[i][i1] = 0;
        }
    }
}
//------------------Заполнение матрицы------------------
void FillArray(int a, int b, int** array) {
    cout << "Заполните матрицу:" << std::endl;
    for (int i = 0; i < a; i++)
    {
        for (int i1 = 0; i1 < b; i1++) {
            cout << i << ", " << i1 << "= ";
            cin >> array[i][i1];
        }
    }
}
//------------------Заполнение матрицы рандомом------------------
void FillArrayRandom(int a, int b, int** array) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < a; i++)
    {
        for (int i1 = 0; i1 < b; i1++) {           
            array[i][i1] = rand() % 100;
        }
    }    
}

//void PrintArrayRow(int a, int b, int** array, int row) {
//    cout << std::endl;
//    
//    for (int i1 = 0; i1 < b; i1++) {
//            cout << array[row][i1] << " ";
//    }
//}

//------------------Удваивание строки матрицы------------------
void DoubleArrayRow(int a, int b, int** array, int row) {   
    for (int i1 = 0; i1 < b; i1++) {
        array[row][i1] *= 2;
    }
}
//------------------Нахождение максимального элемента в строке------------------
int FindMaxInRow(int a, int b, int** array, int row) {
    int max = array[row][0];
    for (int i1 = 0; i1 < b; i1++) {
        if (array[row][i1] > max) max = array[row][i1];
    }
    return max;
}
//------------------Нахождение максимального индекса элемента в строке------------------
int FindMaxInRowIndex(int a, int b, int** array, int row) {
    int max = array[row][0];
    int index = 0;
    for (int i1 = 0; i1 < b; i1++) {
        if (array[row][i1] > max) {
            max = array[row][i1];
            index = i1;
        }
    }
    return index;
}

//------------------Нахождение максимального элемента в матрице------------------
int *FindMax(int a, int b, int** array) {
    int max[3] = { array[0][0],0,0 };
    for (int i = 0; i < a; i++)
    {
        for (int i1 = 0; i1 < b; i1++) {
            if (array[i][i1] > max[0]) {
                max[0] = array[i][i1];
                max[1] = i;
                max[2] = i1;
            }
        }
    }
    return max;
}
//------------------Нахождение суммы элементов в строке------------------
int SummInRow(int a, int b, int** array, int row) {
    int summ = 0;
    for (int i1 = 0; i1 < b; i1++) {
        summ += array[row][i1];
    }
    return summ;
}
//------------------Нахождение суммы элемента в столбце------------------
int SummInCol(int a, int b, int** array, int col) {
    int summ = 0;
    for (int i1 = 0; i1 < a; i1++) {
        summ += array[i1][col];
    }
    return summ;
}
//------------------Нахождение суммы главной диагонали------------------
int SummDiagon(int a, int b, int** array) {
    int summ = 0;
    int c = a < b ? a : b;
    for (int i = 0; i < c; i++) {
        summ += array[i][i];
    }  
    return summ;
}



int main()
{   
    setlocale(LC_ALL, "Russian");
    std::string incorrectinp = "----------------Неверный ввод!----------------";

    int exit = -1;

    cout << "Введите размер массива:\n";
    int a = 0; // size of array
    int b = 0; // размер массива
    while (!isdigit(a) && a <= 0 && !isdigit(b) && b <= 0) // ввод пока не введен корректно
    {
        cout << "Высота= ";
        cin >> a;
        cout << "Ширина= ";
        cin >> b;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << incorrectinp;
            cout << "\nПопробуйте еще раз: ";
        }
    }
    
    int **array = new int*[a];
    for (int i = 0; i < a; i++) {
        array[i] = new int[b];
    }
    FillArrayEmpty(a, b, array);
   
    int row = 0;
    int* max = new int[3];
    while (exit != 0)
    {
        cout << std::endl;
        cout << "\nВыберите пункт:\n";
        cout << "1) Вывод матрицы\n";
        cout << "2) Заполнить матрицу\n";
        cout << "3) Заполнить матрицу случайными числами\n";       
        cout << "4) Удвоить значение в строке матрицы\n";
        cout << "5) Найти максимум в строке матрицы\n";
        cout << "6) Найти индекс максимума в строке матрицы\n";
        cout << "7) Найти максимум в матрице\n";
        cout << "8) Сумма строки матрицы\n";
        cout << "9) Сумма столбца матрицы\n";
        cout << "10) Сумма элементов главной диагонали\n";
        cout << "0) Exit\n";

        try {

            cin >> exit;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << incorrectinp;
                exit = -1;
            }
            
            switch (exit) {
            

            case(1):
                PrintArray(a, b, array);
                break;

            case(2):
                FillArray(a, b, array);
                break;

            case(3):
                FillArrayRandom(a, b, array);
                break;           

            case(4):
                while (row <= 0 || row > b)
                {
                    cout << "Введите номер строки:";
                    cin >> row;
                }
                if (cin.fail()) {
                    cout << incorrectinp;
                }
                else
                {
                    DoubleArrayRow(a, b, array, row - 1);
                    row = 0;
                }
                
                break;

            case(5):
                while (row <= 0 || row > b)
                {
                    cout << "Введите номер строки:";
                    cin >> row;
                }
                
                if (cin.fail()) {
                    cout << incorrectinp;
                }
                else
                {
                    cout << "Максимум= " << FindMaxInRow(a, b, array, row - 1);
                    row = 0;
                }               
                break;

            case(6):
                while (row <= 0 || row > b)
                {
                    cout << "Введите номер строки:";
                    cin >> row;
                }
                if (cin.fail()) {
                    cout << incorrectinp;
                }
                else
                {
                    cout << "Индекс максимального элемента= " << row - 1 << "," << FindMaxInRowIndex(a, b, array, row - 1);
                    row = 0;
                }
                
                break;

            case(7):
                max = FindMax(a, b, array);
                cout << "Максимум= " << max[0] << " Его индекс= " << max[1] << "," << max[2];
                break;

            case(8):
                while (row <= 0 || row > b)
                {
                    cout << "Введите номер строки:";
                    cin >> row;
                }
                if (cin.fail()) {
                    cout << incorrectinp;
                }
                else
                {
                    cout << "Сумма= " << SummInRow(a, b, array, row - 1);
                    row = 0;
                }
                
                break;

            case(9):
                while (row <= 0 || row > a)
                {
                    cout << "Введите номер строки:";
                    cin >> row;
                }
                if (cin.fail()) {
                    cout << incorrectinp;
                }
                else
                {
                    cout << "Сумма= " << SummInCol(a, b, array, row - 1);
                    row = 0;
                }
                
                break;

            case(10):
                cout << "Сумма= " << SummDiagon(a, b, array);
                break;


            case(0): exit = 0;
                break;
            default: exit = -1;
                break;
            }
        }
        catch (std::exception ex) {
            cout << " Exception: " << ex.what();
        }
        

    }

    return 0;
}

