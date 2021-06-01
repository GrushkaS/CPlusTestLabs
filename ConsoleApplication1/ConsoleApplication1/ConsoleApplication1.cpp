#include <iostream>
using std::cout;
using std::cin;


//------------------����� ������� � �������------------------
void PrintArray(int a, int *array) {
    cout << std::endl;
    for (int i = 0; i < a; i++)
    {
        cout << array[i] << " ";
    }
}

//------------------��������� ������� �������------------------
//void SetSizeofArray(int a, int * array) {
//    array = new int[a];    
//}

//------------------������������� ������� ���������� �������------------------
void FillArrayEmpty(int a, int* array) {
    for (int i = 0; i < a; i++) {
        //cin >> array[i];
        array[i] =0;
        //cout << array[i];
    }
}
//------------------���� ���������� ������� �������------------------
void FillArray(int a, int* array) {
    cout << "��������� ������:" << std::endl;
    for (int i = 0; i < a; i++) {
        cout << i << "-�������: ";
        cin >> array[i];
        //array[i] = 0;
        //cout << array[i];
    }
}
//------------------���������� ������� ���������� ����������------------------
void FillArrayRandom(int a, int* array) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < a; i++) {
        array[i] = rand() % 100;    
    }
}
//------------------���������� ������������� �������� �������------------------
int FindMax(int a, int* array) {
    int max = array[0];
    for (int i = 0; i < a; i++) {
        if (max < array[i]) max = array[i];
    }
    return max;
}
//------------------���������� ������������� ������� �������� �������------------------
int FindMinIndex(int a, int* array) {
    int max = array[0];
    int minIndex = 0;
    for (int i = 0; i < a; i++) {
        if (max > array[i]) {
            max = array[i];
            minIndex = i;
        }
    }
    return minIndex;
}
//------------------���������� ���������� ������ ��������� � ������������ �������� ���������------------------
void Task6(int a, int* array, int &numberOfEven, long double &productOfOdd) {
    for (int i = 0; i < a; i++) {
        if (array[i] % 2 == 0) numberOfEven++;
        if (array[i] % 2 != 0) {
            if (productOfOdd == 0) productOfOdd = 1;
            productOfOdd *= array[i];
        }

    }
}
//------------------�������� ��� ������� 5 �������� ������� �� 5------------------
void Replace5(int a, int* array) { 
    for (int i = 0; i < a; i++) {
        if (array[i] % 5 == 0) array[i] = 5;
    }
}


int main()
{     
    setlocale(LC_ALL, "Russian");
    std::string incorrectinp = "----------------�������� ����!----------------";

    int exit = -1; // ���������� ����
    
    

    cout << "������� ������ �������:\n";
    cout << "a= ";
    int a = 0; // ������ �������
    while (!isdigit(a) && a <= 0) // ���� ���� �� ������ ���������
    {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << incorrectinp; 
            cout << "\n���������� ��� ���: ";
        }
    }
    int *array = new int[a]; 
    FillArrayEmpty(a, array);   // ���������� ������

    int even = 0; long double odd = 0;

    while (exit != 0)
    {
        //------------------����------------------
        cout << std::endl;
        cout << "\n------------------------------------------------------------\n";
        cout << "\n�������� �����:\n";            
        cout << "1) ��������� ������\n";
        cout << "2) ��������� ������ ����������� ��������� �����\n";
        cout << "3) ����� �������\n";
        cout << "4) ����� ������������ �������\n";
        cout << "5) ����� ������ ������������ ��������\n";
        cout << "6) ����� � ������� ���������� ������ ��������� � ������������ �������� ���������\n";
        cout << "7) �������� ��� ������� 5 �������� ������� �� 5\n";
        cout << "0) Exit\n";


        cin >> exit;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << incorrectinp;
            exit = -1;
        }

        //------------------��������� ������ ����------------------
        even = 0; odd = 0;
        switch (exit) {
              
        case(1):
            FillArray(a, array);
            break;

        case(2):
            FillArrayRandom(a, array);
            break;

        case(3): 
            PrintArray(a, array);
            break;

        case(4):
            cout << "��������= " << FindMax(a, array);
            break;

        case(5):
            cout << "����������� ������ � �������= " << FindMinIndex(a, array) + 1;
            break;

        case(6):          
            Task6(a, array, even, odd);
            cout << "���-�� ������= " << even << " ������������ ��������= " << odd;
            break;

        case(7):
            Replace5(a, array);           
            break;

        case(0): exit = 0;
            break;
        default: exit = -1; 
            break;
        }

    }

    return 0;
}
