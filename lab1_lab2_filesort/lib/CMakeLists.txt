set(source_libs sort.cpp)
set(source_headers sort.h)

add_library(sort STATIC ${source_libs} ${source_headers})
	# Создает библиотеку с именем sort