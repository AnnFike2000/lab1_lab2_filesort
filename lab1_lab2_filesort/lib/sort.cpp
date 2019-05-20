#include "sort.h"

/****RECURSIVE****/

void internal_qsort_recursive(
	String::iterator left_idx,
	String::iterator right_idx) {

	if(std::distance(left_idx, right_idx) < 1) return;

	auto
		start_idx = left_idx,
		end_idx = right_idx,
		base_idx = left_idx + std::distance(left_idx, right_idx) / 2;

	while(left_idx < right_idx) {
		while(*left_idx < *base_idx && left_idx < base_idx) left_idx++;
		while(*right_idx >= *base_idx && right_idx > base_idx) right_idx--;

		if(left_idx < right_idx) std::iter_swap(left_idx, right_idx);
		if(left_idx == base_idx) base_idx = right_idx;
		else if(right_idx == base_idx) base_idx = left_idx;
	}
	
	if(base_idx > start_idx)
		internal_qsort_recursive(start_idx, base_idx);
	if(base_idx < end_idx)
		internal_qsort_recursive(base_idx + 1, end_idx);
}

void qsort_recursive(String & raw) {
	internal_qsort_recursive(raw.begin(), raw.end() - 1);
}

#define TEST_PATH "C:\\Documents\\programming\\cpp.txt"

void sort_file(char * path_to_file)
{
  String unsorted;
  std::ifstream f;
  f.open(path_to_file, std::ios::in);//точный адрес хранения необходимого файла
  if (f)
  {
  while(!f.eof())
    f>>unsorted;
  }
  else
  { 
    std::cout <<"Error!\n";
  }
  f.close();
  qsort_recursive(unsorted);
  //return unsorted;
  std::ofstream n;
  n.open(path_to_file, std::ios::out);;//удаляем данные о предыдущем файле
  if (!(n.is_open()))
  {
    std::cout << "File not find\n";
  }
  else
  {
    n<<unsorted;//перезаписываем файл
    n.close();
  }
}
    
