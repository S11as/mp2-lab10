file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h

add_library(${lib} STATIC ${srcs} ${hdrs} TList.cpp TList.h TListElem.cpp TListElem.h TListIterator.cpp TListIterator.h TMonom.cpp TMonom.h TPolinomial.cpp TPolinomial.h) #Создаем статическую библиотеку с именем из переменной ${MyLib1}, объявленной в родительском CMake файле (локальные переменные переносятся в наследников), в неё добавляются файлы из переменных ${srcs} и ${hdrs}
