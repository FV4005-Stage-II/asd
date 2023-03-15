
#include <iostream>

#include "Header.h"

using namespace std;

std::string res_fanc(bool val) {
  string mes;
  if (val)
    mes = "Запрос обработан";
  else
    mes = "Ошибка запроса";
  return mes;
}

int main(void) {
  setlocale(LC_ALL, "RUS");
  int n;
  cout << "введите размер списка: ";
  cin >> n;
  MyArr<int> arr(n);

  // for (int i (0); i < 10; i++)
  // 	arr.push_back(i);
  MyArr<int>::Iterator it = arr.begin();
  MyArr<int>::rIterator r_it = arr.r_begin();
  while (1) {
    int choice(0);
    int index(0);
    int value{0};

    // MyArr<int>::Iterator it(arr.begin());
    cout << "<---------------------МЕНЮ--------------------->\n"
         << "1: опрос размера списка" << endl
         << "2: опрос кол-ва ячеек" << endl
         << "3: очистка списка" << endl
         << "4: проверка списка на пустоту" << endl
         << "5: опрос наличия заданного значения" << endl
         << "6: чтение значения с заданным номером в списке" << endl
         << "7: изменение значения с заданным номером в списке" << endl
         << "8: получение позиции в списке для заданного значения" << endl
         << "9: включение нового значения" << endl
         << "10: включение нового значения в позицию с заданным номером" << endl
         << "11: удаление элемента по значение" << endl
         << "12: удаление элемента по индексу" << endl
         << "13: вывод элементов списка" << endl
         << " <--------------Прямой итератор--------------->\n"
         << "14: итератор на начало\n"
         << "15: итератор на конец\n"
         << "16: установка на новое значение (It)" << endl
         << "17: переход к след. зн. (It)" << endl
         << "18: переход к пред. зн. (It)" << endl
         << "19: чтение значения (It)" << endl
         << "20: запись значения (It)" << endl
         << " <-------------Обратный итератор-------------->\n"
         << "21: итератор на начало\n"
         << "22: итератор на конец\n"
         << "23: установка на новое значение (r_It)" << endl
         << "24: переход к след. зн. (r_It)" << endl
         << "25: переход к пред. зн. (r_It)" << endl
         << "26: чтение значения (r_It)" << endl
         << "27: запись значения (r_It)" << endl
         << "0: Выход" << endl;

    cout << "Введите номер пункта: ";
    cin >> choice;
    try {
      switch (choice) {
        case 0:
          return 0;
          break;
        case 1:
          cout << arr.get_size() << endl;
          break;
        case 2:
          cout << arr.get_capacity() << endl;
          break;
        case 3:
          arr.clear();
          cout << "Список очищен" << endl;
          break;
        case 4:
          if (arr.empty())
            cout << "Список пустой" << endl;
          else
            cout << "Список не пустой" << endl;
          break;
        case 5:
          cout << "Введите индекс: ";
          cin >> index;
          if (arr.check_value(index))
            cout << "Заданное значение существует" << endl;
          else
            cout << "Заданного значения не существует" << endl;
          break;
        case 6:
          cout << "Введите индекс: ";
          cin >> index;
          cout << arr[index];
          break;
        case 7:
          cout << "Введите индекс: ";
          cin >> index;
          cout << "Введите значение: ";
          cin >> value;
          cout << res_fanc(arr.change_value(index, value)) << endl;
          break;
        case 8:
          cout << "Введите значение: ";
          cin >> value;
          if (arr.get_index(value) == 0)
            cout << "Не существет, такого значения" << endl;
          else
            cout << arr.get_index(value) << endl;
          break;
        case 9:
          cout << "Введите значение: ";
          cin >> value;
          arr.push_back(value);
          break;
        case 10:
          cout << "Введите индекс: ";
          cin >> index;
          cout << "Введите значение: ";
          cin >> value;
          cout << res_fanc(arr.set_value(index, value)) << endl;
          break;
        case 11:
          cout << "Введите значение: ";
          cin >> value;
          cout << res_fanc(arr.del_value(value)) << endl;
          break;
        case 12:
          cout << "Введите индекс: ";
          cin >> index;
          cout << res_fanc(arr.erase(index)) << endl;
          break;
        case 13:
          for (int i = 0; i < arr.get_size(); i++) {
            cout << arr[i] << ' ';
          }
          cout << endl;
          break;

        case 14: {
        if (arr.empty() == true) {
          cout << "массив пуст." << endl;
          break;
        }
        it = arr.begin();
        cout << "Прямой итератор установлен на начало и равен значению: " << *it
             << endl;
      } break;

        case 15: {
        if (arr.empty() == true) {
          cout << "массив пуст." << endl;
          break;
        }
        it = arr.end();
        cout << arr.get_size();
        cout << "Неустановленный прямой итератор равен значению: " << *it
             << endl;
      } break;

        case 16:
          cout << "Введите индекс: ";
          cin >> index;
          it = arr.begin() + index;
          break;
        case 17:
          it++;
          break;
        case 18:
          it--;
          break;
        case 19:
          cout << *it << endl;
          break;
        case 20:
          cin >> *it;
          break;
        case 21: {
        if (arr.empty() == true) {
          cout << "массив пуст." << endl;
          break;
        }
        r_it = arr.r_begin();
        cout << "Прямой итератор установлен на начало и равен значению: " << *r_it
             << endl;
      } break;

        case 22: {
        if (arr.empty() == true) {
          cout << "массив пуст." << endl;
          break;
        }
        r_it = arr.r_end();
        cout << arr.get_size();
        cout << "Неустановленный прямой итератор равен значению: " << *r_it
             << endl;
      } break;
        case 23:
          cout << "Введите индекс: ";
          cin >> index;
          r_it = arr.r_begin() + index;
          break;
        case 24:
          r_it++;
          break;
        case 25:
          r_it--;
          break;
        case 26:
          cout << *r_it << endl;
          break;
        case 27:
          cin >> *r_it;
          break;
      }
    } catch (const char* msg) {
      std::cout << msg << std::endl;
    }

    cout << "\nвведите для продолжения ...\n";
    getchar(), getchar();
    system("clear");
  }

  return 0;
}
