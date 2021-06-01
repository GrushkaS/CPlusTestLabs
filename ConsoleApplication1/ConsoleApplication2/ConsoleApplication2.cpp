#include <iostream>
#include <limits>
#include <string>
using std::cout;
using std::cin;


//------------------����� ������� � �������------------------
//������� ��������� ������ �� ������ � ��� ������ � ������
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

//------------------���������� ������� ������------------------
void FillArrayEmpty(int a, int b, int** array) {
    for (int i = 0; i < a; i++)
    {
        for (int i1 = 0; i1 < b; i1++) {
            array[i][i1] = 0;
        }
    }
}
//------------------���������� �������------------------
void FillArray(int a, int b, int** array) {
    cout << "��������� �������:" << std::endl;
    for (int i = 0; i < a; i++)
    {
        for (int i1 = 0; i1 < b; i1++) {
            cout << i << ", " << i1 << "= ";
            cin >> array[i][i1];
        }
    }
}
//------------------���������� ������� ��������------------------
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

//------------------���������� ������ �������------------------
void DoubleArrayRow(int a, int b, int** array, int row) {   
    for (int i1 = 0; i1 < b; i1++) {
        array[row][i1] *= 2;
    }
}
//------------------���������� ������������� �������� � ������------------------
int FindMaxInRow(int a, int b, int** array, int row) {
    int max = array[row][0];
    for (int i1 = 0; i1 < b; i1++) {
        if (array[row][i1] > max) max = array[row][i1];
    }
    return max;
}
//------------------���������� ������������� ������� �������� � ������------------------
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

//------------------���������� ������������� �������� � �������------------------
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
//------------------���������� ����� ��������� � ������------------------
int SummInRow(int a, int b, int** array, int row) {
    int summ = 0;
    for (int i1 = 0; i1 < b; i1++) {
        summ += array[row][i1];
    }
    return summ;
}
//------------------���������� ����� �������� � �������------------------
int SummInCol(int a, int b, int** array, int col) {
    int summ = 0;
    for (int i1 = 0; i1 < a; i1++) {
        summ += array[i1][col];
    }
    return summ;
}
//------------------���������� ����� ������� ���������------------------
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
    std::string incorrectinp = "----------------�������� ����!----------------";

    int exit = -1;

    cout << "������� ������ �������:\n";
    int a = 0; // size of array
    int b = 0; // ������ �������
    while (!isdigit(a) && a <= 0 && !isdigit(b) && b <= 0) // ���� ���� �� ������ ���������
    {
        cout << "������= ";
        cin >> a;
        cout << "������= ";
        cin >> b;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << incorrectinp;
            cout << "\n���������� ��� ���: ";
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
        cout << "\n�������� �����:\n";
        cout << "1) ����� �������\n";
        cout << "2) ��������� �������\n";
        cout << "3) ��������� ������� ���������� �������\n";       
        cout << "4) ������� �������� � ������ �������\n";
        cout << "5) ����� �������� � ������ �������\n";
        cout << "6) ����� ������ ��������� � ������ �������\n";
        cout << "7) ����� �������� � �������\n";
        cout << "8) ����� ������ �������\n";
        cout << "9) ����� ������� �������\n";
        cout << "10) ����� ��������� ������� ���������\n";
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
                    cout << "������� ����� ������:";
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
                    cout << "������� ����� ������:";
                    cin >> row;
                }
                
                if (cin.fail()) {
                    cout << incorrectinp;
                }
                else
                {
                    cout << "��������= " << FindMaxInRow(a, b, array, row - 1);
                    row = 0;
                }               
                break;

            case(6):
                while (row <= 0 || row > b)
                {
                    cout << "������� ����� ������:";
                    cin >> row;
                }
                if (cin.fail()) {
                    cout << incorrectinp;
                }
                else
                {
                    cout << "������ ������������� ��������= " << row - 1 << "," << FindMaxInRowIndex(a, b, array, row - 1);
                    row = 0;
                }
                
                break;

            case(7):
                max = FindMax(a, b, array);
                cout << "��������= " << max[0] << " ��� ������= " << max[1] << "," << max[2];
                break;

            case(8):
                while (row <= 0 || row > b)
                {
                    cout << "������� ����� ������:";
                    cin >> row;
                }
                if (cin.fail()) {
                    cout << incorrectinp;
                }
                else
                {
                    cout << "�����= " << SummInRow(a, b, array, row - 1);
                    row = 0;
                }
                
                break;

            case(9):
                while (row <= 0 || row > a)
                {
                    cout << "������� ����� ������:";
                    cin >> row;
                }
                if (cin.fail()) {
                    cout << incorrectinp;
                }
                else
                {
                    cout << "�����= " << SummInCol(a, b, array, row - 1);
                    row = 0;
                }
                
                break;

            case(10):
                cout << "�����= " << SummDiagon(a, b, array);
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

