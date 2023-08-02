# CMakeList.txt: проект CMake для badlang-vm; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("badlang-vm")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (badlang-vm   "stack/stack-cell.h" "stack/vm-stack.c" "stack/vm-stack.h" "bytecode/tokens.h" "bytecode/bc.c" "bytecode/bc.h" "badlang-vm.c")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
