#include <iostream>
using std::cout;
using std::cin;


//------------------Вывод массива в консоль------------------
void PrintArray(int a, int *array) {
    cout << std::endl;
    for (int i = 0; i < a; i++)
    {
        cout << array[i] << " ";
    }
}

//------------------Установка размера массива------------------
//void SetSizeofArray(int a, int * array) {
//    array = new int[a];    
//}

//------------------Инициализация массива начальными данными------------------
void FillArrayEmpty(int a, int* array) {
    for (int i = 0; i < a; i++) {
        //cin >> array[i];
        array[i] =0;
        //cout << array[i];
    }
}
//------------------Ввод эелементов массива вручную------------------
void FillArray(int a, int* array) {
    cout << "Заполните массив:" << std::endl;
    for (int i = 0; i < a; i++) {
        cout << i << "-элемент: ";
        cin >> array[i];
        //array[i] = 0;
        //cout << array[i];
    }
}
//------------------Заполнение массива рандомными значениями------------------
void FillArrayRandom(int a, int* array) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < a; i++) {
        array[i] = rand() % 100;    
    }
}
//------------------Нахождение максимального элемента массива------------------
int FindMax(int a, int* array) {
    int max = array[0];
    for (int i = 0; i < a; i++) {
        if (max < array[i]) max = array[i];
    }
    return max;
}
//------------------Нахождение максимального индекса элемента массива------------------
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
//------------------Нахождение количество четных элементов и произведение нечетных элементов------------------
void Task6(int a, int* array, int &numberOfEven, long double &productOfOdd) {
    for (int i = 0; i < a; i++) {
        if (array[i] % 2 == 0) numberOfEven++;
        if (array[i] % 2 != 0) {
            if (productOfOdd == 0) productOfOdd = 1;
            productOfOdd *= array[i];
        }

    }
}
//------------------Заменить все кратные 5 элементы массива на 5------------------
void Replace5(int a, int* array) { 
    for (int i = 0; i < a; i++) {
        if (array[i] % 5 == 0) array[i] = 5;
    }
}


int main()
{     
    setlocale(LC_ALL, "Russian");
    std::string incorrectinp = "----------------Неверный ввод!----------------";

    int exit = -1; // переменная меню
    
    

    cout << "Введите размер массива:\n";
    cout << "a= ";
    int a = 0; // размер массива
    while (!isdigit(a) && a <= 0) // ввод пока не введен корректно
    {
        cin >> a;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << incorrectinp; 
            cout << "\nПопробуйте еще раз: ";
        }
    }
    int *array = new int[a]; 
    FillArrayEmpty(a, array);   // заполнение нулями

    int even = 0; long double odd = 0;

    while (exit != 0)
    {
        //------------------Меню------------------
        cout << std::endl;
        cout << "\n------------------------------------------------------------\n";
        cout << "\nВыберите пункт:\n";            
        cout << "1) Заполнить массив\n";
        cout << "2) Заполнить массив генератором случайных чисел\n";
        cout << "3) Вывод массива\n";
        cout << "4) Найти максимальный элемент\n";
        cout << "5) Найти индекс минимального элемента\n";
        cout << "6) Найти в массиве количество четных элементов и произведение нечетных элементов\n";
        cout << "7) Заменить все кратные 5 элементы массива на 5\n";
        cout << "0) Exit\n";


        cin >> exit;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << incorrectinp;
            exit = -1;
        }

        //------------------Обработка выбора меню------------------
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
            cout << "Максимум= " << FindMax(a, array);
            break;

        case(5):
            cout << "Минимальный индекс в массиве= " << FindMinIndex(a, array) + 1;
            break;

        case(6):          
            Task6(a, array, even, odd);
            cout << "Кол-во четных= " << even << " Произведение нечетных= " << odd;
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
