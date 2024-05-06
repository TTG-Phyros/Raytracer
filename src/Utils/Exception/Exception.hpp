/**
 * @file Exception.hpp
 * @author COUSTABEAU Maxime (maxime.coustabeau@epitech.eu)
 *         GIRARD Anthony (anthony1.girard@epitech.eu)
 *         MERY Baptiste (baptiste.mery@epitech.eu)
 *         AUDIBERT Nicolas (nicolas.audibert@epitech.eu)
 * @brief EPITECH PROJECT, 2024
 * @version 0.1
 * @date 2024-05-03
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef EXCEPTION
#define EXCEPTION

#include <iostream>

/**
 * @class Exception
 * @brief Custom exception class for handling errors.
 * @details This class inherits from std::exception and provides a custom error message.
 */
class Exception : public std::exception
{
    public:
        Exception(const std::string &errorMsg) noexcept;
        ~Exception();

        virtual const char* what() const noexcept;

    private:
        std::string _error; ///< The error message associated with the exception.
};

#endif // !EXCEPTION
