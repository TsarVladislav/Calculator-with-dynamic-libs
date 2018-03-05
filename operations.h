/*!
	\file operations.h
	\brief Заголовочный файл для списка функций-операций.

	Имена функций читаются отсюда
	\author Vladislav Tsisyk
	\version 1.0
	\date Июль 2017

*/

#include <stdio.h>
/*!
 *  \brief указатель на функцию, которая принимает два параметра типа int
 *	\param[int] операнд
 *  \param[int] операнд
 *  \return результат операции
 *
 * */
typedef int (*twoi_t)(int, int);
/*!
 *  \brief указатель на функцию, которая принимает один параметр типа int
 *  \param[int] операнд
 *  \return результат операции
 * */

typedef int (*onei_t)(
    int);
	   /*!
	    *  \brief  операция сложения двух числен
	    *  \param[int] операнд
	    *  \param[int] операнд
	    *  \return результат операции
	    * */

int sum(int, int);
		    /*!
		     *  \brief  операция сложения двух целочисленных чисел
		     *  \param[int] операнд
		     *  \param[int] операнд
		     *  \return результат операции
		     * */

int mul(int, int);
		    /*!
		     *  \brief  операция умножения двух целочисленных чисел
		     *  \param[int] операнд
		     *  \param[int] операнд
		     *  \return результат операции
		     * */

int sub(int, int);
		    /*!
		     *  \brief  операция вычитания двух целочисленных чисел
		     *  \param[int] операнд
		     *  \param[int] операнд
		     *  \return результат операции
		     * */

int mdiv(int, int); 
		     /*!
		      *  \brief  операция деление двух целочисленных чисел
		      *  \param[int] операнд
		      *  \param[int] операнд
		      *  \return результат операции
		      * */

int factorial(int);

/*!
 *  \brief Факториал
 *  \param[int] операнд
 *  \return результат операции
 * */
