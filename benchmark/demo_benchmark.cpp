#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <vector>
#include "data_structure.hpp"

using namespace std;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
static constexpr auto kProjectPath = string_view{PROJECT_SOURCE_DIR};

namespace itis {

  int main() {

    // работа с набором данных
    const auto path = string(kDatasetPath);
    cout << "Path to the 'dataset/' folder: " << path << endl;

    auto input_file = ifstream(path);

    string line;

    int num = 0;
    for (int i = 1; i < 8; ++i) {
      switch (i) {
        case 1:
          num = 100;
          break;
        case 2:
          num = 1000;
          break;
        case 3:
          num = 5000;
          break;
        case 4:
          num = 10000;
          break;
        case 5:
          num = 50000;
          break;
        case 6:
          num = 100000;
          break;
        case 7:
          num = 500000;
          break;
      }

      input_file = ifstream(path + "\\dataset" + to_string(num) + ".csv");
      cout << "dataset: " + to_string(i) << endl;

      // Парсинг строки
      int* my_array = new int[num];
      int index = 0;
      while (getline(input_file, line, ';')) {
        my_array[index] = stoi(line);
        index++;
      }

      for (int j = 1; j < 11; ++j) {

        const auto time_point_before = chrono::steady_clock::now();
        itis::quickSort(my_array,0,num);
        const auto time_point_after = chrono::steady_clock::now();

        // переводим время в наносекунды
        const auto time_diff = time_point_after - time_point_before;
        const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

        // время в милисекундах
        cout << to_string(j) + ") Time (ms): " << time_elapsed_ns / 1000000 << '\n';
      }
      delete[] my_array;
    }
    return 0;
  }
}
