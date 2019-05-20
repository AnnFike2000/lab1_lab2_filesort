set(exec_file main.cpp)
set(exec_headers main.h)
add_executable(main ${exec_file} ${exec_headers})
	# Создает исполняемый файл с именем main
target_link_libraries(main sort gtest)
	# Собирает из исходника main.cpp