/*!
	\file calculator.h
	\brief Заголовочный файл калькулятора
	\author Vladislav Tsisyk
	\version 1.0
	\date Июль 2017

*/

#include <dirent.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"
 /*! 
  * захардкоженый путь до динамических библиотек.make создастпапку.
  */
#define LPATH "lib/"
/*!
 * \brief Максимальная длина пути
 *
 */
#define STRLEN 256 

/*!
 *  \brief Тип для хранения информации о загруженной динамической библиотеке
 * */
typedef struct {


	/*!
	 * \brief Имя функции
	 */
	char name[STRLEN];

	/*!
	 * \brief Путь до файла, в котором лежит функция
	 * */
	char path[STRLEN];
	/*!
	 *"handle" for the dynamic library. man dlopen
	 * */
	void *handle;

	/*!
	 *адрес функции в памяти. man dlsym
	 */
	void *f;
} operations_t;

/*!
 * считывает число из командной строки
 *
 * \return считанное целочисленное число
 * */
int getNumber();
/*!
 * функция вытаскивания функции из динамической библиотеки
 *
 * \param[in] path Имя библиотеки(dynamic shared object). man dlopen
 * \param[in] name Имя функции. man dlsym
 * \param[in] op указатель на массив. Этот массив хранит список функций из
 * динамических билиотек.
 * \return сколько всего функций в массиве после выполнения этой функции.
 * */

int openf(char *path, char *name, operations_t **op);

/*!
 * Удаляет подстроку из строки
 *
 * \param[out] s строка
 * \param[in] toremove строка, которую нужно удалить из строки s
 * */

void rmsbstr(char *s, const char *toremove);
