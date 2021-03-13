#include <iostream>
#include <string>

void quick_sort(std::string& arr, const size_t left, const size_t right);
char custom_tolower(char ch);

int main_quick_sort(void)
{
  try
  {
    std::cout << "The program is designed to sort the sequence of letters of the Latin alphabet."
      " Enter the sequence of latin fonts to sort:" << std::endl;

    std::string sequence{};
    bool success_input = false;

    while (!success_input)
    {
      success_input = true;
      std::cin >> sequence;

      // проверка, что в последовательности только символы
      for (size_t i = 0; i < sequence.length(); i++)
        if (custom_tolower(sequence[i]) < 'a' ||
          custom_tolower(sequence[i]) > 'z')
        {
          std::cout << "The sequence contains non-latin letters."
            " Re-enter a sequence of latin letters:" << std::endl;
          success_input = false;
          break;
        }
    }

    std::cout << "Source sequence for sorting: " << sequence << std::endl;

    quick_sort(sequence, 0, sequence.length()-1);

    std::cout << "Sorted sequence: " << sequence << std::endl;
  }
  catch (const std::exception& Exc)
  {
    std::cout << Exc.what() << std::endl;
    std::cout << "EXIT_WITH_EXCEPTION" << std::endl;
    return EXIT_SUCCESS;
  }

  return EXIT_SUCCESS;
}


// нужен потому что std::tolower принимает параметр типа int8
char custom_tolower(char ch)
{
  return static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
}

void quick_sort(std::string& arr, const size_t left, const size_t right)
{
  size_t i = left, j = right;
  char temp, pivot = arr[(left + right) / 2];

  while (i <= j)
  {
    while (custom_tolower(arr[i]) < custom_tolower(pivot))
      i++;
    while (custom_tolower(arr[j]) > custom_tolower(pivot))
      j--;

    if (i <= j)
    {
      if (custom_tolower(arr[i]) > custom_tolower(arr[j]))
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
      i++; j--;
    }

  };

  if (left < j)
    quick_sort(arr, left, j);
  if (i < right)
    quick_sort(arr, i, right);
}